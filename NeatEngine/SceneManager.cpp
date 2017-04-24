#include "stdafx.h"
#include "SceneManager.h"
#include "Component.h"
#include "Scene.h"
#include "OutputLog.h"

SceneManager::SceneManager()
{
  m_pCurScene = nullptr;
  AddScene("PersistentScene", new Scene());
}


SceneManager::~SceneManager()
{
}

void SceneManager::AddObject(GameObject* newObject, std::string sceneId)
{
  if (SceneExists(sceneId))
  {
    // Add the object to the end of the list
    m_scenes[sceneId]->AddObject(newObject);
  }
  else
  {
    OutputLog::GetInstance().AddLine("Scene \"" + sceneId + "\" does not exist!", MessageType::ERROR);
  }
}

void SceneManager::AddScene(std::string sceneId, Scene *pScene)
{
  if (!SceneExists(sceneId))
  {
    m_scenes[sceneId] = pScene;
  }
  else
  {
    OutputLog::GetInstance().AddLine("Scene \"" + sceneId + "\" has already been added!", MessageType::ERROR);
  }
}

void SceneManager::SetScene(std::string sceneId)
{
  if (SceneExists(sceneId) && GetScene(sceneId) != m_pCurScene)
  {
    if (m_pCurScene == nullptr)
    {
      m_pCurScene = m_scenes[sceneId];
      m_pCurScene->LoadScene();
    }
    else 
    {
      m_pCurScene->SetActive(false);
      m_pCurScene = nullptr;
      m_pCurScene = m_scenes[sceneId];
      m_pCurScene->LoadScene();
    }
  }
}

Scene* SceneManager::GetScene(std::string sceneId)
{
  if (SceneExists(sceneId))
  {
    return m_scenes[sceneId];
  }
  else
  {
    OutputLog::GetInstance().AddLine("Scene \"" + sceneId + "\" does not exist!", MessageType::FATAL_ERROR);
    return nullptr;
  }
}

Scene* SceneManager::GetCurrentScene()
{
  return m_pCurScene;
}

bool SceneManager::SceneExists(std::string sceneId)
{
  if (m_scenes.find(sceneId) == m_scenes.end())
  {
    return false;
  }
  else
  {
    return true;
  }
}

void SceneManager::DeleteInactiveObjects()
{
  if (m_pCurScene != nullptr)
  {
    m_pCurScene->DeleteInactiveObjects();
  }
}