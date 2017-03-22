#include "Game.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "OutputLog.h"

void Game::Start()
{
  if (_gameState != GameState::Uninitialized)
  {
    return;
  }

  OutputLog log;
  log.Output("Starting...", OutputLog::MessageType::MESSAGE);

  _mainWindow.create(sf::VideoMode(1024, 768, 32), "Game Title", sf::Style::Titlebar | sf::Style::Close);
  _gameState = GameState::Playing;

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
  OutputLog log;
  // Clear to grey
  _mainWindow.clear(sf::Color(100, 100, 100));

  // If the game state has been switched set the previous game state and output message
  if (_prevGameState != _gameState)
  {
    switch (Game::_gameState)
    {
      case Game::GameState::Uninitialized:
        log.Output("Uninitialized", OutputLog::MessageType::MESSAGE);
        _prevGameState = GameState::Uninitialized;
        break;
      case Game::GameState::Playing:
        log.Output("Playing", OutputLog::MessageType::MESSAGE);
        _prevGameState = GameState::Playing;
        break;
      case Game::GameState::Exiting:
        log.Output("Exiting...", OutputLog::MessageType::MESSAGE);
        _prevGameState = GameState::Exiting;
        break;
      default:
        break;
    }
  }
   
  ////

  // Update the inputs
  InputManager::GetInstance()->SampleKeyboard();

  // Update and Draw GameObjects here
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