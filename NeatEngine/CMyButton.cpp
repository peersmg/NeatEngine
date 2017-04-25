#include "CMyButton.h"
#include "ResourceLoader.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Game.h"
#include "OutputLog.h"
#include "Window.h"

CMyButton::CMyButton(GameObject* pOwner, std::string buttonId, std::string text, sf::FloatRect rect, std::string style, int fontSize, alignment alignment, int camera)
{
  m_pOwner = pOwner;
  m_buttonId = buttonId;
  m_textValue = text;
  m_fontSize = fontSize;
  m_camera = camera;
  m_alignment = alignment;
  m_style = ResourceLoader::GetInstance().GetStyle(style).GetButtonStyle();
  m_pressed = false;
  m_window = Game::instance.GetWindow();

  m_rect = rect;
  m_text = sf::Text(m_textValue, m_style.font);
  SetPosition(sf::Vector2f(rect.left, rect.top));
}

CMyButton::CMyButton(GameObject* pOwner, std::string buttonId, std::string text, sf::FloatRect rect, std::string style, Window* window, int fontSize, alignment alignment, int camera)
{
  m_pOwner = pOwner;
  m_buttonId = buttonId;
  m_textValue = text;
  m_fontSize = fontSize;
  m_camera = camera;
  m_alignment = alignment;
  m_style = ResourceLoader::GetInstance().GetStyle(style).GetButtonStyle();
  m_pressed = false;
  m_window = window;

  m_rect = rect;
  m_text = sf::Text(m_textValue, m_style.font);
  SetPosition(sf::Vector2f(rect.left, rect.top));
}

CMyButton::~CMyButton()
{
}

void CMyButton::Update(float deltaTime)
{
  if (m_pressed && m_mouseOver && InputManager::GetInstance()->ButtonReleased(sf::Mouse::Left))
  {
    m_pOwner->ButtonPressed(m_buttonId);
  }

  if (InputManager::GetInstance()->MouseOver(m_rect))
  {
    m_mouseOver = true;
  }
  else
  {
    m_mouseOver = false;
  }

  if (m_mouseOver && InputManager::GetInstance()->ButtonPressed(sf::Mouse::Left))
  {
    m_pressed = true;
  }
  
  if (InputManager::GetInstance()->ButtonReleased(sf::Mouse::Left))
  {
    m_pressed = false;
  }
}

void CMyButton::Draw()
{
  m_rectangleShape.setSize(sf::Vector2f(m_rect.width, m_rect.height));
  m_rectangleShape.setPosition(sf::Vector2f(m_rect.left, m_rect.top));

  if (m_style.useImg == true)
  {
    if (m_pressed && m_mouseOver)
    {
      m_rectangleShape.setTexture(&m_style.downBackgroundImg);
    }
    else if (m_mouseOver)
    {
      m_rectangleShape.setTexture(&m_style.hoverBackgroundImg);
    }
    else
    {
      m_rectangleShape.setTexture(&m_style.normalBackgroundImg);
    }
  }
  else
  {
    if (m_pressed && m_mouseOver)
    {
      m_rectangleShape.setFillColor(m_style.downBackgroundCol);
    }
    else if (m_mouseOver)
    {
      m_rectangleShape.setFillColor(m_style.hoverBackgroundCol);
    }
    else
    {
      m_rectangleShape.setFillColor(m_style.normalBackgroundCol);
    }

    m_rectangleShape.setOutlineColor(m_style.outlineColor);
    m_rectangleShape.setOutlineThickness(m_style.outlineSize);
  }
  
  m_text.setCharacterSize(m_fontSize);
  m_text.setPosition(sf::Vector2f(m_rect.left + (m_rect.width / 2) - (m_text.getGlobalBounds().width / 2), m_rect.top + (m_rect.height / 2) - (m_text.getGlobalBounds().height / 1.2)));

  m_window->Draw(m_rectangleShape);
  m_window->Draw(m_text);
}

void CMyButton::SetText(std::string newText)
{

}

void CMyButton::SetPosition(sf::Vector2f newPosition)
{
  // Set the position of the text based on the alignment
  switch (m_alignment)
  {
  case alignment::TOPLEFT:
    m_rect.left = newPosition.x;
    m_rect.top = newPosition.y;
    break;
  case alignment::TOPRIGHT:
    m_rect.left = newPosition.x - m_rect.width;
    m_rect.top = newPosition.y;
    break;
  case alignment::TOPCENTER:
    m_rect.left = newPosition.x - (m_rect.width/2);
    m_rect.top = newPosition.y;
    break;
  case alignment::MIDDLELEFT:
    m_rect.left = newPosition.x;
    m_rect.top = newPosition.y - (m_rect.height/2);
    break;
  case alignment::MIDDLERIGHT:
    m_rect.left = newPosition.x - m_rect.width;
    m_rect.top = newPosition.y - (m_rect.height / 2);
    break;
  case alignment::MIDDLECENTER:
    m_rect.left = newPosition.x - (m_rect.width / 2);
    m_rect.top = newPosition.y - (m_rect.height / 2);
    break;
  case alignment::BOTTOMLEFT:
    m_rect.left = newPosition.x;
    m_rect.top = newPosition.y - m_rect.height;
    break;
  case alignment::BOTTOMRIGHT:
    m_rect.left = newPosition.x - m_rect.width;
    m_rect.top = newPosition.y - m_rect.height;
    break;
  case alignment::BOTTOMCENTER:
    m_rect.left = newPosition.x - (m_rect.width / 2);
    m_rect.top = newPosition.y - m_rect.height;
    break;
  default:
    break;
  }
}