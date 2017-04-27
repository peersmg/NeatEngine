#pragma once
#include "stdafx.h"

class GameObject;

class Component
{
protected:
  GameObject* m_pOwner;   // Object that this component belongs too
  bool m_visible;                         // Is the component visible
  
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

  /**
  * Set the visibility of the component.
  *
  * @param visible - The new visibility of the component.
  */
  void SetVisible(bool visible);

  /**
  * Get if the component is visible or not.
  *
  * @return If the component is visible
  */
  bool GetVisible();
};