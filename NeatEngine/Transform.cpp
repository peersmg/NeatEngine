#include "stdafx.h"
#include "Transform.h"

Transform::Transform(sf::Vector2f position, sf::Vector2f scale, float angle)
{
  m_position = position;
  m_scale = scale;
  m_angle = angle;
}

Transform::~Transform()
{
}

sf::Vector2f Transform::GetPosition()
{
  return m_position;
}

void Transform::SetPosition(sf::Vector2f position)
{
  m_position = position;
}

float Transform::GetAngle()
{
  return m_angle;
}

void Transform::SetAngle(float angle)
{
  m_angle = angle;
}

sf::Vector2f Transform::GetScale()
{
  return m_scale;
}

void Transform::SetScale(sf::Vector2f scale)
{
  m_scale = scale;
}