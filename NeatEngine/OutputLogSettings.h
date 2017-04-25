#pragma once
#include "GameObject.h"

class CMyButton;
class OutputLogSettings : public GameObject
{
private:
  CMyButton* m_button;
  bool m_showingMessages;

public:
  OutputLogSettings();
  ~OutputLogSettings();

  void Update(float deltaTime) override;
  void ButtonPressed(std::string buttonId) override;
};

