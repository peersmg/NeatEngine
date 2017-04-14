#pragma once
#include "stdafx.h"
#include "Component.h"

class GameObject;
class CTransform;

class CSprite : public Component
{
private:
  sf::Texture m_splashImage;    // Image to be used as a sprite
  sf::Sprite m_splashSprite;    // The sprite that will be drawn to the screen
  bool m_imageLoaded;           // Has the image been properly loaded

public:
  CSprite(GameObject* pOwner, std::string imageFile);
  ~CSprite();

  virtual void Update(float deltatime) override;
  virtual void Draw() override;
};

