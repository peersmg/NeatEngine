#include "CTextfield.h"
#include "ResourceLoader.h"
#include "DrawManager.h"
#include "InputManager.h"

#include "OutputLog.h"

CTextfield::CTextfield(GameObject* pOwner, sf::Vector2f position, int width, int lines, std::string defaultText, std::string style, int fontSize, int charLimit, alignment alignment, int camera)
{
  m_pOwner = pOwner;
  m_hasFocus = false;

  m_text = "";
  m_defaultText = defaultText;

  m_alignment = alignment;
  m_lineLimit = lines-1;
  m_lines = 0;
  m_style = ResourceLoader::GetInstance().GetStyle(style).GetTextfieldStyle();

  sf::Text text = sf::Text("XX", m_style.font, fontSize);
  m_fontSize = fontSize;

  float height = (m_style.font.getLineSpacing(m_fontSize)*(lines)) + m_style.font.getLineSpacing(m_fontSize)*0.2;

  sf::Vector2f newPosition = DrawManager::GetInstance().AlignPosition(sf::FloatRect(position.x, position.y, width, height), m_alignment);

  m_rect = sf::FloatRect(newPosition.x, newPosition.y, width, height);

  m_charLimit = charLimit;

  m_characterLineCount.push_back(0);

  m_backspaceTimer = 0;
  m_caratBlinkSpeed = 1.6;
  m_prevLinesCount = 0;

  m_caratCharacterPosition = m_text.size();
}


CTextfield::~CTextfield()
{
}

void CTextfield::Update(float deltaTime)
{
  if (m_backspaceTimer > 0)
  {
    m_backspaceTimer -= deltaTime;
  }

  if (m_caratBlinkSpeed > 0)
  {
    m_caratBlinkSpeed -= deltaTime;
  }
  else if (m_caratBlinkSpeed <= 0)
  {
    m_caratBlinkSpeed = 1.6;
  }

  if (InputManager::GetInstance()->MouseOver(m_rect) && InputManager::GetInstance()->ButtonDown(sf::Mouse::Left))
  {
    m_hasFocus = true;
    m_caratBlinkSpeed = 0.53;
  }
  else if (!InputManager::GetInstance()->MouseOver(m_rect) && InputManager::GetInstance()->ButtonDown(sf::Mouse::Left))
  {
    m_hasFocus = false;
  }

  m_characterLineCount[m_lines] = m_text.size() - m_prevLinesCount;

  CheckBackspace();

  CheckTextInput();
}

void CTextfield::Draw()
{
  if (m_hasFocus)
  {
    DrawManager::GetInstance().DrawRect(m_rect, m_style.backgroundCol, m_style.outlineSize, m_style.focusOutlineCol);
  }
  else
  {
    DrawManager::GetInstance().DrawRect(m_rect, m_style.backgroundCol, m_style.outlineSize, m_style.normalOutlineCol);
  }

  if (m_text == "" && !m_hasFocus)
  {
    // Draw default text
    DrawManager::GetInstance().DrawText(m_defaultText, sf::Vector2f(m_rect.left, m_rect.top), m_fontSize, m_style.font, m_style.placeholderTextCol);
  }
  else if (m_text != "" && !m_hasFocus)
  {
    // Draw m_text
    DrawManager::GetInstance().DrawText(m_text, sf::Vector2f(m_rect.left, m_rect.top), m_fontSize, m_style.font, m_style.placeholderTextCol);
  }
  else
  {
    // Draw m_text with blinking carat at endn(or clicked point)
    DrawManager::GetInstance().DrawText(m_text, sf::Vector2f(m_rect.left, m_rect.top), m_fontSize, m_style.font, m_style.placeholderTextCol);
    
    sf::Text theText = sf::Text(m_text.substr(m_prevLinesCount, m_caratCharacterPosition), m_style.font, m_fontSize);

    m_caratVectorPosition = sf::Vector2f(m_rect.left + theText.getGlobalBounds().width - (m_style.font.getGlyph(65, m_fontSize, false).bounds.width / 2), m_rect.top + (m_style.font.getLineSpacing(m_fontSize)*m_lines));

    if (m_caratBlinkSpeed <= 0.53)
    {
      DrawManager::GetInstance().DrawText("|", m_caratVectorPosition, m_fontSize, m_style.font, sf::Color(100, 100, 100));
    }
  }
}

std::string CTextfield::GetText()
{
  return m_text;
}

void CTextfield::CheckBackspace()
{
  if (InputManager::GetInstance()->KeyDown(sf::Keyboard::BackSpace) && m_text.size() > 0 && m_backspaceTimer <= 0)
  {
    m_backspaceTimer = 0.1;

    m_caratBlinkSpeed = 0.53;

    m_text.pop_back();

    if (m_text.size() < m_prevLinesCount && m_lines != 0)
    {
      m_prevLinesCount = m_prevLinesCount - m_characterLineCount[m_lines];
      m_lines--;
    }
    
    if (m_lines == 0)
    {
      m_prevLinesCount = 0;
    }
  }
}

void CTextfield::CheckTextInput()
{
  if (m_charLimit != 0)
  {
    if (m_hasFocus && m_text.size() < m_charLimit)
    {
      sf::Text theText = sf::Text(m_text + InputManager::GetInstance()->GetTextEntered(), m_style.font, m_fontSize);

      if (theText.getGlobalBounds().width < m_rect.width)
      {
        m_text = m_text + InputManager::GetInstance()->GetTextEntered();
        m_caratCharacterPosition = m_caratCharacterPosition + 1;

        if (InputManager::GetInstance()->GetTextEntered() != "")
        {
          m_caratBlinkSpeed = 0.53;
        }
      }
      else if (m_lines < m_lineLimit)
      {
        m_characterLineCount.push_back(0);
        m_prevLinesCount = m_text.size();
        m_lines++;
        m_text = m_text + "\n";

        m_text = m_text + InputManager::GetInstance()->GetTextEntered();
        m_caratCharacterPosition = 1;

        if (InputManager::GetInstance()->GetTextEntered() != "")
        {
          m_caratBlinkSpeed = 0.53;
        }
      }
    }
  }
  else
  {
    sf::Text theText = sf::Text(m_text + InputManager::GetInstance()->GetTextEntered(), m_style.font, m_fontSize);

    if (theText.getGlobalBounds().width < m_rect.width)
    {
      m_text = m_text + InputManager::GetInstance()->GetTextEntered();
      m_caratCharacterPosition = m_caratCharacterPosition + 1;

      if (InputManager::GetInstance()->GetTextEntered() != "")
      {
        m_caratBlinkSpeed = 0.53;
      }
    }
    else if (m_lines < m_lineLimit)
    {
      m_characterLineCount.push_back(0);
      m_prevLinesCount = m_text.size();
      m_lines++;
      m_text = m_text + "\n";

      m_text = m_text + InputManager::GetInstance()->GetTextEntered();
      m_caratCharacterPosition = 1;

      if (InputManager::GetInstance()->GetTextEntered() != "")
      {
        m_caratBlinkSpeed = 0.53;
      }
    }
  }
}