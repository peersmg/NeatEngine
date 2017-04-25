#include "OutputLogSettings.h"
#include "Game.h"
#include "OutputLog.h"

#include "CMyButton.h"

OutputLogSettings::OutputLogSettings()
{
  if (OutputLog::GetInstance().isShowingMessages())
  {
    m_button = new CMyButton(this, "ShowMessages", "Hide Messages", sf::FloatRect(0, 0, 200, 50), "DefaultStyle");
  }
  else
  {
    m_button = new CMyButton(this, "ShowMessages", "Show Messages", sf::FloatRect(0, 0, 200, 50), "DefaultStyle");
  }

  AddComponent(m_button);
}

OutputLogSettings::~OutputLogSettings()
{
}

void OutputLogSettings::Update(float deltaTime)
{

}

void OutputLogSettings::ButtonPressed(std::string buttonId)
{
  if (OutputLog::GetInstance().isShowingMessages())
  {
    m_button->SetText("Show Messages");
    OutputLog::GetInstance().ShowMessages(false);
  }
  else
  {
    m_button->SetText("Hide Messages");
    OutputLog::GetInstance().ShowMessages(true);
  }
}