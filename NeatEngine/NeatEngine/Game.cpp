#include "stdafx.h"
#include "Game.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "OutputLog.h"
#include "Scene.h"
#include "SplashScene.h"

Game::Game()
{

}
Game::~Game()
{

}

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

  // Load DrawManager font
  DrawManager::GetInstance().LoadFonts();

  // Add Scenes
  m_SceneManager.AddScene("SplashScreen", new SplashScene());

  // Set the initial scene
  m_SceneManager.SetScene("SplashScreen");

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
  m_SceneManager.UpdateScene();
  m_SceneManager.DrawScene();

  m_SceneManager.DeleteInactiveObjects();

  ////

  _mainWindow.display();
  
}

void Game::SetState(GameState newState)
{
  _gameState = newState;
}

Game Game::instance;