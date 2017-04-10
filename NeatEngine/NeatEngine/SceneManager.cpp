#include "stdafx.h"
#include "SceneManager.h"
#include "Component.h"
#include "Scene.h"
#include "OutputLog.h"

SceneManager::SceneManager()
{
  pCurScene = nullptr;
}


SceneManager::~SceneManager()
{
}

void SceneManager::AddObject(std::string sceneId, GameObject* newObject)
{
  if (SceneExists(sceneId))
  {
    // Add the object to the end of the list
    m_scenes[sceneId]->AddObject(newObject);
  }
}

void SceneManager::AddScene(std::string sceneId, Scene *pScene)
{
  m_scenes[sceneId] = pScene;
}

void SceneManager::SetScene(std::string sceneId)
{
  if (SceneExists(sceneId))
  {
    if (pCurScene == nullptr)
    {
      pCurScene = m_scenes[sceneId];
      pCurScene->LoadScene();
    }
    else 
    {
      pCurScene->UnloadScene();
      pCurScene = nullptr;
      pCurScene = m_scenes[sceneId];
    }
  }
}

bool SceneManager::SceneExists(std::string sceneId)
{
  if (m_scenes.find(sceneId) == m_scenes.end())
  {
    OutputLog log;
    log.Output("Scene \"" + sceneId + "\" does not exist.", OutputLog::MessageType::ERROR);
    return false;
  }
  else
  {
    return true;
  }
}

void SceneManager::UpdateScene()
{
  sf::Time deltaTime = m_deltaClock.restart();

  if (pCurScene != nullptr)
  {
    pCurScene->UpdateObjects(deltaTime.asSeconds());
  }
}

void SceneManager::DrawScene()
{
  if (pCurScene != nullptr)
  {
    pCurScene->DrawObjects();
  }
}

void SceneManager::DeleteInactiveObjects()
{
  if (pCurScene != nullptr)
  {
    pCurScene->DeleteInactiveObjects();
  }
}