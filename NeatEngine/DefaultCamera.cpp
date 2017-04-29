#include "stdafx.h"
#include "DefaultCamera.h"
#include "CCamera.h"
#include "Game.h"
#include "InputManager.h"
#include "ObjectFactory.h"

GameObject* CreateDefaultCamera(InitialisationData data)
{
  DefaultCamera* pTemp = new DefaultCamera();
  return (GameObject*)pTemp;
}

const bool bDefaultCamera = ObjectFactory::GetInstance().Register("DefaultCamera", CreateDefaultCamera);

DefaultCamera::DefaultCamera()
{
  AddComponent(new CCamera(this, Game::instance.GetWindow()->GetSize()));
}

DefaultCamera::~DefaultCamera()
{
}