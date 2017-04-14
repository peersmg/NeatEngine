#include "stdafx.h"
#include "CSprite.h"
#include "GameObject.h"
#include "OutputLog.h"
#include "Game.h"

#include "Transform.h"

CSprite::CSprite(GameObject* pOwner, std::string imageFile)
{
  m_imageLoaded = false;
  m_pOwner = pOwner;

  OutputLog log;

  if (m_splashImage.loadFromFile(imageFile))
  {
    m_splashSprite.setTexture(m_splashImage);

    m_splashSprite.setScale(m_pOwner->GetTransform().GetScale());
    m_splashSprite.setPosition(m_pOwner->GetTransform().GetPosition());
    m_splashSprite.setRotation(m_pOwner->GetTransform().GetAngle());

    m_imageLoaded = true;
    log.Output("Image \"" + imageFile + "\" loaded.", OutputLog::MessageType::MESSAGE);
  }
  else
  {
    log.Output("SplashScreen image failed to load", OutputLog::MessageType::ERROR);
  }
}

CSprite::~CSprite()
{
}

void CSprite::Update(float deltaTime)
{
  m_splashSprite.setScale(m_pOwner->GetTransform().GetScale());
  m_splashSprite.setPosition(m_pOwner->GetTransform().GetPosition());
  m_splashSprite.setRotation(m_pOwner->GetTransform().GetAngle());
}

void CSprite::Draw()
{
  if (m_imageLoaded)
  {
    Game::instance.GetWindow().draw(m_splashSprite);
  }
}