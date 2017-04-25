#pragma once
#include "Component.h"
#include "GUIStyle.h"

class Window;
class CMyButton : public Component
{
private:
  sf::FloatRect m_rect;
  sf::RectangleShape m_rectangleShape;
  ButtonStyle m_style;
  sf::Text m_text;
  std::string m_textValue;
  int m_fontSize;
  int m_camera;
  alignment m_alignment;
  std::string m_buttonId;
  Window* m_window;

  bool m_mouseOver;
  bool m_pressed;
public:

  CMyButton(GameObject* pOwner, std::string buttonId, std::string text, sf::FloatRect rect, std::string style, int fontSize = 12, alignment alignment = alignment::TOPLEFT, int camera = 0);

  CMyButton(GameObject* pOwner, std::string buttonId, std::string text, sf::FloatRect rect, std::string style, Window* window, int fontSize = 12, alignment alignment = alignment::TOPLEFT, int camera = 0);

  ~CMyButton();

  void Update(float deltaTime) override;
  void Draw() override;

  void SetText(std::string newText);

  void SetPosition(sf::Vector2f newPosition);
};

