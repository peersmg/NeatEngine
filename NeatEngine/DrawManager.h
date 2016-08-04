#pragma once
#include "DataTypes.h"

class DrawManager
{
private:
  static DrawManager* m_pDrawManager;

public:

  DrawManager();
  ~DrawManager();

  static DrawManager* GetInstance();

  void BasicRect(rect Rect, sf::Color color);
};

