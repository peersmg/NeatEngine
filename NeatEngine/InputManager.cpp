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
  // get the current mouse position in the window
  sf::Vector2i pixelPos = sf::Mouse::getPosition(Game::instance.GetWindow());

  // convert it to world coordinates and set it
  return (sf::Vector2i)Game::instance.GetWindow().mapPixelToCoords(pixelPos);
}

bool InputManager::MouseOver(rect Rect)
{
  sf::Vector2i mousePos = GetMousePosition();

  if (mousePos.x <= Rect.x + Rect.w && mousePos.x >= Rect.x &&
    mousePos.y <= Rect.y + Rect.h && mousePos.y >= Rect.y)
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
  for (unsigned int i = 0; i < m_events.size(); i++)
  {
    if (m_events[i].type == sf::Event::KeyPressed && m_events[i].key.code == Key)
    {
      return true;
    }
  }
  
  return false;
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