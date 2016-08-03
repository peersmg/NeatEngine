#pragma once
#include "stdafx.h"

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
  bool MouseOver(sf::Vector2f position, sf::Vector2f size);
  sf::Vector2i GetMousePosition();

};

