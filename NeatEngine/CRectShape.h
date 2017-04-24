#pragma once
#include "stdafx.h"
#include "Component.h"

class CRectShape : public Component
{
private:
  sf::RectangleShape m_rectangle;

public:

  /**
  * Constructor for Rectangle shape.
  *
  * @param rect - Rectangle.
  * @param fillColor - Rectangle fill color.
  */
  CRectShape(GameObject* pOwner, sf::FloatRect rect, sf::Color fillColor, float outlineThickness = 0, sf::Color outlineColor = sf::Color::Black);

  /**
  * Destructor.
  */
  ~CRectShape();

  void Update(float deltatime) override;
  void Draw() override;
};

