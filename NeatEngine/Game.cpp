#include "stdafx.h"
#include "Game.h"
#include "InputManager.h"
#include "OutputLog.h"
#include "Scene.h"
#include "SSplash.h"
#include "SDefault.h"
#include "ResourceLoader.h"
#include "DefaultCamera.h"
#include "OutputLog.h"

#include "icon.h"

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

  m_mainWindow = new Window("Game Title", sf::Vector2i(1228, 768), false);
  m_mainWindow->GetRenderWindow()->setIcon(sfml_icon.width, sfml_icon.height, sfml_icon.pixel_data);

  m_gameState = GameState::Playing;

  // Load files
  ResourceLoader::GetInstance().LoadFonts();
  ResourceLoader::GetInstance().LoadSoundEffects();
  ResourceLoader::GetInstance().LoadTextures();
  ResourceLoader::GetInstance().LoadStyles();

  // Add Scenes
  m_SceneManager.AddScene("SplashScreen", new SSplash());
  m_SceneManager.AddScene("DefaultScene", new SDefault());
  m_SceneManager.AddScene("DefaultScene", new SDefault());

#ifndef NDEBUG
  OutputLog::GetInstance().Initialise();
#endif

  OutputLog::GetInstance().AddLine("Starting...", MessageType::MESSAGE);

  DefaultCamera* defaultCamera = new DefaultCamera();

  m_SceneManager.AddObject(new DefaultCamera());

  m_mainWindow->AddCamera(defaultCamera);

  // Set the initial scene
  m_SceneManager.SetScene("SplashScreen");

  // While the game is not exiting run the game loop
  while (!IsExiting())
  {
    GameLoop();
  }

  delete m_mainWindow;
}

Window* Game::GetWindow()
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
  ////

  sf::Time deltaTime = m_deltaClock.restart();

  // Update the inputs
  InputManager::GetInstance()->SampleKeyboard();

  m_mainWindow->Update();

  // Update and Draw GameObjects here
  m_SceneManager.GetScene("PersistentScene")->UpdateObjects(deltaTime.asSeconds());
  m_SceneManager.GetCurrentScene()->UpdateObjects(deltaTime.asSeconds());


  m_SceneManager.GetScene("PersistentScene")->DrawObjects();
  m_SceneManager.GetCurrentScene()->DrawObjects();

  m_SceneManager.DeleteInactiveObjects();

  ////

#ifndef NDEBUG
  OutputLog::GetInstance().Draw();
#endif

  m_mainWindow->Display();
  
}

void Game::SetState(GameState newState)
{
  m_gameState = newState;
}

Game Game::instance;