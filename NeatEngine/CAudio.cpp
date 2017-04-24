#include "stdafx.h"
#include "CAudio.h"
#include "ResourceLoader.h"
#include "OutputLog.h"

CAudio::CAudio(GameObject* pOwner, std::string audioFile, bool soundEffect, bool autoPlay, bool looping, float volume)
{
  m_autoPlay = autoPlay;
  m_looping = looping;
  m_audioFile = audioFile;
  m_volume = volume;

  SetAudio(m_audioFile, soundEffect);
}

CAudio::~CAudio()
{
}

void CAudio::SetAudio(std::string audioFile, bool soundEffect)
{
  bool m_audioLoaded;

  m_soundEffect = soundEffect;

  if (m_soundEffect)
  {
    if (ResourceLoader::GetInstance().isSoundLoaded(audioFile))
    {
      m_audioBuffer = ResourceLoader::GetInstance().GetSoundEffect(audioFile);
      m_audioLoaded = true;
    }
    else
    {
      m_audioLoaded = m_audioBuffer.loadFromFile(audioFile);
    }
  }
  else
  {
    m_audioLoaded = m_music.openFromFile(audioFile);
  }


  if (m_audioLoaded)
  {
    if (m_soundEffect)
    {
      m_audio.setBuffer(m_audioBuffer);
      m_audio.setLoop(m_looping);
      m_audio.setVolume(m_volume);
    }
    else
    {
      m_music.setLoop(m_looping);
      m_music.setVolume(m_volume);
    }
    

    if (m_autoPlay)
    {
      Play();
    }

    OutputLog::GetInstance().AddLine("Audio \"" + audioFile + "\" loaded.", MessageType::MESSAGE);
  }
  else
  {
    OutputLog::GetInstance().AddLine("Sound failed to load", MessageType::ERROR);
  }
}

void CAudio::Play()
{
  if (m_soundEffect)
  {
    m_audio.play();
  }
  else
  {
    m_music.play();
  }
}

void CAudio::Stop()
{
  if (m_soundEffect )
  {
    m_audio.stop();
  }
  else
  {
    m_music.stop();
  }
}

void CAudio::SetVolume(float newVolume)
{
  m_volume = newVolume;

  if (m_soundEffect)
  {
    m_audio.setVolume(m_volume);
  }
  else
  {
    m_music.setVolume(m_volume);
  }
}