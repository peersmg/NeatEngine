#pragma once
#include "Component.h"

class GameObject;

class CCamera : public Component
{
private:
  sf::View m_view;
  float m_angle;
  sf::Vector2i m_size;
  sf::FloatRect m_viewport;

public:
  CCamera(GameObject* pOwner, sf::Vector2i size, sf::FloatRect viewport = sf::FloatRect(0, 0, 1, 1), float angle = 0);
  ~CCamera();

  void Update(float deltatime) override;

  sf::View GetView();
};

