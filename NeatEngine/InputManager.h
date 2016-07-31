#pragma once
#include "stdafx.h"

class InputManager
{
private:
  std::vector<sf::Event> m_events;
  sf::Vector2i m_mousePosition;

public:
  InputManager();
  ~InputManager();
  static InputManager *pInstance;

  void Update();
  
  std::vector<sf::Event> GetEvents();
  bool MouseOver(sf::Vector2f position, sf::Vector2f size);
  sf::Vector2i GetMousePosition();

};

