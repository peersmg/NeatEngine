#include "Game.h"
#include "InputManager.h"
#include "DrawManager.h"

void Game::Start()
{
  if (_gameState != GameState::Uninitialized)
  {
    return;
  }

  std::cout << "Message: Starting..." << std::endl;

  _mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang", sf::Style::Titlebar | sf::Style::Close);
  _gameState = GameState::ShowingSplash;

  //Initialise DrawManager
  DrawManager::GetInstance()->Initialise();

  // Game start code here
  SplashScreen *mainSplash = new SplashScreen;
  m_objects.AddObject(mainSplash);
  mainSplash->Initialise();


  ////

  // While the game is not exiting run the game loop
  while (!IsExiting())
  {
    GameLoop();
  }

  _mainWindow.close();
}

sf::RenderWindow &Game::GetWindow()
{
  return _mainWindow;
}

bool Game::IsExiting()
{
  if (_gameState == GameState::Exiting)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Game::GameLoop()
{

  // Clear to grey
  _mainWindow.clear(sf::Color(100, 100, 100));

  // If the game state has been switched set the previous game state and output message
  if (_prevGameState != _gameState)
  {
    switch (Game::_gameState)
    {
      case Game::GameState::Uninitialized:
        std::cout << "Message: Uninitialized\n";
        _prevGameState = GameState::Uninitialized;
        break;
      case Game::GameState::ShowingSplash:
        std::cout << "Message: Showing Splash\n";
        _prevGameState = GameState::ShowingSplash;
        break;
      case Game::GameState::Paused:
        std::cout << "Message: Game Paused\n";
        _prevGameState = GameState::Paused;
        break;
      case Game::GameState::ShowingMenu:
        std::cout << "Message: Showing Menu\n";
        _prevGameState = GameState::ShowingMenu;
        break;
      case Game::GameState::Playing:
        std::cout << "Message: Playing\n";
        _prevGameState = GameState::Playing;
        break;
      case Game::GameState::Exiting:
        std::cout << "Message: Exiting...\n";
        _prevGameState = GameState::Exiting;
        break;
      default:
        break;
    }
  }
   
  ////

  // Update the inputs
  InputManager::GetInstance()->Update();

  // Draw and update GameObjects here
  m_objects.UpdateAll();
  m_objects.DrawAll();

  m_objects.DeleteInactiveObjects();

  ////

  _mainWindow.display();
  
}

void Game::SetState(GameState newState)
{
  _gameState = newState;
}

Game Game::instance;