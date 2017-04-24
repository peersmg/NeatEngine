#pragma once
#include "stdafx.h"
#include "Component.h"

class CAudio : public Component
{
private:
  sf::SoundBuffer m_audioBuffer;
  sf::Sound m_audio;
  sf::Music m_music;
  std::string m_audioFile;

  bool m_autoPlay;
  bool m_looping;
  bool m_soundEffect;
  float m_volume;

public:
  CAudio(GameObject* pOwner, std::string audioFile, bool soundEffect, bool autoPlay = false, bool looping = false, float volume = 100);
  ~CAudio();

  void SetAudio(std::string audioFile, bool soundEffect);

  void SetVolume(float newVolume);

  void Play();
  void Stop();
};

