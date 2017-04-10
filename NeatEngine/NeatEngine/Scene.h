#pragma once
#include "stdafx.h"

class GameObject;

class Scene
{
private:
  std::list<GameObject*> m_objects;

public:
  Scene();
  ~Scene();

  void AddObject(GameObject* pObject);

  virtual void LoadScene() = 0;
  void UnloadScene();

  void UpdateObjects(float deltaTime);
  void DrawObjects();

  void DeleteInactiveObjects();
};