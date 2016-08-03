#include "stdafx.h"
#include "DrawManager.h"
#include "Game.h"

DrawManager::DrawManager()
{
  
}


DrawManager::~DrawManager()
{
}

DrawManager* DrawManager::GetInstance()
{
  return m_pDrawManager;
}

void DrawManager::BasicRect(rect Rect)
{
  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(Rect.w, Rect.h));
  rectangle.setPosition(Rect.x, Rect.y);
  rectangle.setOutlineThickness(0);
  rectangle.setFillColor(sf::Color::Blue);
  
  Game::instance.GetWindow().draw(rectangle);
}

DrawManager *DrawManager::m_pDrawManager = new DrawManager;