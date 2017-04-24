#pragma once

#include "stdafx.h"
#include "Window.h"

class OutputLog
{
private:
  OutputLog();
  ~OutputLog();

  Window* m_window;
  std::vector<OutputInfo> m_log;
  sf::Font m_font;

public:
  static OutputLog& GetInstance()
  {
    static OutputLog instance;
    return instance;
  }

  void Initialise();

  void AddLine(std::string text, MessageType type = MessageType::MESSAGE);

  void Draw();
};