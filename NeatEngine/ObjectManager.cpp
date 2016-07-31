#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
  DeleteAllObjects();
}

void ObjectManager::AddObject(GameObject *newObject)
{

  // Add the object after the next highest draw depth

  auto it = m_allObjects.begin();

  while (it != m_allObjects.end() && (*it)->m_drawdepth < newObject->m_drawdepth)
  {
    ++it;
  }
  m_allObjects.insert(it, newObject);
}

void ObjectManager::DeleteInactiveObjects()
{

  // Delete incactive objects
  auto it = m_allObjects.begin();

  for (; it != m_allObjects.end(); ++it)
  {
    if (!(*it)->m_active)
    {
      delete *it;
      *it = nullptr;
    }
  }

  // Remove objects that have been set to nullptr
  auto ita = std::remove(m_allObjects.begin(), m_allObjects.end(), nullptr);
  m_allObjects.erase(ita, m_allObjects.end());
}

void ObjectManager::DeleteAllObjects()
{
  auto it = m_allObjects.begin();

  for (; it != m_allObjects.end(); ++it)
  {
    delete *it;
  }

  m_allObjects.clear();
}

void ObjectManager::DrawAll()
{
  auto it = m_allObjects.begin();

  for (; it != m_allObjects.end(); ++it)
  {
    if ((*it)->m_active)
    {
      (*it)->Draw();
    }
  }

}

void ObjectManager::UpdateAll()
{
  auto it = m_allObjects.begin();

  sf::Clock deltaClock;
  sf::Time deltaTime = deltaClock.getElapsedTime();

  for (; it != m_allObjects.end(); ++it)
  {
    if ((*it)->m_active)
    {
      (*it)->Update(deltaTime.asSeconds());
    }
  }

  deltaClock.restart();
}