#pragma once
#include "stdafx.h"
#include "Transform.h"

class Component;

class GameObject
{
  friend class SceneManager;

protected:
  Transform m_transform;                  // The transform of the object
  bool m_active;                          // Is the object active
  bool m_isPersistent;                    // Should the object exist across scenes
  std::vector<Component*> m_components;   // The objects components
  
  int m_layer;                            // The object draw and update layer

public:
  GameObject();

  virtual ~GameObject();

  std::vector<Component*> GetComponents();

  // Set the position of the gameobject
  void SetTransform(Transform position);
  Transform GetTransform();

  void SetLayer(int newLayer);
  int GetLayer();

  void SetPersistent(bool persistent);
  bool GetPersistent();

  // Update to be used for basic logic, for more advanced logic create a component
  virtual void Update(float deltaTime) {    };

  virtual void ButtonPressed(std::string buttonId) {    };

  virtual void HandleEvent(Event evt) {   };

  void SetActive(bool active);
  bool GetActive();

  void AddComponent(Component* newComponent);
};

