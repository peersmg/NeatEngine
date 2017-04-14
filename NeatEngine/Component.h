#pragma once
#include "stdafx.h"

class GameObject;

class Component
{
protected:
  GameObject* m_pOwner;   // Object that this component belongs too

public:

  /**
  * Constructor.
  */
  Component();

  /**
  * Destructor.
  */
  virtual ~Component();

  /**
  * Update function, called every frame.
  *
  * @param deltaTime - The time between the last frame and the current frame.
  */
  virtual void Update(float deltaTime) {  /* Implimentation Optional */ };

  /**
  * Draw function, called every frame after update.
  */
  virtual void Draw() {  /* Implimentation Optional */ };
};