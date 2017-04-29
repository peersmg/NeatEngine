#include "stdafx.h"
#include "InputManager.h"
#include "Game.h"
#include "OutputLog.h"

InputManager::InputManager()
{
  ClearKeyStates();

  m_maxClickTime = 0.5f;
}


InputManager::~InputManager()
{
}

void InputManager::Update()
{
  
}

void InputManager::SampleKeyboard()
{
  // Clear events
  //ClearKeyStates();

  sf::Event currentEvent;
  m_textEntered = "";
  m_mouseWheelDelta = 0;

  if (m_clickTime > 0)
  {
    m_clickTime -= 0.016;
  }

  for (auto const &element : m_keyState)
  {
    if (element.second == ButtonState::PRESSED)
    {
      m_keyState[element.first] = ButtonState::DOWN;
    }
  }

  for (auto const &element : m_mouseState)
  {
    if (element.second == ButtonState::PRESSED)
    {
      m_mouseState[element.first] = ButtonState::DOWN;
    }
  }

  if (m_mouseState[m_clickButton] == ButtonState::CLICKED)
  {
    m_mouseState[m_clickButton] = ButtonState::RELEASED;
  }

  // Set key events
  while (Game::instance.GetWindow()->GetRenderWindow()->pollEvent(currentEvent))
  {
    m_events.push_back(currentEvent);

    if (currentEvent.type == sf::Event::KeyPressed)
    {
      m_keyState[currentEvent.key.code] = ButtonState::PRESSED;
    }
    else if (currentEvent.type == sf::Event::KeyReleased)
    {
      m_keyState[currentEvent.key.code] = ButtonState::RELEASED;
    }
    else if (currentEvent.type == sf::Event::MouseButtonPressed)
    {
      m_mouseState[currentEvent.mouseButton.button] = ButtonState::PRESSED;
      m_clickButton = currentEvent.mouseButton.button;
      m_clickTime = m_maxClickTime;
    }
    else if (currentEvent.type == sf::Event::MouseButtonReleased)
    {
      m_mouseState[currentEvent.mouseButton.button] = ButtonState::RELEASED;

      if (currentEvent.mouseButton.button == m_clickButton && m_clickTime > 0)
      {
        m_mouseState[currentEvent.mouseButton.button] = ButtonState::CLICKED;
        m_clickTime = 0;
      }
    }
    else if (currentEvent.type == sf::Event::Closed)
    {
      Game::instance.SetState(GameState::Exiting);
    }

    if (currentEvent.type == sf::Event::MouseWheelMoved)
    {
      m_mouseWheelDelta = currentEvent.mouseWheel.delta;
    }

    if (currentEvent.type == sf::Event::TextEntered && currentEvent.text.unicode != 8 && currentEvent.text.unicode != 13 && currentEvent.text.unicode != 27)
    {
      if (currentEvent.text.unicode < 128)
      {
        m_textEntered = m_textEntered + static_cast<char>(currentEvent.text.unicode);
      }
    }
  }

#ifndef NDEBUG
  bool closeWindow = false;

  if (OutputLog::GetInstance().GetWindow() != nullptr)
  {
    while (OutputLog::GetInstance().GetWindow()->GetRenderWindow()->pollEvent(currentEvent))
    {
      if (currentEvent.type == sf::Event::KeyReleased)
      {
        if (currentEvent.mouseButton.button == sf::Keyboard::Space)
        {
          OutputLog::GetInstance().ShowMessages(!OutputLog::GetInstance().isShowingMessages());
        }
      }
      if (currentEvent.type == sf::Event::Closed)
      {
        closeWindow = true;
      }
    }
  }

  if (closeWindow)
  {
    OutputLog::GetInstance().CloseWindow();
  }
#endif
}

void InputManager::ClearKeyStates()
{
  for (int i = 0; i < sf::Keyboard::KeyCount; i++)
  {
    m_keyState[static_cast<sf::Keyboard::Key>(i)] = ButtonState::NONE;
  }

  for (int i = 0; i < sf::Mouse::ButtonCount; i++)
  {
    m_mouseState[static_cast<sf::Mouse::Button>(i)] = ButtonState::NONE;
  }
}

sf::Vector2i InputManager::GetMousePosition()
{
  // The position of the mouse on the screen
  sf::Vector2i pixelPos = sf::Mouse::getPosition(*Game::instance.GetWindow()->GetRenderWindow());

  // The reletive position of the mouse in the game
  return (sf::Vector2i)Game::instance.GetWindow()->GetRenderWindow()->mapPixelToCoords(pixelPos);

  //return pixelPos;
}

void InputManager::AddAction(std::string action, sf::Keyboard::Key key)
{
  m_actionMap[action].push_back(key);
}

bool InputManager::MouseOver(sf::FloatRect Rect)
{
  sf::Vector2i mousePos = GetMousePosition();

  if (mousePos.x <= Rect.left + Rect.width && mousePos.x >= Rect.left &&
    mousePos.y <= Rect.top + Rect.height && mousePos.y >= Rect.top)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool InputManager::ButtonPressed(sf::Mouse::Button button)
{
  if (m_mouseState[button] == ButtonState::PRESSED)
  {
    return true;
  }

  return false;
}

bool InputManager::ButtonDown(sf::Mouse::Button button)
{
  if (m_mouseState[button] == ButtonState::DOWN)
  {
    return true;
  }

  return false;
}

bool InputManager::ButtonReleased(sf::Mouse::Button button)
{
  if (m_mouseState[button] == ButtonState::RELEASED)
  {
    return true;
  }

  return false;
}

bool InputManager::ButtonClicked(sf::Mouse::Button button)
{
  if (m_mouseState[button] == ButtonState::CLICKED)
  {
    return true;
  }

  return false;
}

bool InputManager::KeyPressed(sf::Keyboard::Key Key)
{
  //return sf::Keyboard::isKeyPressed(Key);
  if (m_keyState[Key] == ButtonState::PRESSED)
  {
    return true;
  }

  return false;
}

bool InputManager::KeyDown(sf::Keyboard::Key Key)
{
  //return sf::Keyboard::isKeyPressed(Key);
  if (m_keyState[Key] == ButtonState::DOWN)
  {
    return true;
  }

  return false;
}

bool InputManager::KeyUp(sf::Keyboard::Key Key)
{
  if (m_keyState[Key] == ButtonState::RELEASED)
  {
    return true;
  }

  return false;
}

bool InputManager::KeyPressed(std::string action)
{
  bool actionMade = false;

  for (sf::Keyboard::Key Key : m_actionMap[action])
  {
    if (m_keyState[Key] == ButtonState::PRESSED)
    {
      actionMade = true;
    }
  }

  return actionMade;
}

bool InputManager::KeyDown(std::string action)
{
  bool actionMade = false;

  for (sf::Keyboard::Key Key : m_actionMap[action])
  {
    if (m_keyState[Key] == ButtonState::DOWN)
    {
      actionMade = true;
    }
  }

  return actionMade;
}

bool InputManager::KeyUp(std::string action)
{
  bool actionMade = false;
  
  for (sf::Keyboard::Key Key : m_actionMap[action])
  {
    if (m_keyState[Key] == ButtonState::RELEASED)
    {
      actionMade = true;
    }
  }

  return actionMade;
}

std::string InputManager::GetTextEntered()
{
  return m_textEntered;
}

float InputManager::GetMouseWheelDelta()
{
  return m_mouseWheelDelta;
}

InputManager* InputManager::GetInstance()
{
  return m_pInstance;
}

std::vector<sf::Event> InputManager::GetEvents()
{
  return m_events;
}

InputManager *InputManager::m_pInstance = new InputManager;