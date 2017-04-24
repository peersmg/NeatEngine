#pragma once
#include "stdafx.h"

class Transform
{
private:
  sf::Vector2f m_position;    // Object position
  sf::Vector2f m_scale;       // Object scale
  float m_angle;              // Object angle
  sf::Vector2f m_origin;      // Object origin point

public:

  /**
  * Constructor.
  *
  * @param position - Initial position.
  * @param scale - Initial scale.
  * @param angle - Initial angle.
  */
  Transform(sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f scale = sf::Vector2f(1.0, 1.0), sf::Vector2f origin = sf::Vector2f(0.0, 0.0), float angle = 0.0);

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
  * Get the transform angle.
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

  /**
  * Get the origin point.
  *
  * @return The origin point.
  */
  sf::Vector2f GetOrigin();

  /**
  * Set the origin point.
  *
  * @param origin - The new origin point.
  */
  void SetOrigin(sf::Vector2f origin);
};

