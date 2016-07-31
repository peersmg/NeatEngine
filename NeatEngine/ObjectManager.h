#pragma once
#include "GameObject.h"

class ObjectManager
{
private:
  std::list<GameObject*> m_allObjects;

public:
  ObjectManager();
  ~ObjectManager();

  // Add object to list
  void AddObject(GameObject *newObject);

  // Delete all GameObjects with m_active set to false
  void DeleteInactiveObjects();

  // Delete all GameObjects
  void DeleteAllObjects();

  // Update all GameObjects
  void UpdateAll();

  // Draw all GameObjects
  void DrawAll();
};

