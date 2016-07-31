#include "Game.h"


void Game::Start()
{
  if (_gameState != GameState::Uninitialized)
  {
    return;
  }

  std::cout << "Message: Starting..." << std::endl;

  _mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang");
  _gameState = GameState::Playing;

  //Start code here
  SplashScreen *mainSplash = new SplashScreen;
  m_objects.AddObject(mainSplash);
  mainSplash->Initialise();
  //

  while (!IsExiting())
  {
    GameLoop();
  }

  std::cout << "Message: Exiting...\n";

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
  sf::Event currentEvent;

  if (!IsExiting())
  {
    // Clear to grey
    _mainWindow.clear(sf::Color(100, 100, 100));

    // Clear events
    _events.clear();

    //Add events to array
    while (_mainWindow.pollEvent(currentEvent))
    {
      _events.push_back(currentEvent);
    }

    //// GAME STUFF HERE ////

    if (_prevGameState != _gameState)
    {
      switch (Game::_gameState)
      {
      case Game::GameState::Uninitialized:

        _prevGameState = GameState::Uninitialized;
        break;
      case Game::GameState::ShowingSplash:

        _prevGameState = GameState::ShowingSplash;
        break;
      case Game::GameState::Paused:

        _prevGameState = GameState::Paused;
        break;
      case Game::GameState::ShowingMenu:
        std::cout << "Message: Adding menu class\n";
        _prevGameState = GameState::ShowingMenu;
        break;
      case Game::GameState::Playing:

        _prevGameState = GameState::Playing;
        break;
      case Game::GameState::Exiting:

        _prevGameState = GameState::Exiting;
        break;
      default:
        break;
      }
    }

    ////

    // Draw and update  GameObjects here

    m_objects.UpdateAll();
    m_objects.DrawAll();

    m_objects.DeleteInactiveObjects();

    //

    _mainWindow.display();

    // Exit the game and close the window if the x button is pressed
    
    for (int i = 0; i < _events.size(); i++)
    {
      // Request for closing the window
      if (currentEvent.type == sf::Event::Closed)
        _gameState = GameState::Exiting;
    }
    
    
  }
}

void Game::SetState(GameState newState)
{
  _gameState = newState;
}

std::vector<sf::Event> Game::PollEvents()
{
  return _events;
}

Game Game::instance;