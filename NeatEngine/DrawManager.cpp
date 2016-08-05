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
  rectangle.setFillColor(color);
  
  Game::instance.GetWindow().draw(rectangle);
}

void DrawManager::DrawText(std::string Text, int fontSize, sf::Vector2f Position, sf::Color Color)
{
  
  // Create text
  sf::Text text(Text, m_defaultFont);
  text.setCharacterSize(fontSize);
  text.setColor(Color);

  text.setPosition(sf::Vector2f(Position.x - text.getLocalBounds().width / 2, Position.y - text.getLocalBounds().height / 2));

  // Draw it
  Game::instance.GetWindow().draw(text);
}

DrawManager *DrawManager::m_pInstance = new DrawManager;