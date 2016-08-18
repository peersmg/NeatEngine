#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(GameObject *newObject)
{
  // Add the object to the end of the list
  m_allObjects.insert(m_allObjects.end(), newObject);
}

void ObjectManager::DeleteInactiveObjects()
{
  auto it = m_allObjects.begin();

  // Iterate through all Game Objects and remove the ones with m_active set to false
  for (; it != m_allObjects.end(); ++it)
  {
    if (!(*it)->m_active)
    {
      delete *it;
      *it = nullptr;
    }
  }

  // Find all the values in the list set to nullptr and push them to the end of the vector
  auto itr = std::remove(m_allObjects.begin(), m_allObjects.end(), nullptr);

  // Erase the values set to nullptr from the list
  m_allObjects.erase(itr, m_allObjects.end());
  
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

  // Iterate through all the objects and update them
  for (; it != m_allObjects.end(); ++it)
  {
    if ((*it)->m_active)
    {
      (*it)->Update(deltaTime.asSeconds());
    }
  }

  deltaClock.restart();
}