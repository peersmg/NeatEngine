#include "stdafx.h"
#include "GameObject.h"
#include "OutputLog.h"

GameObject::GameObject()
{
  // Game objects should be active by default
  m_active = true;
  m_transform = Transform();
}

GameObject::~GameObject()
{
}

Transform GameObject::GetTransform()
{
  return m_transform;
}

void GameObject::SetTransform(Transform transform)
{
  m_transform = transform;
}

void GameObject::SetActive(bool active)
{
  m_active = active;
}

bool GameObject::GetActive()
{
  return m_active;
}

std::vector<Component*> GameObject::GetComponents()
{
  return m_components;
}