#pragma once

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
  bool useImg;

  sf::Color backgroundCol;

  sf::Font font;

  int outlineSize;
  sf::Color normalOutlineCol;
  sf::Color focusOutlineCol;

  sf::Color placeholderTextCol;
  sf::Color normalTextCol;
};