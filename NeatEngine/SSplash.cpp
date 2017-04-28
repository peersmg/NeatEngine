#include "stdafx.h"
#include "SSplash.h"
#include "OutputLog.h"
#include "Game.h"
#include "DefaultCamera.h"
#include "ObjectFactory.h"

SSplash::SSplash()
{
}

SSplash::~SSplash()
{
}

void SSplash::LoadScene()
{
  OutputLog::GetInstance().AddLine("Loading scene...", MessageType::MESSAGE);

  InitialisationData splashData;
  ObjectFactory::GetInstance().Spawn("SplashScreen", splashData);
  
}
