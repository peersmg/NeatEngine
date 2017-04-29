#include "stdafx.h"
#include "Component.h"

Component::Component()
{
  m_pOwner = nullptr;
  m_visible = true;
}

Component::~Component()
{

}

void Component::SetVisible(bool visible)
{
  m_visible = visible;
}

bool Component::GetVisible()
{
  return m_visible;
}

void Component::SetDormant(bool dormant)
{
  m_dormant = dormant;
}

bool Component::GetDormant()
{
  return m_dormant;
}