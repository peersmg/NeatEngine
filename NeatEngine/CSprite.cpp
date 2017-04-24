#include "stdafx.h"
#include "CSprite.h"
#include "GameObject.h"
#include "OutputLog.h"
#include "Game.h"
#include "ResourceLoader.h"

CSprite::CSprite(GameObject* pOwner, std::string imageFile, bool smooth)
{
  m_imageLoaded = false;
  m_pOwner = pOwner;

  if (ResourceLoader::GetInstance().isTextureLoaded(imageFile))
  {
    m_texture = ResourceLoader::GetInstance().GetTexture(imageFile);
    m_imageLoaded = true;
  }
  else
  {
    m_imageLoaded = m_texture.loadFromFile(imageFile);
  }

  if (m_imageLoaded)
  {

    m_texture.setSmooth(smooth);

    m_sprite.setTexture(m_texture);

    m_sprite.setScale(m_pOwner->GetTransform().GetScale());
    m_sprite.setPosition(m_pOwner->GetTransform().GetPosition());
    m_sprite.setRotation(m_pOwner->GetTransform().GetAngle());

    m_imageLoaded = true;
    OutputLog::GetInstance().AddLine("Image \"" + imageFile + "\" loaded.", MessageType::MESSAGE);
  }
  else
  {
    OutputLog::GetInstance().AddLine("Image failed to load", MessageType::ERROR);
  }
}

CSprite::~CSprite()
{
}

void CSprite::Update(float deltaTime)
{
  m_sprite.setScale(m_pOwner->GetTransform().GetScale());
  m_sprite.setPosition(m_pOwner->GetTransform().GetPosition());
  m_sprite.setRotation(m_pOwner->GetTransform().GetAngle());
}

void CSprite::Draw()
{
  if (m_imageLoaded)
  {
    Game::instance.GetWindow()->Draw(m_sprite);
  }
}