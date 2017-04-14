#pragma once

#include "stdafx.h"
#include "SceneManager.h"

class Game
{

private:
  Game();
  ~Game();

  GameState m_gameState;           // The current game state
  sf::RenderWindow m_mainWindow;   // The render window

  sf::Clock m_deltaClock;         // Clock used to measure delta time

public:

  // Start the game, should only be called once in main
  void Start();

  // Is the game state set to exiting
  bool IsExiting();

  // Main game loop, called as long as the game is not exiting
  void GameLoop();

  // Return a reference to the window
  sf::RenderWindow &GetWindow();

  // Set _gameState
  void SetState(GameState newState);

  static Game instance;           // Static game instance
  SceneManager m_SceneManager;        // Manager class for game objects
};

