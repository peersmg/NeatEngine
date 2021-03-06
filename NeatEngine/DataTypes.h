#pragma once
#include <map>
#include <string>
#include "Transform.h"

// Alignment enum used for text
enum class alignment { TOPLEFT, TOPRIGHT, TOPCENTER, MIDDLELEFT, MIDDLERIGHT, MIDDLECENTER, BOTTOMLEFT, BOTTOMRIGHT, BOTTOMCENTER };

// Main enum for game state
enum class GameState { Uninitialized, Playing, Exiting };

// Types of shape
enum class Shape { RECTANGLE, CIRCLE };

// Debug
enum class MessageType { MESSAGE, ERROR, FATAL_ERROR };

struct OutputInfo
{
  MessageType type;
  std::string text;
  std::string time;
};

struct InitialisationData
{
  std::string scene = "";
  Transform transform;
  std::map<std::string, std::string> data;
};

class GameObject;

struct Event
{
  GameObject* pSource;
  std::string type;
  float data1;
  float data2;
};

// GUI

struct TextStyle
{
  sf::Color color;
  sf::Font font;
};

struct ButtonStyle
{
  bool useImg;

  sf::Texture normalBackgroundImg;
  sf::Texture hoverBackgroundImg;
  sf::Texture downBackgroundImg;

  sf::Color normalBackgroundCol;
  sf::Color hoverBackgroundCol;
  sf::Color downBackgroundCol;

  sf::Color normalTextCol;
  sf::Color hoverTextCol;
  sf::Color downTextCol;

  sf::Font font;

  int outlineSize;
  sf::Color outlineColor;
};

struct TextfieldStyle
{
  sf::Color backgroundCol;

  sf::Font font;

  int outlineSize;
  sf::Color normalOutlineCol;
  sf::Color focusOutlineCol;

  sf::Color placeholderTextCol;
  sf::Color normalTextCol;
};

struct DropdownStyle
{
  sf::Color backgroundCol;
  sf::Color hoverCol;
  sf::Color selectedCol;

  sf::Font font;

  int outlineSize;
  sf::Color outlineCol;

  sf::Color textCol;
};