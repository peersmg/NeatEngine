#include "stdafx.h"
#include "GameObject.h"
#include "OutputLog.h"

GameObject::GameObject()
{
  // Game objects should be active by default
  m_active = true;
  m_transform = Transform();
  m_layer = 0;
  m_isPersistent = false;
}

GameObject::~GameObject()
{
  while (m_components.size() > 0)
  {
    delete m_components[m_components.size()-1];
    m_components[m_components.size()-1] = nullptr;
    m_components.pop_back();
  }
}

Transform GameObject::GetTransform()
{
  return m_transform;
}

void GameObject::SetTransform(Transform transform)
{
  m_transform = transform;
}

int GameObject::GetLayer()
{
  return m_layer;
}

void GameObject::SetLayer(int newLayer)
{
  m_layer = newLayer;
}

bool GameObject::GetPersistent()
{
  return m_isPersistent;
}

void GameObject::SetPersistent(bool persistent)
{
  m_isPersistent = persistent;
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

void GameObject::AddComponent(Component* newComponent)
{
  m_components.push_back(newComponent);
}