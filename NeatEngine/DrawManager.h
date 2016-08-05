#pragma once
#include "DataTypes.h"
#include "stdafx.h"

class DrawManager
{
private:
  static DrawManager* m_pInstance;

  sf::Font m_defaultFont;

public:

  DrawManager();
  ~DrawManager();

  static DrawManager* GetInstance();

  void Initialise();

  void BasicRect(sf::FloatRect Rect, sf::Color color);
  sf::FloatRect DrawText(std::string Text, int fontSize, sf::Vector2f Position, sf::Color Color = sf::Color::White, alignment Alignment = alignment::TOPLEFT);
};

