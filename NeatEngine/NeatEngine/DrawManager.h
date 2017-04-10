#pragma once
#include "DataTypes.h"
#include "stdafx.h"

class DrawManager
{
private:
  sf::Font m_defaultFont;           // The default font to use if an alternative font is not specified

public:

  DrawManager();
  ~DrawManager();

  static DrawManager& GetInstance()
  {
    static DrawManager instance;
    return instance;
  }

  // Initialise the draw manager
  void LoadFonts();

  // Draw a basic rectangle
  void BasicRect(sf::FloatRect Rect, sf::Color color);

  // Draw text
  sf::FloatRect DrawText(std::string Text, int fontSize, sf::Vector2f Position, sf::Color Color = sf::Color::White, alignment Alignment = alignment::TOPLEFT);
};

