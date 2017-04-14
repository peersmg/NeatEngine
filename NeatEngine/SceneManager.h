#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Scene;

class SceneManager
{
private:
  std::map<std::string, Scene*> m_scenes;   // Map of all the game scenes
  Scene* m_pCurScene;                         // Pointer to the current scene

public:

  /**
  * Constructor.
  */
  SceneManager();

  /**
  * Destructor.
  */
  ~SceneManager();

  /**
  * Add object to the specified scene.
  *
  * @param sceneId - The name of the scene to add the object to.
  * @param newObject - Pointer to the GameObject to be added.
  */
  void AddObject(GameObject* newObject, std::string sceneId);

  /**
  * Add object to the current scene.
  *
  * @param newObject - Pointer to the GameObject to be added.
  */
  void AddObject(GameObject* newObject);

  /**
  * Add a new scene.
  *
  * @param sceneId - The name of the scene to be added.
  * @param pScene - Pointer to the scene to be added.
  */
  void AddScene(std::string sceneId, Scene *pScene);

  /**
  * Unloads the previous scene and loads the new scene.
  *
  * @param sceneId - The name of the scene to set as the current scene.
  */
  void SetScene(std::string sceneId);

  /**
  * Gets a pointer to the specified scene.
  *
  * @param sceneId - The name of the scene to return.
  * @return A pointer to the specified scene.
  */
  Scene* GetScene(std::string sceneId);

  /**
  * Get the current scene.
  *
  * @return The current scene.
  */
  Scene* GetCurrentScene();

  /**
  * Check if the scene ID has been added.
  *
  * @param sceneId - The name of the scene to check.
  * @return If the scene has been added or not.
  */
  bool SceneExists(std::string sceneId);

  /**
  * Delete all GameObjects with m_active set to false.
  */
  void DeleteInactiveObjects();
};

