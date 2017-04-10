#pragma once
#include "stdafx.h"
#include "GameObject.h"

#include "Transform.h"

class SplashScreen : public GameObject
{
private:
public:
  SplashScreen();
  ~SplashScreen();

  void Update(float deltaTime) override;
};

