#pragma once
#include "stdafx.h"
#include "GameObject.h"

#include "Transform.h"

class CAudio;
class CDropdown;
class CTextfield;
class CMyButton;

class SplashScreen : public GameObject
{
private:
  CAudio* m_buttonSound;
  CDropdown* m_settingsDropdown;
  CTextfield* m_nameTextfield;
  CMyButton* m_button;

  bool m_started = false;

public:
  SplashScreen();
  ~SplashScreen();

  void Update(float deltaTime) override;
  void ButtonPressed(std::string buttonId) override;
};

