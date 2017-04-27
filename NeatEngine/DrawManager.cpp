#include "DrawManager.h"
#include "ResourceLoader.h"
#include "OutputLog.h"
#include "Game.h"

DrawManager::DrawManager()
{
}

DrawManager::~DrawManager()
{
}

void DrawManager::DrawRect(sf::FloatRect rect, sf::Color fillColor, float outlineThickness, sf::Color outlineColor, alignment alignment)
{
  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(rect.width, rect.height));
  rectangle.setPosition(AlignPosition(rect, alignment));
  rectangle.setOutlineThickness(outlineThickness);
  rectangle.setFillColor(fillColor);
  rectangle.setOutlineColor(outlineColor);

  Game::instance.GetWindow()->Draw(rectangle);
}

void DrawManager::DrawText(std::string text, sf::Vector2f position, int fontSize, std::string font, sf::Color Color, alignment alignment)
{
  sf::Font theFont;

  if (ResourceLoader::GetInstance().isFontLoaded(font))
  {
    theFont = ResourceLoader::GetInstance().GetFont(font);
  }
  else
  {
    OutputLog::GetInstance().AddLine("Font not loaded", MessageType::FATAL_ERROR);
  }

  sf::Text theText = sf::Text(text, theFont);

  theText.setColor(Color);
  theText.setCharacterSize(fontSize);

  theText.setPosition(AlignPosition(sf::FloatRect(position.x, position.y, theText.getGlobalBounds().width, theText.getGlobalBounds().height), alignment));

  Game::instance.GetWindow()->Draw(theText);
}

void DrawManager::DrawText(std::string text, sf::Vector2f position, int fontSize, sf::Font font, sf::Color Color, alignment alignment)
{
  sf::Text theText = sf::Text(text, font);

  theText.setColor(Color);
  theText.setCharacterSize(fontSize);

  theText.setPosition(AlignPosition(sf::FloatRect(position.x, position.y, theText.getGlobalBounds().width, theText.getGlobalBounds().height), alignment));

  Game::instance.GetWindow()->Draw(theText);
}

sf::Vector2f DrawManager::AlignPosition(sf::FloatRect rect, alignment theAlignment)
{
  sf::Vector2f position;

  switch (theAlignment)
  {
  case alignment::TOPLEFT:
    position = sf::Vector2f(rect.left, rect.top);
    break;
  case alignment::TOPRIGHT:
    position = sf::Vector2f(rect.left - rect.width, rect.top);
    break;
  case alignment::TOPCENTER:
    position = sf::Vector2f(rect.left - (rect.width/2), rect.top);
    break;
  case alignment::MIDDLELEFT:
    position = sf::Vector2f(rect.left, rect.top - (rect.height/2));
    break;
  case alignment::MIDDLERIGHT:
    position = sf::Vector2f(rect.left - rect.width, rect.top - (rect.height / 2));
    break;
  case alignment::MIDDLECENTER:
    position = sf::Vector2f(rect.left - (rect.width / 2), rect.top - (rect.height / 2));
    break;
  case alignment::BOTTOMLEFT:
    position = sf::Vector2f(rect.left, rect.top - rect.top);
    break;
  case alignment::BOTTOMRIGHT:
    position = sf::Vector2f(rect.left, rect.top);
    break;
  case alignment::BOTTOMCENTER:
    position = sf::Vector2f(rect.left - (rect.width / 2), rect.top - rect.top);
    break;
  default:
    break;
  }

  return position;
}