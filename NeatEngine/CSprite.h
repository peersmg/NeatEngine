#pragma once
#include "stdafx.h"
#include "Component.h"

class GameObject;

class CSprite : public Component
{
private:
  sf::Texture m_texture;        // Image to be used as a sprite
  sf::Sprite m_sprite;          // The sprite that will be drawn to the screen
  bool m_imageLoaded;           // Has the image been properly loaded

public:
  CSprite(GameObject* pOwner, std::string imageFile, bool smooth = false);
  ~CSprite();

  void Update(float deltatime) override;
  void Draw() override;
};

