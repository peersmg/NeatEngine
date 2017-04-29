#pragma once
#include "stdafx.h"

class GameObject;

class Component
{
protected:
  GameObject* m_pOwner;         // Object that this component belongs too
  bool m_visible;               // Is the component visible
  bool m_dormant;               // Should the component be updated or drawn

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

  /**
  * Set if the component is dormant.
  *
  * @param dormant - Should the component be dormant.
  */
  void SetDormant(bool dormant);

  /**
  * Get if the component is dormant or not.
  *
  * @return If the component is dormant
  */
  bool GetDormant();
};