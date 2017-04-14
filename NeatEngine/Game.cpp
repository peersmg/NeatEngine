#include "stdafx.h"
#include "Game.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "OutputLog.h"
#include "Scene.h"
#include "SplashScene.h"
#include "SDefault.h"

Game::Game()
{

}
Game::~Game()
{

}

void Game::Start()
{
  if (m_gameState != GameState::Uninitialized)
  {
    return;
  }

  OutputLog log;
  log.Output("Starting...", OutputLog::MessageType::MESSAGE);

  m_mainWindow.create(sf::VideoMode(1024, 768, 32), "Game Title", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  m_gameState = GameState::Playing;

  // Load DrawManager font
  DrawManager::GetInstance().LoadFonts();

  // Add Scenes
  m_SceneManager.AddScene("SplashScreen", new SplashScene());
  m_SceneManager.AddScene("DefaultScene", new SDefault());

  // Set the initial scene
  m_SceneManager.SetScene("SplashScreen");

  // While the game is not exiting run the game loop
  while (!IsExiting())
  {
    GameLoop();
  }

  m_mainWindow.close();
}

sf::RenderWindow &Game::GetWindow()
{
  return m_mainWindow;
}

bool Game::IsExiting()
{
  if (m_gameState == GameState::Exiting)
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
  m_mainWindow.clear(sf::Color(100, 100, 100));
   
  ////

  sf::Time deltaTime = m_deltaClock.restart();

  // Update the inputs
  InputManager::GetInstance()->SampleKeyboard();

  // Update and Draw GameObjects here
  m_SceneManager.GetScene("PersistentScene")->UpdateObjects(deltaTime.asSeconds());
  m_SceneManager.GetCurrentScene()->UpdateObjects(deltaTime.asSeconds());


  m_SceneManager.GetScene("PersistentScene")->DrawObjects();
  m_SceneManager.GetCurrentScene()->DrawObjects();

  m_SceneManager.DeleteInactiveObjects();

  ////

  m_mainWindow.display();
  
}

void Game::SetState(GameState newState)
{
  m_gameState = newState;
}

Game Game::instance;