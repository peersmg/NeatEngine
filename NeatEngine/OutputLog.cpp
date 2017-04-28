#include "stdafx.h"
#include "OutputLog.h"
#include "ResourceLoader.h"
#include "DefaultCamera.h"
#include "Game.h"
#include "DrawManager.h"

#include "Component.h"
#include <math.h>

OutputLog::OutputLog()
{
  m_window = nullptr;
  m_font.loadFromFile("fonts/lucon.ttf");

  m_showMessages = true;
}

OutputLog::~OutputLog()
{
  m_logFile.close();
  delete m_window;
}

void OutputLog::Initialise()
{
  m_window = new Window("Output Log", sf::Vector2i(1000, 400), false, sf::Color(50, 50, 50));
  m_logFile.open("OutputLog.txt");

  m_clock.restart();

  sf::Text text = sf::Text("H", m_font);
  text.setCharacterSize(14);

  m_textHeight = text.getGlobalBounds().height;
}

void OutputLog::AddLine(std::string text, MessageType type)
{
#ifndef NDEBUG
    OutputInfo info;

    info.time = GetFormatTime();
    info.text = text;
    info.type = type;
    m_log.push_back(info);

    if (info.type != MessageType::MESSAGE)
    {
      m_errorLog.push_back(info);
    }

    switch (type)
    {
    case MessageType::MESSAGE:
      text = "[" + info.time + "]\tMessage: " + text;
      break;
    case MessageType::ERROR:
      text = "[" + info.time + "]\tERROR: " + text;
      break;
    case MessageType::FATAL_ERROR:
      text = "[" + info.time + "]\tFATAL ERROR: " + text;
      break;
    default:
      break;
    }

    m_logFile << text << "\n";
#endif
}

Window* OutputLog::GetWindow()
{
  return m_window;
}

void OutputLog::CloseWindow()
{
  delete m_window;
  m_window = nullptr;
}

void OutputLog::Draw()
{
  if (m_window != nullptr)
  {
    m_window->Update();
    
    if (m_showMessages)
    {
      PrintLog(m_log);
    }
    else
    {
      PrintLog(m_errorLog);
    }

    m_window->Display();
  }
  
}

void OutputLog::PrintLog(std::vector<OutputInfo> &log)
{
  for (int i = 0; i < log.size(); i++)
  {
    int num = log.size() - i - 1;

    sf::Text text = sf::Text(log[num].text, m_font);
    sf::Text numText = sf::Text(log[num].time, m_font);
    text.setCharacterSize(14);
    numText.setCharacterSize(14);

    switch (log[num].type)
    {
    case MessageType::MESSAGE:
      text.setColor(sf::Color::White);
      break;
    case MessageType::ERROR:
      text.setColor(sf::Color(255, 140, 0));
      break;
    case MessageType::FATAL_ERROR:
      text.setColor(sf::Color(255, 69, 0));
      break;
    default:
      break;
    }

    numText.setString("[" + log[num].time + "]");

    numText.setColor(sf::Color::White);

    sf::Vector2f position = sf::Vector2f(0, m_window->GetSize().y - (m_textHeight * 2 * (i+1)));

    text.setPosition(sf::Vector2f(position.x + numText.getGlobalBounds().width + 50, position.y));

    numText.setPosition(sf::Vector2f(position.x, position.y));

    m_window->Draw(numText);
    m_window->Draw(text);

    if (i >= 100)
    {
      break;
    }
  }
}

bool OutputLog::isShowingMessages()
{
  return m_showMessages;
}

void OutputLog::ShowMessages(bool showMessages)
{
  m_showMessages = showMessages;
}

sf::String OutputLog::GetFormatTime()
{
  sf::String hourS;
  sf::String minsS;
  sf::String secsS;

  float hour = m_clock.getElapsedTime().asSeconds() / 60 / 60;
  hour = std::trunc(hour);

  float mins = int(m_clock.getElapsedTime().asSeconds()/60) % 60;
  mins = std::trunc(mins);

  float secs = int(m_clock.getElapsedTime().asSeconds()) % 60;

  if (hour > 9)
  {
    hourS = std::to_string((int)hour);
  }
  else
  {
    hourS = "0" + std::to_string((int)hour);
  }

  if (mins > 9)
  {
    minsS = std::to_string((int)mins);
  }
  else
  {
    minsS = "0" + std::to_string((int)mins);
  }

  if (secs > 9)
  {
    secsS = std::to_string((int)secs);
  }
  else
  {
    secsS = "0" + std::to_string((int)secs);
  }

  return hourS + ":" + minsS + ":" + secsS;
}