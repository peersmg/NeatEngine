#pragma once
#include "stdafx.h"
#include "GameObject.h"

class SplashScreen : public GameObject
{
private:
  sf::Texture splashImage;
  sf::Sprite splashSprite;
  bool imageLoaded;
public:
  virtual void Initialise();
  virtual void Update(float deltaTime);
  virtual void Draw();
};

