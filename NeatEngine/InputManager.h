#pragma once
#include "stdafx.h"
#include "DataTypes.h"

class InputManager
{
private:
  std::vector<sf::Event> m_events;        // Vector of current events
  std::vector<sf::Event> m_prevEvents;    // Vector of events from previous check
  sf::Vector2i m_mousePosition;           // Position of the mouse
  static InputManager *m_pInstance;       // Pointer to the InputManager instance

public:
  InputManager();
  ~InputManager();
  
  // Poll events and add them to m_events
  void Update();

  // Return a pointer to an instance of the InputManager
  static InputManager* GetInstance();

  // Return a vector of the events
  std::vector<sf::Event> GetEvents();

  // Return the mouse position
  sf::Vector2i GetMousePosition();

  // Returns true if the mouse is over the specified rect
  bool MouseOver(sf::FloatRect Rect);

  // Returns true if the key is being held down
  bool KeyDown(sf::Keyboard::Key Key);

  // Returns true if the key has just been released
  bool KeyUp(sf::Keyboard::Key Key);
};