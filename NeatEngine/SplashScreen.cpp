#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "CSprite.h"
#include "InputManager.h"

SplashScreen::SplashScreen()
{
  m_active = true;

  m_components.push_back(new CSprite(this, "resources/Splashscreen.png"));
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
    Game::instance.m_SceneManager.SetScene("DefaultScene");
  }
}