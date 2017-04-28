#pragma once
#include "stdafx.h"
#include "DataTypes.h"

class InputManager
{
private:
  enum class ButtonState{ NONE, PRESSED, DOWN, RELEASED };

  std::vector<sf::Event> m_events;        // Vector of current events
  std::vector<sf::Event> m_prevEvents;    // Vector of events from previous check

  std::map<sf::Keyboard::Key, ButtonState> m_keyState;
  std::map<sf::Mouse::Button, ButtonState> m_mouseState;
  std::map<std::string, std::vector<sf::Keyboard::Key>> m_actionMap;
  sf::Vector2i m_mousePosition;           // Position of the mouse
  static InputManager *m_pInstance;       // Pointer to the InputManager instance

  std::string m_textEntered;
  float m_mouseWheelDelta;

public:
  InputManager();
  ~InputManager();
  
  // Poll events and add them to m_events
  void Update();

  // Return a pointer to an instance of the InputManager
  static InputManager* GetInstance();

  void SampleKeyboard();

  void ClearKeyStates();

  void AddAction(std::string action, sf::Keyboard::Key key);

  // Return a vector of the events
  std::vector<sf::Event> GetEvents();

  // Return the mouse position
  sf::Vector2i GetMousePosition();

  // Returns true if the mouse is over the specified rect
  bool MouseOver(sf::FloatRect Rect);

  // Returns true if the mouse button has been pressed
  bool ButtonPressed(sf::Mouse::Button button);

  // Returns true if the mouse button is down
  bool ButtonDown(sf::Mouse::Button button);

  // Returns true if the mouse button is down
  bool ButtonReleased(sf::Mouse::Button button);

  // Returns true if the key has been pressed
  bool KeyPressed(sf::Keyboard::Key Key);

  // Returns true if a key in an action has been pressed
  bool KeyPressed(std::string action);

  // Returns true if the key is being held down
  bool KeyDown(sf::Keyboard::Key Key);

  // Returns true if a key in an action is being held down
  bool KeyDown(std::string action);

  // Returns true if the key has just been released
  bool KeyUp(sf::Keyboard::Key Key);

  // Returns true if a key in an action has just been released
  bool KeyUp(std::string action);

  // Returns entered text
  std::string GetTextEntered();

  // Returns wheel delta
  float GetMouseWheelDelta();
};