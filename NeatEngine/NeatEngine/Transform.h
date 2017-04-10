#pragma once
#include "stdafx.h"

class Transform
{
private:
  sf::Vector2f m_position;
  sf::Vector2f m_scale;
  float m_angle;

public:

  /**
  * Constructor.
  *
  * @param position - Initial position.
  * @param scale - Initial scale.
  * @param angle - Initial angle.
  */
  Transform(sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f scale = sf::Vector2f(1.0, 1.0), float angle = 0.0);

  /**
  * Destructor.
  */
  ~Transform();

  /**
  * Get the position.
  *
  * @return The position of the transform.
  */
  sf::Vector2f GetPosition();

  /**
  * Set the transform position.
  *
  * @param position - The new position.
  */
  void SetPosition(sf::Vector2f position);

  /**
  * Get the angle.
  *
  * @return The angle of the transform.
  */
  float GetAngle();

  /**
  * Set the transform angle.
  *
  * @param angle - The new angle.
  */
  void SetAngle(float angle);

  /**
  * Set the transform angle.
  *
  * @return The scale of the transform.
  */
  sf::Vector2f GetScale();

  /**
  * Set the transform scale.
  *
  * @param scale - The new scale.
  */
  void SetScale(sf::Vector2f scale);
};

