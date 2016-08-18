#pragma once
#include "GameObject.h"

class ObjectManager
{
private:
  std::vector<GameObject*> m_allObjects;  // Main list of gameobjects

public:
  ObjectManager();
  ~ObjectManager();

  // Add object to list
  void AddObject(GameObject *newObject);

  // Delete all GameObjects with m_active set to false
  void DeleteInactiveObjects();

  // Update all GameObjects
  void UpdateAll();

  // Draw all GameObjects
  void DrawAll();
};

