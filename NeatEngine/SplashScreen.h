#pragma once
#include "stdafx.h"
#include "GameObject.h"

#include "Transform.h"

class CAudio;

class SplashScreen : public GameObject
{
private:
  CAudio* m_buttonSound;


public:
  SplashScreen();
  ~SplashScreen();

  void Update(float deltaTime) override;
  void ButtonPressed(std::string buttonId) override;
};

