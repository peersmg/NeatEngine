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

void DrawManager::BasicRect(sf::FloatRect Rect, sf::Color color)
{
  sf::RectangleShape rectangle;   // The rect class that will be drawn to the screen

  rectangle.setSize(sf::Vector2f(Rect.width, Rect.height));
  rectangle.setPosition(Rect.left, Rect.top);
  rectangle.setOutlineThickness(0);
  rectangle.setFillColor(color);
  
  Game::instance.GetWindow().draw(rectangle);
}

sf::FloatRect DrawManager::DrawText(std::string Text, int fontSize, sf::Vector2f Position, sf::Color Color, alignment Alignment)
{
  
  // Create text
  sf::Text text(Text, m_defaultFont);
  text.setCharacterSize(fontSize);
  text.setColor(Color);

  // Set the position of the text based on the passed alignment
  switch (Alignment)
  {
  case alignment::TOPLEFT:
    text.setPosition(sf::Vector2f(Position.x, Position.y));
    break;
  case alignment::TOPRIGHT:
    text.setPosition(sf::Vector2f(Position.x - text.getLocalBounds().width, Position.y));
    break;
  case alignment::TOPCENTER:
    text.setPosition(sf::Vector2f(Position.x - (text.getLocalBounds().width/2), Position.y));
    break;
  case alignment::MIDDLELEFT:
    text.setPosition(sf::Vector2f(Position.x, Position.y - (text.getLocalBounds().height / 2)));
    break;
  case alignment::MIDDLERIGHT:
    text.setPosition(sf::Vector2f(Position.x - text.getLocalBounds().width, Position.y - (text.getLocalBounds().height / 2)));
    break;
  case alignment::MIDDLECENTER:
    text.setPosition(sf::Vector2f(Position.x - text.getLocalBounds().width / 2, Position.y - (text.getLocalBounds().height / 2)));
    break;
  case alignment::BOTTOMLEFT:
    text.setPosition(sf::Vector2f(Position.x, Position.y - (text.getLocalBounds().height)));
    break;
  case alignment::BOTTOMRIGHT:
    text.setPosition(sf::Vector2f(Position.x - text.getLocalBounds().width, Position.y - (text.getLocalBounds().height)));
    break;
  case alignment::BOTTOMCENTER:
    text.setPosition(sf::Vector2f(Position.x - (text.getLocalBounds().width / 2), Position.y - (text.getLocalBounds().height)));
    break;
  default:
    break;
  }

  // Draw it
  Game::instance.GetWindow().draw(text);

  // Return text bounds
  return text.getGlobalBounds();
}

DrawManager *DrawManager::m_pInstance = new DrawManager;