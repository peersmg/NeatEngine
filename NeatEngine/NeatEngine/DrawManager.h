#pragma once
#include "DataTypes.h"
#include "stdafx.h"

class DrawManager
{
private:
  static DrawManager* m_pInstance;  // Draw manager instance
  sf::Font m_defaultFont;           // The default font to use if an alternative font is not specified

public:

  DrawManager();
  ~DrawManager();

  // Return a pointer to the draw manager instance
  static DrawManager* GetInstance();

  // Initialise the draw manager
  void Initialise();

  // Draw a basic rectangle
  void BasicRect(sf::FloatRect Rect, sf::Color color);

  // Draw text
  sf::FloatRect DrawText(std::string Text, int fontSize, sf::Vector2f Position, sf::Color Color = sf::Color::White, alignment Alignment = alignment::TOPLEFT);
};

