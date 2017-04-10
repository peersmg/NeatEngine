#include "stdafx.h"
#include "SplashScreen.h"
#include "SpriteComponent.h"
#include "InputManager.h"

SplashScreen::SplashScreen()
{
  m_active = true;

  m_components.push_back(new SpriteComponent(this, "resources/Splashscreen.png"));
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Update(float deltaTime)
{
  InputManager *pInputManager = InputManager::GetInstance();

  // Close the splash screen if any key has been pressed
  if (pInputManager->ButtonReleased(sf::Mouse::Left))
  {

    SetActive(false);
  }
}