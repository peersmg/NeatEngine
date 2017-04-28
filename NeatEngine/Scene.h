#pragma once
#include "stdafx.h"

class GameObject;

class Scene
{
private:
  int m_maxLayer;
  std::map<int, std::list<GameObject*>> m_layerObjects;
  bool m_active;

  void ChangeLayer(int oldLayer, int newLayer, GameObject* pObject);
  void UnloadScene();

public:
  Scene();
  ~Scene();

  void AddObject(GameObject* pObject, int layer = 0);

  virtual void LoadScene() {    };
  
  void SetActive(bool active);

  void UpdateObjects(float deltaTime);
  void DrawObjects();

  void DeleteInactiveObjects();

  void SendEvent(Event evt);
};