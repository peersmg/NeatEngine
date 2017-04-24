#include "stdafx.h"
#include "Transform.h"

Transform::Transform(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f origin, float angle)
{
  m_position = position;
  m_scale = scale;
  m_angle = angle;
  m_origin = origin;
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

sf::Vector2f Transform::GetOrigin()
{
  return m_origin;
}

void Transform::SetOrigin(sf::Vector2f origin)
{
  m_origin = origin;
}