#include "GameObject.h"


GameObject::GameObject()
{
  // Game objects should be active by default
  m_active = true;
}

GameObject::~GameObject()
{
}

void GameObject::SetPosition(sf::Vector2f position)
{
  m_position = position;
}