#include "stdafx.h"
#include "Scene.h"
#include "GameObject.h"
#include "Component.h"
#include "OutputLog.h"

Scene::Scene()
{
}

Scene::~Scene()
{
  UnloadScene();
}

void Scene::AddObject(GameObject* pObject)
{
  m_objects.push_back(pObject);
}

void Scene::UpdateObjects(float deltaTime)
{
  for (GameObject* pObject : m_objects)
  {
    for (Component* pComponent : pObject->GetComponents())
    {
      pComponent->Update(deltaTime);
    }

    pObject->Update(deltaTime);
  }
}

void Scene::DrawObjects()
{
  for (GameObject* pObject : m_objects)
  {
    for (Component* pComponent : pObject->GetComponents())
    {
      pComponent->Draw();
    }
  }
}

void Scene::UnloadScene()
{
  for (GameObject* pObject : m_objects)
  {
    pObject->SetActive(false);
  }

  DeleteInactiveObjects();

  OutputLog log;
  log.Output("Unloading scene...", OutputLog::MessageType::MESSAGE);
}

void Scene::DeleteInactiveObjects()
{
  auto it = m_objects.begin();

  // Iterate through all Game Objects and remove the ones with m_active set to false
  for (; it != m_objects.end(); ++it)
  {
    if (!(*it)->GetActive())
    {
      delete *it;
      *it = nullptr;
    }
  }

  // Find all the values in the list set to nullptr and push them to the end of the vector
  auto itr = std::remove(m_objects.begin(), m_objects.end(), nullptr);

  // Erase the values set to nullptr from the list
  m_objects.erase(itr, m_objects.end());
}