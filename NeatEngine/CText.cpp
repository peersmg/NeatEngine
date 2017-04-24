#include "stdafx.h"
#include "CText.h"
#include "Game.h"
#include "ResourceLoader.h"

#include "OutputLog.h"

CText::CText(GameObject* pOwner, std::string text, sf::Vector2f position, int fontSize, std::string font, sf::Color Color, alignment alignment)
{
  if (ResourceLoader::GetInstance().isFontLoaded(font))
  {
    m_font = ResourceLoader::GetInstance().GetFont(font);
  }
  else
  {
    OutputLog::GetInstance().AddLine("Font not loaded", MessageType::FATAL_ERROR);
  }

  m_pOwner = pOwner;

  m_textValue = text;
  m_position = position;
  m_fontSize = fontSize;
  m_color = Color;
  m_alignment = alignment;

  m_text = sf::Text(m_textValue, m_font);
  m_text.setColor(m_color);
  m_text.setCharacterSize(m_fontSize);

  SetPosition(m_position);
}

CText::CText(GameObject* pOwner, std::string text, sf::Vector2f position, std::string style, int fontSize, alignment alignment)
{
  TextStyle textStyle = ResourceLoader::GetInstance().GetStyle(style).GetTextStyle();

  m_font = textStyle.font;

  m_pOwner = pOwner;

  m_textValue = text;
  m_position = position;
  m_fontSize = fontSize;
  m_color = textStyle.color;
  m_alignment = alignment;

  m_text = sf::Text(m_textValue, m_font);
  m_text.setColor(m_color);
  m_text.setCharacterSize(m_fontSize);

  SetPosition(m_position);
}

CText::~CText()
{
}

void CText::Draw()
{
  Game::instance.GetWindow()->Draw(m_text);
}

void CText::SetText(std::string newText)
{
  m_textValue = newText;
  m_text = sf::Text(m_textValue, m_font);
}

void CText::SetPosition(sf::Vector2f newPosition)
{
  m_position = newPosition;

  // Set the position of the text based on the alignment
  switch (m_alignment)
  {
  case alignment::TOPLEFT:
    m_text.setPosition(sf::Vector2f(m_position.x, m_position.y));
    break;
  case alignment::TOPRIGHT:
    m_text.setPosition(sf::Vector2f(m_position.x - m_text.getGlobalBounds().width, m_position.y));
    break;
  case alignment::TOPCENTER:
    m_text.setPosition(sf::Vector2f(m_position.x - (m_text.getGlobalBounds().width / 2), m_position.y));
    break;
  case alignment::MIDDLELEFT:
    m_text.setPosition(sf::Vector2f(m_position.x, m_position.y - (m_text.getGlobalBounds().height / 2)));
    break;
  case alignment::MIDDLERIGHT:
    m_text.setPosition(sf::Vector2f(m_position.x - m_text.getGlobalBounds().width, m_position.y - (m_text.getGlobalBounds().height / 2)));
    break;
  case alignment::MIDDLECENTER:
    m_text.setPosition(sf::Vector2f(m_position.x - m_text.getGlobalBounds().width / 2, m_position.y - (m_text.getGlobalBounds().height / 2)));
    break;
  case alignment::BOTTOMLEFT:
    m_text.setPosition(sf::Vector2f(m_position.x, m_position.y - (m_text.getGlobalBounds().height)));
    break;
  case alignment::BOTTOMRIGHT:
    m_text.setPosition(sf::Vector2f(m_position.x - m_text.getGlobalBounds().width, m_position.y - (m_text.getGlobalBounds().height)));
    break;
  case alignment::BOTTOMCENTER:
    m_text.setPosition(sf::Vector2f(m_position.x - (m_text.getGlobalBounds().width / 2), m_position.y - (m_text.getGlobalBounds().height)));
    break;
  default:
    break;
  }
}