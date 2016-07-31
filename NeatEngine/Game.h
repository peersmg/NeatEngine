#pragma once

#include <iostream>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#include "SplashScreen.h"
#include "ObjectManager.h"

class Game
{
public:
  enum class GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

  static Game instance;
  void Start();
  sf::RenderWindow &GetWindow();
  std::vector<sf::Event> PollEvents();
  void SetState(GameState newState);
  ObjectManager m_objects;

private:
  bool IsExiting();
  void GameLoop();

  std::vector<sf::Event> _events;
  GameState _gameState;
  GameState _prevGameState;
  sf::RenderWindow _mainWindow;


};

