#pragma once

#include "stdafx.h"
#include "Window.h"
#include <fstream>

class OutputLog
{
private:
  OutputLog();
  ~OutputLog();

  Window* m_window;
  std::vector<OutputInfo> m_log;
  std::vector<OutputInfo> m_errorLog;
  sf::Font m_font;
  bool m_showMessages;
  sf::Clock m_clock;
  sf::Clock m_fpsClock;
  float m_fps;

  std::ofstream m_logFile;

  float m_textHeight;
public:
  static OutputLog& GetInstance()
  {
    static OutputLog instance;
    return instance;
  }

  void Initialise();

  void AddLine(std::string text, MessageType type = MessageType::MESSAGE);

  void Draw();

  Window* GetWindow();
  void CloseWindow();

  bool isShowingMessages();
  void ShowMessages(bool showMessages);

  void PrintLog(std::vector<OutputInfo> &log);

  sf::String GetFormatTime();
};