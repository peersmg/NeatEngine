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

  void BasicRect(rect Rect, sf::Color color);
  void DrawText(std::string Text, int fontSize, sf::Vector2f Position, sf::Color Color = sf::Color::White, alignment Alignment = alignment::TOPLEFT);
};

