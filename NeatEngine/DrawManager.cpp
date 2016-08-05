#include "DrawManager.h"
#include "Game.h"

DrawManager::DrawManager()
{
  
}


DrawManager::~DrawManager()
{
}

void DrawManager::Initialise()
{
  m_defaultFont.loadFromFile("fonts/SquaresBold.otf");
}

DrawManager* DrawManager::GetInstance()
{
  return m_pInstance;
}

void DrawManager::BasicRect(rect Rect, sf::Color color)
{
  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(Rect.w, Rect.h));
  rectangle.setPosition(Rect.x, Rect.y);
  rectangle.setOutlineThickness(0);
  rectangle.setFillColor(sf::Color::Blue);
  
  Game::instance.GetWindow().draw(rectangle);
}

void DrawManager::DrawText(std::string Text, int fontSize, sf::Vector2f Position, sf::Color Color)
{
  
  // Create text
  sf::Text text(Text, m_defaultFont);
  text.setCharacterSize(fontSize);
  text.setColor(Color);
  text.setPosition(Position);

  // Draw it
  Game::instance.GetWindow().draw(text);
}

DrawManager *DrawManager::m_pInstance = new DrawManager;