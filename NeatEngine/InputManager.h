#pragma once
#include "stdafx.h"
#include "DataTypes.h"

class InputManager
{
private:
  std::vector<sf::Event> m_events;
  std::vector<sf::Event> m_prevEvents;
  sf::Vector2i m_mousePosition;
  static InputManager *m_pInstance;

public:
  InputManager();
  ~InputManager();
  

  void Update();
  static InputManager* GetInstance();

  std::vector<sf::Event> GetEvents();
  sf::Vector2i GetMousePosition();

  bool MouseOver(sf::FloatRect Rect);
  bool KeyDown(sf::Keyboard::Key Key);
  bool KeyUp(sf::Keyboard::Key Key);
};