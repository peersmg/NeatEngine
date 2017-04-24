#include "stdafx.h"
#include "CCamera.h"
#include "GameObject.h"

CCamera::CCamera(GameObject* pOwner, sf::Vector2i size, sf::FloatRect viewport, float angle)
{
  m_angle = angle;
  m_size = size;
  m_viewport = viewport;
  m_pOwner = pOwner;
  
  m_view.reset(sf::FloatRect(m_pOwner->GetTransform().GetOrigin().x*m_pOwner->GetTransform().GetPosition().x, 
               m_pOwner->GetTransform().GetOrigin().y*m_pOwner->GetTransform().GetPosition().y, 
               m_size.x, m_size.y));

  m_view.setViewport(m_viewport);
  m_view.setRotation(m_angle);
}


CCamera::~CCamera()
{
}

void CCamera::Update(float deltaTime)
{
  m_view.reset(sf::FloatRect(m_pOwner->GetTransform().GetPosition().x, m_pOwner->GetTransform().GetPosition().y, m_size.x, m_size.y));
  m_view.setViewport(m_viewport);
  m_view.setCenter(sf::Vector2f(m_pOwner->GetTransform().GetOrigin().x*m_size.x, m_pOwner->GetTransform().GetOrigin().y*m_size.y));
  m_view.setRotation(m_angle);
}

sf::View CCamera::GetView()
{
  return m_view;
}