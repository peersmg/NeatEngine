#include "stdafx.h"
#include "InputManager.h"
#include "Game.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::Update()
{
  sf::Event currentEvent;

  // Clear events
  m_events.clear();
  
  // Add events to array
  while (Game::instance.GetWindow().pollEvent(currentEvent))
  {
    m_events.push_back(currentEvent);
  }

  for (unsigned int i = 0; i < m_events.size(); i++)
  {
    // Request for closing the window
    if (m_events[i].type == sf::Event::Closed)
      Game::instance.SetState(Game::GameState::Exiting);
  }

  m_mousePosition = GetMousePosition();

  m_prevEvents = m_events;
}

sf::Vector2i InputManager::GetMousePosition()
{
  // The position of the mouse on the screen
  sf::Vector2i pixelPos = sf::Mouse::getPosition(Game::instance.GetWindow());

  // The reletive position of the mouse in the game
  return (sf::Vector2i)Game::instance.GetWindow().mapPixelToCoords(pixelPos);
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

bool InputManager::KeyDown(sf::Keyboard::Key Key)
{
  return sf::Keyboard::isKeyPressed(Key);
}

bool InputManager::KeyUp(sf::Keyboard::Key Key)
{
  for (unsigned  int i = 0; i < m_events.size(); i++)
  {
    if (m_events[i].type == sf::Event::KeyReleased && m_events[i].key.code == Key)
    {
      return true;
    }
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