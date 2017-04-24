#pragma once
#include "Component.h"
#include "GUIStyle.h"

class CText : public Component
{
private:
  sf::String m_textValue;
  sf::Vector2f m_position;
  int m_fontSize;
  sf::Color m_color;
  alignment m_alignment;
  sf::Font m_font;

  sf::Text m_text;

public:
  CText(GameObject* pOwner, std::string text, sf::Vector2f position, int fontSize, std::string font, sf::Color Color, alignment alignment = alignment::TOPLEFT);
  CText(GameObject* pOwner, std::string text, sf::Vector2f position, std::string style, int fontSize = 12, alignment alignment = alignment::TOPLEFT);
  
  ~CText();

  void Draw() override;

  void SetText(std::string newText);

  void SetPosition(sf::Vector2f newPosition);

  sf::FloatRect GetBounds();
};

