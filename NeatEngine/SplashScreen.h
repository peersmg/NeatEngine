#pragma once
#include "stdafx.h"
#include "GameObject.h"

class SplashScreen : public GameObject
{
private:
  sf::Texture splashImage;    // Image to be used as a sprite
  sf::Sprite splashSprite;    // The sprite that will be drawn to the screen
  bool imageLoaded;           // Has the image been properly loaded

public:

  // Load the splashscreen image
  virtual void Initialise();

  // Check if the splashscreen has been closed
  virtual void Update(float deltaTime);

  // Draw the splash screen
  virtual void Draw();
};

