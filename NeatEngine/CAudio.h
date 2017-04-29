#pragma once
#include "stdafx.h"
#include "Component.h"

class CAudio : public Component
{
private:
  sf::SoundBuffer m_audioBuffer;    // Audio buffer
  sf::Sound m_audio;                // Audio file
  sf::Music m_music;                // Music file
  std::string m_audioFile;          // File path

  bool m_autoPlay;                  // Play audio on object creation
  bool m_looping;                   // Play the audio on loop
  bool m_soundEffect;               // Is the audio component a sound effect
  float m_volume;                   // Audio volume

public:

  /**
  * Constructor.
  *
  * @param pOwner - The time between the last frame and the current frame.
  * @param audioFile - The audio file to be played.
  * @param soundEffect - Is the audio a sound effect.
  * @param autoPlay - Should the audio autoplay.
  * @param looping - Should the audio loop.
  * @param volume - Volume of the audio.
  */
  CAudio(GameObject* pOwner, std::string audioFile, bool soundEffect, bool autoPlay = false, bool looping = false, float volume = 100);

  /**
  * Destructor.
  */
  ~CAudio();

  void SetAudio(std::string audioFile, bool soundEffect);

  void SetVolume(float newVolume);

  void Play();
  void Stop();
};

