#include "CDropdown.h"
#include "DrawManager.h"
#include "OutputLog.h"
#include "ResourceLoader.h"
#include "InputManager.h"

CDropdown::CDropdown(GameObject* pOwner, std::vector<std::string> options, sf::Vector2f position, int width, std::string style, int fontSize, int defaultOption, alignment alignment)
{
  m_options = options;
  m_selectedOption = m_options[defaultOption];
  m_width = width;
  m_fontSize = fontSize;
  m_selected = false;

  m_style = ResourceLoader::GetInstance().GetStyle(style).GetDropdownStyle();

  m_height = m_style.font.getLineSpacing(m_fontSize) + (m_style.font.getLineSpacing(m_fontSize)*0.2);

  m_position = DrawManager::GetInstance().AlignPosition(sf::FloatRect(position.x, position.y, m_width, m_height), alignment);
}

CDropdown::~CDropdown()
{
}

void CDropdown::Update(float deltaTime) 
{

  m_optionHovered = -2;

  if (InputManager::GetInstance()->MouseOver(sf::FloatRect(m_position.x, m_position.y, m_width, m_height)))
  {
    m_optionHovered = -1;
  }
  else if (m_selected)
  {
    for (int i = 0; i < m_options.size(); i++)
    {
      // Check mouse over
      if (InputManager::GetInstance()->MouseOver(sf::FloatRect(m_position.x, m_position.y + m_height + (m_height*i), m_width, m_height)) && InputManager::GetInstance()->ButtonClicked(sf::Mouse::Left))
      {
        m_selected = false;
        m_selectedOption = m_options[i];
      }
      else if (InputManager::GetInstance()->MouseOver(sf::FloatRect(m_position.x, m_position.y + m_height + (m_height*i), m_width, m_height)))
      {
        m_optionHovered = i;
      }
    }
  }

  if (m_optionHovered == -1 && InputManager::GetInstance()->ButtonPressed(sf::Mouse::Left))
  {
    m_selected = !m_selected;
  }
}

void CDropdown::Draw()
{
  // Draw box with currently selected option
  if (m_optionHovered == -1)
  {
    DrawManager::GetInstance().DrawRect(sf::FloatRect(m_position, sf::Vector2f(m_width, m_height)), m_style.hoverCol, m_style.outlineSize, m_style.outlineCol);
  }
  else
  {
    DrawManager::GetInstance().DrawRect(sf::FloatRect(m_position, sf::Vector2f(m_width, m_height)), m_style.backgroundCol, m_style.outlineSize, m_style.outlineCol);
  }
  
  if (m_selected)
  {
    DrawManager::GetInstance().DrawRect(sf::FloatRect(sf::Vector2f(m_position.x, m_position.y + m_style.outlineSize + m_height), sf::Vector2f(m_width, (m_height*m_options.size()))),
      m_style.backgroundCol, m_style.outlineSize, m_style.outlineCol);

    if (m_optionHovered >= 0)
    {
      DrawManager::GetInstance().DrawRect(sf::FloatRect(sf::Vector2f(m_position.x, m_position.y + m_style.outlineSize + m_height + (m_height*m_optionHovered)), sf::Vector2f(m_width, m_height)),
        m_style.hoverCol);
    }

    for (int i = 0; i < m_options.size(); i++)
    {
      if (m_options[i] == m_selectedOption)
      {
        DrawManager::GetInstance().DrawRect(sf::FloatRect(sf::Vector2f(m_position.x, m_position.y + m_style.outlineSize + m_height + (m_height*i)), sf::Vector2f(m_width, m_height)),
          m_style.selectedCol);
      }

      DrawManager::GetInstance().DrawText(m_options[i], sf::Vector2f(m_position.x + m_width / 2, m_position.y + m_height + (m_height*i)), m_fontSize, m_style.font, m_style.textCol, alignment::TOPCENTER);
    }
  }

  DrawManager::GetInstance().DrawText(m_selectedOption, sf::Vector2f(m_position.x + m_width / 2, m_position.y), m_fontSize, m_style.font, m_style.textCol, alignment::TOPCENTER);
}

std::string CDropdown::GetSelectedOption()
{
  return m_selectedOption;
}

void CDropdown::SetSelectedOption(std::string theOption)
{
  bool optionValid = false;

  for (std::string option : m_options)
  {
    if (option == theOption)
    {
      optionValid = true;
      m_selectedOption = theOption;
    }
  }

  if (optionValid == false)
  {
    OutputLog::GetInstance().AddLine("Option \"" + theOption + "\" not valid!", MessageType::ERROR);
  }
}