#include "stdafx.h"
#include "CRectShape.h"
#include "Game.h"

CRectShape::CRectShape(GameObject* pOwner, sf::FloatRect rect, sf::Color fillColor, float outlineThickness, sf::Color outlineColor)
{
  m_pOwner = pOwner;

  Transform ownerTransform = m_pOwner->GetTransform();

  m_rectangle.setSize(sf::Vector2f(rect.width, rect.height));
  m_rectangle.setPosition(sf::Vector2f(rect.left, rect.top));
  m_rectangle.setOutlineThickness(outlineThickness);
  m_rectangle.setFillColor(fillColor);
  m_rectangle.setOutlineColor(outlineColor);
}


CRectShape::~CRectShape()
{
}

void CRectShape::Update(float deltatime)
{
  Transform ownerTransform = m_pOwner->GetTransform();

  m_rectangle.setPosition(ownerTransform.GetPosition());
}

void CRectShape::Draw()
{
  Game::instance.GetWindow()->Draw(m_rectangle);
}