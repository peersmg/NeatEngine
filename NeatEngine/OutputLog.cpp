#include "stdafx.h"
#include "OutputLog.h"
#include "ResourceLoader.h"
#include "DefaultCamera.h"
#include "Game.h"
#include <iostream>

OutputLog::OutputLog()
{
  m_window = nullptr;
  m_font.loadFromFile("fonts/lucon.ttf");
}

OutputLog::~OutputLog()
{
  delete m_window;
}

void OutputLog::Initialise()
{
  m_window = new Window("Output Log", sf::Vector2i(1000, 400), false, sf::Color(50, 50, 50));
}

void OutputLog::AddLine(std::string text, MessageType type)
{
#ifndef NDEBUG
  OutputInfo info;
  info.text = text;
  info.type = type;
  m_log.push_back(info);
#endif
}

void OutputLog::Draw()
{
  if (m_window != nullptr)
  {
    m_window->Update();
    
    if (m_log.size() > 100)
    {
      for (int i = 0; i < 100; i++)
      {
        int num = m_log.size() - i - 1;

        sf::Text text = sf::Text("XX", m_font);
        sf::Text numText = sf::Text("XX", m_font);
        text.setCharacterSize(14);
        numText.setCharacterSize(14);

        switch (m_log[num].type)
        {
        case MessageType::MESSAGE:
          text.setColor(sf::Color::White);
          text.setString("Message: " + m_log[num].text);
          break;
        case MessageType::ERROR:
          text.setColor(sf::Color(255, 140, 0));
          text.setString("ERROR: " + m_log[num].text);
          break;
        case MessageType::FATAL_ERROR:
          text.setColor(sf::Color(255, 69, 0));
          text.setString("FATAL ERROR: " + m_log[num].text);
          break;
        default:
          break;
        }

        numText.setString("[" + std::to_string(num) + "]");

        numText.setColor(sf::Color::White);

        sf::Vector2f position = sf::Vector2f(0, m_window->GetSize().y - (text.getGlobalBounds().height * 1.2 * i));

        text.setPosition(sf::Vector2f(position.x + 100, position.y - (text.getGlobalBounds().height * 2)));

        numText.setPosition(sf::Vector2f(position.x, position.y - (text.getGlobalBounds().height * 2)));

        m_window->Draw(numText);
        m_window->Draw(text);
      }
    }
    else
    {
      for (int i = 0; i < m_log.size(); i++)
      {
        int num = m_log.size() - i - 1;

        sf::Text text = sf::Text("XX", m_font);
        sf::Text numText = sf::Text("XX", m_font);
        text.setCharacterSize(14);
        numText.setCharacterSize(14);

        switch (m_log[num].type)
        {
        case MessageType::MESSAGE:
          text.setColor(sf::Color::White);
          text.setString("Message: " + m_log[num].text);
          break;
        case MessageType::ERROR:
          text.setColor(sf::Color(255, 140, 0));
          text.setString("ERROR: " + m_log[num].text);
          break;
        case MessageType::FATAL_ERROR:
          text.setColor(sf::Color(255, 69, 0));
          text.setString("FATAL ERROR: " + m_log[num].text);
          break;
        default:
          break;
        }

        numText.setString("[" + std::to_string(num) + "]");

        numText.setColor(sf::Color::White);

        sf::Vector2f position = sf::Vector2f(0, m_window->GetSize().y - (text.getGlobalBounds().height * 1.2 * i));

        text.setPosition(sf::Vector2f(position.x + 100, position.y - (text.getGlobalBounds().height * 2)));

        numText.setPosition(sf::Vector2f(position.x, position.y - (text.getGlobalBounds().height * 2)));

        m_window->Draw(numText);
        m_window->Draw(text);
      }
    }

    m_window->Display();
  }
  
}