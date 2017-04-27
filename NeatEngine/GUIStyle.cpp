#include "stdafx.h"
#include "GUIStyle.h"
#include "ResourceLoader.h"
#include "OutputLog.h"

GUIStyle::GUIStyle()
{
}


GUIStyle::~GUIStyle()
{
}

void GUIStyle::LoadAll()
{
  /////// Default style here
  OutputLog::GetInstance().AddLine("Loading default style....", MessageType::MESSAGE);

  // Text Style
  m_textStyle.color = sf::Color::Black;

  if (ResourceLoader::GetInstance().isFontLoaded("fonts/SquaresBold.otf"))
  {
    m_textStyle.font = ResourceLoader::GetInstance().GetFont("fonts/SquaresBold.otf");
  }
  else
  {
    OutputLog::GetInstance().AddLine("Font not loaded", MessageType::ERROR);
  }

  // Button Style

  m_buttonStyle.useImg = false;
  m_buttonStyle.normalBackgroundCol = sf::Color(100, 0, 0);
  m_buttonStyle.hoverBackgroundCol = sf::Color(200, 0, 0);
  m_buttonStyle.downBackgroundCol = sf::Color(50, 0, 0);
  m_buttonStyle.normalTextCol = sf::Color::Black;
  m_buttonStyle.hoverTextCol = m_buttonStyle.normalTextCol;
  m_buttonStyle.downTextCol = m_buttonStyle.normalTextCol;
  m_buttonStyle.outlineColor = sf::Color::Black;
  m_buttonStyle.outlineSize = 3;

  if (ResourceLoader::GetInstance().isFontLoaded("fonts/SquaresBold.otf"))
  {
    m_buttonStyle.font = ResourceLoader::GetInstance().GetFont("fonts/SquaresBold.otf");
  }
  else
  {
    OutputLog::GetInstance().AddLine("Font not loaded", MessageType::ERROR);
  }

  // Textbox Style
  m_textfieldStyle.useImg = false;
  m_textfieldStyle.backgroundCol = sf::Color(200, 200, 200);
  m_textfieldStyle.normalOutlineCol = sf::Color(50, 50, 50);
  m_textfieldStyle.focusOutlineCol = sf::Color(100, 100, 100);
  m_textfieldStyle.placeholderTextCol = sf::Color(50, 50, 50);
  m_textfieldStyle.normalTextCol = sf::Color::Black;

  m_textfieldStyle.outlineSize = 2;

  if (ResourceLoader::GetInstance().isFontLoaded("fonts/lucon.ttf"))
  {
    m_textfieldStyle.font = ResourceLoader::GetInstance().GetFont("fonts/lucon.ttf");
  }
  else
  {
    OutputLog::GetInstance().AddLine("Font not loaded", MessageType::ERROR);
  }
}

TextStyle GUIStyle::GetTextStyle()
{
  return m_textStyle;
}

ButtonStyle GUIStyle::GetButtonStyle()
{
  return m_buttonStyle;
}
TextfieldStyle GUIStyle::GetTextfieldStyle()
{
  return m_textfieldStyle;
}