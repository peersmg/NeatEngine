#pragma once
#include "stdafx.h"

class Particle
{
  bool m_active;
  sf::Sprite m_sprite;

  sf::Vector2f m_position;
  sf::Vector2f m_size;
  sf::Vector2f m_velocity;
  sf::Vector2f m_gravity;

  sf::Color m_color;

  float m_lifetime;

public:
  Particle(sf::Vector2f startPos, sf::Vector2f startVel, sf::Sprite sprite, float lifetime, sf::Vector2f gravity, sf::Vector2f size, sf::Color color);
  ~Particle();

  void Update(float deltaTime);
  void Draw();

  bool GetActive();
};

