#pragma once
#include "Component.h"

class GameObject;
class Particle;
class CDefaultParticleEmitter : public Component
{
private:

  sf::Vector2f m_position;
  sf::Texture m_particleTexture;
  sf::Sprite m_particleSprite;
  sf::Shader m_particleShader;

  sf::Color m_particleColor;

  float m_emissionDuration;
  float m_particleSpeed;
  float m_particleLifetime;
  int m_particlesPerSecond;
  float m_particleRotationSpeed;

  float m_particleCountdown;

  float m_gravity;

  bool m_fadeOverTime;
  bool m_looping;

  std::vector<Particle*> m_particles;

public:
  CDefaultParticleEmitter(sf::Vector2f position);
  ~CDefaultParticleEmitter();

  void Update(float deltaTime) override;
  void Draw() override;
};

