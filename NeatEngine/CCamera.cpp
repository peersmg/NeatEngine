#include "stdafx.h"
#include "CCamera.h"
#include "GameObject.h"
#include "InputManager.h"
#include "OutputLog.h"

CCamera::CCamera(GameObject* pOwner, sf::Vector2i size, sf::FloatRect viewport, float angle, float zoom, bool zoomable)
{
  m_angle = angle;
  m_size = size;
  m_viewport = viewport;
  m_pOwner = pOwner;
  m_zoom = zoom;
  m_zoomable = zoomable;

  m_maxZoom = 0.1;
  m_minZoom = 5;
  
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
  m_view.reset(sf::FloatRect(m_pOwner->GetTransform().GetOrigin().x*m_pOwner->GetTransform().GetPosition().x,
    m_pOwner->GetTransform().GetOrigin().y*m_pOwner->GetTransform().GetPosition().y,
    m_size.x, m_size.y));

  if (m_zoomable)
  {
    m_zoom -= InputManager::GetInstance()->GetMouseWheelDelta()/10;

    if (m_zoom < m_maxZoom)
    {
      m_zoom = m_maxZoom;
    }
    else if (m_zoom > m_minZoom)
    {
      m_zoom = m_minZoom;
    }
  }
  
  m_view.setViewport(m_viewport);
  m_view.setRotation(m_angle);
  m_view.zoom(m_zoom);

}

sf::View CCamera::GetView()
{
  return m_view;
}

void CCamera::SetZoom(float zoom)
{
  m_zoom = zoom;
}

float CCamera::GetZoom()
{
  return m_zoom;
}