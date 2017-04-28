#pragma once
#include "stdafx.h"

class GameObject;
typedef GameObject* (*tCreator)(InitialisationData data);

class ObjectFactory
{
private:
  ObjectFactory();
  ~ObjectFactory();

  std::map<std::string, tCreator> m_creatorMap;

public:
  
  static ObjectFactory& GetInstance()
  {
    static ObjectFactory instance;
    return instance;
  }

  bool Register(std::string name, tCreator fptr);

  GameObject* Spawn(std::string name);
  GameObject* Spawn(std::string name, InitialisationData data);

};

