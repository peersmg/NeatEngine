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
    OutputLog log;
    log.Output("Scene \"" + sceneId + "\" does not exist!", OutputLog::MessageType::ERROR);
  }
}

void SceneManager::AddObject(GameObject* newObject)
{
  if (m_pCurScene != nullptr)
  {
    // Add the object to the end of the list
    m_pCurScene->AddObject(newObject);
  }
  else
  {
    OutputLog log;
    log.Output("Current scene has not been set!", OutputLog::MessageType::ERROR);
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
    OutputLog log;
    log.Output("Scene \"" + sceneId + "\" has already been added!", OutputLog::MessageType::MESSAGE);
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