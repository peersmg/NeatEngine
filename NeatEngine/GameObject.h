#pragma once
#include "stdafx.h"

class GameObject
{

  friend class ObjectManager;   // Allows object manager to access protected variables

protected:
  sf::Vector2f m_position;      // The position of the object
  bool m_active;                // Is the object active

public:
  GameObject();

  virtual ~GameObject();

  // Update gameobject logic
  virtual void Update(float deltaTime) = 0;

  // Draw the object after the logic has been updated
  virtual void Draw() = 0;

  // Set the position of the gameobject
  void SetPosition(sf::Vector2f position);

};

