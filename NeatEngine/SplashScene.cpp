#include "stdafx.h"
#include "SplashScene.h"
#include "SplashScreen.h"
#include "OutputLog.h"
#include "Game.h"

SplashScene::SplashScene()
{
}

SplashScene::~SplashScene()
{
}

void SplashScene::LoadScene()
{
  OutputLog log;
  log.Output("Loading scene...", OutputLog::MessageType::MESSAGE);

  AddObject(new SplashScreen());
}
