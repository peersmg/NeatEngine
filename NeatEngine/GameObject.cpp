#include "GameObject.h"


GameObject::GameObject()
{
  m_active = false;
}

GameObject::~GameObject()
{
  
}

void GameObject::SetPosition(sf::Vector2f position)
{
  m_position = position;
}