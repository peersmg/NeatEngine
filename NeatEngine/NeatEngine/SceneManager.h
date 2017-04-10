#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Scene;

class SceneManager
{
private:
  std::map<std::string, Scene*> m_scenes;
  Scene* pCurScene;

  sf::Clock m_deltaClock;

public:
  SceneManager();
  ~SceneManager();

  // Add object to scene
  void AddObject(std::string sceneId, GameObject* newObject);

  // Update the current scene
  void UpdateScene();

  // Draw the current scene
  void DrawScene();

  // Add a new scene
  void AddScene(std::string sceneId, Scene *pScene);

  // Set the current scene
  void SetScene(std::string sceneId);

  // Check if the scene ID is in the map
  bool SceneExists(std::string sceneId);

  // Delete all GameObjects with m_active set to false
  void DeleteInactiveObjects();
};

