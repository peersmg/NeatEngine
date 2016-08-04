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

  std::vector<sf::Event> events = pInputManager->GetEvents();
  
  for (int i = 0; i < events.size(); i++)
  {
    if (events[i].type == sf::Event::EventType::KeyPressed || events[i].type == sf::Event::EventType::MouseButtonPressed || events[i].type == sf::Event::EventType::Closed)
    {
      std::cout << "Message: Exiting Splash Screen. Event ID: " << events[i].type << "\n";

      Game::instance.SetState(Game::GameState::ShowingMenu);

      m_active = false;
    }
  }

  if (pInputManager->MouseOver(rect(0, 0, 50, 50)) && pInputManager->KeyDown(sf::Keyboard::Space))
  {
    std::cout << "Message: Box selected\n";
  }

}

void SplashScreen::Draw()
{
  DrawManager *pDrawManager = DrawManager::GetInstance();

  if (imageLoaded)
  {
    Game::instance.GetWindow().draw(splashSprite);
  }
}