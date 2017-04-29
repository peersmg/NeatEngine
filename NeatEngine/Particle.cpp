#include "Particle.h"
#include "Game.h"

Particle::Particle(sf::Vector2f startPos, sf::Vector2f startVel, sf::Sprite sprite, float lifetime, sf::Vector2f gravity, sf::Vector2f size, sf::Color color)
{
  m_position = startPos;
  m_sprite = sprite;
  m_size = size;
  m_velocity = startVel;
  m_gravity = gravity;
  m_lifetime = lifetime;
  m_color = color;

  m_sprite.setScale(sf::Vector2f(m_size.x / m_sprite.getGlobalBounds().width, m_size.y/m_sprite.getGlobalBounds().height));
  m_sprite.setColor(m_color);
}


Particle::~Particle()
{
}

void Particle::Update(float deltaTime)
{
  m_lifetime -= deltaTime;

  if (m_lifetime <= 0)
  {
    m_active = false;
  }

  m_velocity -= m_gravity;

  m_position += m_velocity*deltaTime;
  m_sprite.setPosition(m_position);
}

void Particle::Draw()
{
  Game::instance.GetWindow()->Draw(m_sprite);
}

bool Particle::GetActive()
{
  return m_active;
}