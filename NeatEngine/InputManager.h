#pragma once
#include "stdafx.h"
#include "DataTypes.h"

class InputManager
{
private:
  std::vector<sf::Event> m_events;
  sf::Vector2i m_mousePosition;
  static InputManager *m_pInstance;

public:
  InputManager();
  ~InputManager();
  

  void Update();
  static InputManager* GetInstance();

  std::vector<sf::Event> GetEvents();
  bool MouseOver(rect Rect);
  sf::Vector2i GetMousePosition();

};

