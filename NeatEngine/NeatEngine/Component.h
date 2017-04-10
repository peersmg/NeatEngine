#pragma once
#include "stdafx.h"

class GameObject;

class Component
{
protected:
  GameObject* m_pOwner;

public:
  Component();
  virtual ~Component();

  virtual void Update(float deltatime) {  /* Implimentation Optional */ };
  virtual void Draw() {  /* Implimentation Optional */ };
};