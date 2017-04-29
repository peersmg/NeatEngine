#pragma once
#include "Component.h"
class CTextfield : public Component
{
private:
  bool m_hasFocus;

  std::string m_text;
  std::string m_defaultText;

  sf::FloatRect m_rect;
  TextfieldStyle m_style;
  int m_lineLimit;
  int m_lines;

  alignment m_alignment;
  int m_fontSize;

  int m_charLimit;

  std::vector<int> m_characterLineCount;
  int m_prevLinesCount;

  float m_caratBlinkSpeed;
  float m_backspaceTimer;

  sf::Vector2f m_caretVectorPosition;
  int m_caretCharacterPosition;
  int m_caretLine;

public:
  CTextfield(GameObject* pOwner, sf::Vector2f position, int width, int lines, std::string defaultText, std::string style, int fontSize = 12, int charLimit = 0, 
             alignment alignment = alignment::TOPLEFT, int camera = 0);

  ~CTextfield();

  void Update(float deltaTime) override;
  void Draw() override;

  std::string GetText();

  void CheckBackspace();
  void CheckTextInput();
};

