#include "SplashScreen.h"
#include "Game.h"
#include "InputManager.h"
#include "DrawManager.h"

void SplashScreen::Initialise()
{
  imageLoaded = false;
  m_active = true;

  if (splashImage.loadFromFile("images/Splashscreen.png"))
  {
    splashSprite.setTexture(splashImage);
    imageLoaded = true;
    std::cout << "Message: SplashScreen image loaded." << std::endl;
  }
  else
  {
    std::cout << "Error: SplashScreen image not loaded." << std::endl;
  }
}

void SplashScreen::Update(float deltaTime)
{
  InputManager *pInputManager = InputManager::GetInstance();
  
  // Close the splash screen if any key has been pressed
  if (pInputManager->ButtonPressed(sf::Mouse::Left))
  {
    std::cout << "Message: Exiting Splash Screen." << "\n";

    m_active = false;
  }
}

void SplashScreen::Draw()
{
  if (imageLoaded)
  {
    Game::instance.GetWindow().draw(splashSprite);
  }
}