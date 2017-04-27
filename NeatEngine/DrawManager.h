#pragma once
#include "stdafx.h"

class DrawManager
{
private:
  DrawManager();
  ~DrawManager();

public:

  static DrawManager& GetInstance()
  {
    static DrawManager instance;
    return instance;
  }
  
  void DrawRect(sf::FloatRect rect, sf::Color fillColor, float outlineThickness = 0, sf::Color outlineColor = sf::Color::Black, alignment alignment = alignment::TOPLEFT);

  void DrawText(std::string text, sf::Vector2f position, int fontSize, std::string font, sf::Color Color, alignment alignment = alignment::TOPLEFT);
  void DrawText(std::string text, sf::Vector2f position, int fontSize, sf::Font font, sf::Color Color, alignment alignment = alignment::TOPLEFT);

  sf::Vector2f AlignPosition(sf::FloatRect rect, alignment theAlignment);
};

