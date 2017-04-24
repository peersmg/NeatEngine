#include "stdafx.h"
#include "DefaultCamera.h"
#include "CCamera.h"
#include "Game.h"

DefaultCamera::DefaultCamera()
{
  AddComponent(new CCamera(this, Game::instance.GetWindow()->GetSize()));
}

DefaultCamera::~DefaultCamera()
{
}