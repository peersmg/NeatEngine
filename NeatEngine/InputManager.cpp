#include "stdafx.h"
#include "InputManager.h"
#include "Game.h"
#include "OutputLog.h"

InputManager::InputManager()
{
  ClearKeyStates();
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
    }
    else if (currentEvent.type == sf::Event::MouseButtonReleased)
    {
      m_mouseState[currentEvent.mouseButton.button] = ButtonState::RELEASED;
    }
    else if (currentEvent.type == sf::Event::Closed)
    {
      Game::instance.SetState(GameState::Exiting);
    }
  }
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

InputManager* InputManager::GetInstance()
{
  return m_pInstance;
}

std::vector<sf::Event> InputManager::GetEvents()
{
  return m_events;
}

InputManager *InputManager::m_pInstance = new InputManager;