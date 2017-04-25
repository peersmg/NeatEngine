#pragma once
#include "GameObject.h"

class CCamera;
class Window;
class DefaultCamera : public GameObject
{

public:
  DefaultCamera(Window *window);
  ~DefaultCamera();
};

