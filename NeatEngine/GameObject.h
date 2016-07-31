#pragma once
#include "stdafx.h"

class GameObject
{

  friend class ObjectManager;

protected:
  sf::Vector2f m_position;
  int m_drawdepth;
  bool m_active;

public:
  GameObject();

  virtual ~GameObject();

  virtual void Initialise() = 0;
  virtual void Update(float deltaTime) = 0;
  virtual void Draw() = 0;

  void SetPosition(sf::Vector2f position);

};

