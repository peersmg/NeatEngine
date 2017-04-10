#pragma once

#include "stdafx.h"
#include "SceneManager.h"

class Game
{
public:
  
  // Main enum for game state
  enum class GameState { Uninitialized, Playing, Exiting };

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

private:
  Game();
  ~Game();
  GameState _gameState;           // The current game state
  GameState _prevGameState;       // The previous game state
  sf::RenderWindow _mainWindow;   // The render window
};

