#pragma once
#include "stdafx.h"
#include "Transform.h"

class Component;

class GameObject
{

  friend class SceneManager;

protected:
  Transform m_transform;      // The position of the object
  bool m_active;                // Is the object active
  std::vector<Component*> m_components;

public:
  GameObject();

  virtual ~GameObject();

  std::vector<Component*> GetComponents();

  // Set the position of the gameobject
  void SetTransform(Transform position);

  // Update to be used for basic logic, for more advanced logic create a component
  virtual void Update(float deltaTime) = 0;

  Transform GetTransform();

  void SetActive(bool active);
  bool GetActive();
};

