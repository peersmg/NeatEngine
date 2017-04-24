#include "stdafx.h"
#include "SSplash.h"
#include "SplashScreen.h"
#include "OutputLog.h"
#include "Game.h"
#include "DefaultCamera.h"

SSplash::SSplash()
{
}

SSplash::~SSplash()
{
}

void SSplash::LoadScene()
{
  OutputLog::GetInstance().AddLine("Loading scene...", MessageType::MESSAGE);

  AddObject(new SplashScreen());
  
}
