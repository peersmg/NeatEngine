#include "ObjectFactory.h"
#include "GameObject.h"
#include "Game.h"
#include "OutputLog.h"

ObjectFactory::ObjectFactory()
{
}


ObjectFactory::~ObjectFactory()
{
}

bool ObjectFactory::Register(std::string name, tCreator fptr)
{
  m_creatorMap[name] = fptr;
  return true;
}

GameObject* ObjectFactory::Spawn(std::string name, InitialisationData data)
{
  GameObject* pTemp = nullptr;

  if (m_creatorMap.find(name) == m_creatorMap.end())
  {
    OutputLog::GetInstance().AddLine("Object \"" + name + "\" does not exist!", MessageType::ERROR);
  }
  else
  {
    tCreator fptr = m_creatorMap[name];
    pTemp = (*fptr)(data);

    if (data.scene == "")
    {
      Game::instance.m_SceneManager.AddObject(pTemp);
    }
    else
    {
      Game::instance.m_SceneManager.AddObject(pTemp, data.scene);
    }
  }

  return pTemp;
}

GameObject* ObjectFactory::Spawn(std::string name)
{
  GameObject* pTemp = nullptr;

  if (m_creatorMap.find(name) == m_creatorMap.end())
  {
    OutputLog::GetInstance().AddLine("Object \"" + name + "\" does not exist!", MessageType::ERROR);
  }
  else
  {
    tCreator fptr = m_creatorMap[name];
    InitialisationData data;
    pTemp = (*fptr)(data);

    if (data.scene == "")
    {
      Game::instance.m_SceneManager.AddObject(pTemp);
    }
    else
    {
      Game::instance.m_SceneManager.AddObject(pTemp, data.scene);
    }
  }

  return pTemp;
}