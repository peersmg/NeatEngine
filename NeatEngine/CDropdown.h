#pragma once
#include "Component.h"

class GameObject;
class CDropdown : public Component
{
private:
  std::vector<std::string> m_options;
  std::string m_selectedOption;
  sf::Vector2f m_position;
  float m_width;
  float m_height;
  
  int m_optionHovered;
  bool m_selected;

  int m_fontSize;
  DropdownStyle m_style;

public:
  CDropdown(GameObject* pOwner, std::vector<std::string> options, sf::Vector2f position, int width, std::string style, int fontSize, int defaultOption = 0, alignment alignment = alignment::TOPLEFT);
  ~CDropdown();

  void Update(float deltaTime) override;
  void Draw() override;

  std::string GetSelectedOption();
  void SetSelectedOption(std::string theOption);
};

