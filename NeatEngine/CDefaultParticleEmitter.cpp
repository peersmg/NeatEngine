#include "CDefaultParticleEmitter.h"
#include "ResourceLoader.h"
#include "OutputLog.h"
#include "Particle.h"

CDefaultParticleEmitter::CDefaultParticleEmitter(sf::Vector2f position)
{
  m_position = position;

  if (ResourceLoader::GetInstance().isTextureLoaded("resources/particles/circle.png"))
  {
    m_particleTexture = ResourceLoader::GetInstance().GetTexture("resources/particles/circle.png");
  }
  else
  {
    OutputLog::GetInstance().AddLine("Particle Texture not loaded!", MessageType::ERROR);
  }
  
  m_emissionDuration = 3;
  m_particleSpeed = 50;
  m_particleLifetime = 5;
  m_particlesPerSecond = 200;
  m_particleRotationSpeed = 0;

  m_particleColor = sf::Color::Red;

  m_fadeOverTime = false;
  m_looping = true;
}


CDefaultParticleEmitter::~CDefaultParticleEmitter()
{
}

void CDefaultParticleEmitter::Update(float deltaTime)
{
  if (m_particleCountdown > 0)
  {
    m_particleCountdown -= deltaTime;
  }
  else
  {
    m_particleCountdown = 1.0f / m_particlesPerSecond;

    // Spawn Particle

    m_particleSprite.setTexture(m_particleTexture);
    m_particleSprite.setColor(sf::Color(255, 255, 255));
    sf::Vector2f vel = sf::Vector2f((rand() % 500)-250, (rand() % 500)-250);
    sf::Color col = sf::Color(rand() % 255, rand() % 255, rand() % 255);
    m_particles.push_back(new Particle(m_position, vel, m_particleSprite, m_particleLifetime, sf::Vector2f(0, -11), sf::Vector2f(5, 5), col));
  }
  
  for (int i = 0; i < m_particles.size(); i++)
  {
    if (m_particles[i]->GetActive())
    {
      m_particles[i]->Update(deltaTime);
    }
    else
    {
      delete m_particles[i];
      m_particles[i] = nullptr;
    }
  }

  m_particles.erase(std::remove(m_particles.begin(), m_particles.end(), nullptr), m_particles.end());
}

void CDefaultParticleEmitter::Draw()
{
  for (Particle* pParticle : m_particles)
  {
    //if (pParticle->GetActive())
    //{
      pParticle->Draw();
    //}
  }
}