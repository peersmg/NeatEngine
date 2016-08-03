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
  
  //Add events to array
  while (Game::instance.GetWindow().pollEvent(currentEvent))
  {
    m_events.push_back(currentEvent);
  }

  for (int i = 0; i < m_events.size(); i++)
  {
    // Request for closing the window
    if (m_events[i].type == sf::Event::Closed)
      Game::instance.SetState(Game::GameState::Exiting);
  }

  // get the current mouse position in the window
  sf::Vector2i pixelPos = sf::Mouse::getPosition(Game::instance.GetWindow());

  // convert it to world coordinates and set it
  m_mousePosition = (sf::Vector2i)Game::instance.GetWindow().mapPixelToCoords(pixelPos);
}

sf::Vector2i InputManager::GetMousePosition()
{
  return m_mousePosition;
}

bool InputManager::MouseOver(rect Rect)
{

  if (m_mousePosition.x <= Rect.x + Rect.w && m_mousePosition.x >= Rect.x &&
    m_mousePosition.y <= Rect.y + Rect.h && m_mousePosition.y >= Rect.y)
  {
    return true;
  }
  else
  {
    return false;
  }
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