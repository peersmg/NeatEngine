#include "stdafx.h"
#include "DefaultCamera.h"
#include "CCamera.h"
#include "Game.h"

DefaultCamera::DefaultCamera(Window *window)
{
  AddComponent(new CCamera(this, window->GetSize()));
}

DefaultCamera::~DefaultCamera()
{
}