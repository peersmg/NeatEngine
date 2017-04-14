#include "stdafx.h"
#include "Scene.h"
#include "GameObject.h"
#include "Component.h"
#include "OutputLog.h"

Scene::Scene()
{
  m_maxLayer = 0;
  m_active = true;
}

Scene::~Scene()
{
  UnloadScene();
}

void Scene::AddObject(GameObject* pObject, int layer)
{
  m_layerObjects[layer].push_back(pObject);

  if (layer > m_maxLayer)
  {
    m_maxLayer = layer;
  }
}

void Scene::UpdateObjects(float deltaTime)
{
  if (m_active == true)
  {
    GameObject* pObjectToMove = nullptr;

    for (int i = 0; i <= m_maxLayer; i++)
    {
      if (m_layerObjects[i].size() > 0)
      {
        for (GameObject* pObject : m_layerObjects[i])
        {
          for (Component* pComponent : pObject->GetComponents())
          {
            pComponent->Update(deltaTime);
          }

          pObject->Update(deltaTime);

          if (pObject->GetLayer() != i)
          {
            pObjectToMove = pObject;
          }
        }

        if (pObjectToMove != nullptr)
        {
          ChangeLayer(i, pObjectToMove->GetLayer(), pObjectToMove);
        }
      }
    }
  }
  else
  {
    UnloadScene();
  }
}

void Scene::DrawObjects()
{
  for (int i = 0; i <= m_maxLayer; i++)
  {
    for (GameObject* pObject : m_layerObjects[i])
    {
      for (Component* pComponent : pObject->GetComponents())
      {
        pComponent->Draw();
      }
    }
  }
}

void Scene::UnloadScene()
{
  for (int i = 0; i <= m_maxLayer; i++)
  {
    for (GameObject* pObject : m_layerObjects[i])
    {
      pObject->SetActive(false);
    }
  }

  DeleteInactiveObjects();

  OutputLog log;
  log.Output("Unloading scene...", OutputLog::MessageType::MESSAGE);
}

void Scene::DeleteInactiveObjects()
{
  for (int i = 0; i <= m_maxLayer; i++)
  {
    auto it = m_layerObjects[i].begin();

    // Iterate through all Game Objects and remove the ones with m_active set to false
    for (; it != m_layerObjects[i].end(); ++it)
    {
      if (!(*it)->GetActive())
      {
        delete *it;
        *it = nullptr;
      }
    }

    // Erase the values set to nullptr from the list
    m_layerObjects[i].erase(std::remove(m_layerObjects[i].begin(), m_layerObjects[i].end(), nullptr), m_layerObjects[i].end());
  }
}

void Scene::ChangeLayer(int oldLayer, int newLayer, GameObject* pObject)
{
  m_layerObjects[oldLayer].erase(std::find(m_layerObjects[oldLayer].begin(), m_layerObjects[oldLayer].end(), pObject));

  AddObject(pObject, newLayer);
}

void Scene::SetActive(bool active)
{
  m_active = active;
}