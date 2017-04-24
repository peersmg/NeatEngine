#pragma once
#include "stdafx.h"
#include "GUIStyle.h"
class ResourceLoader
{
private:
  std::map<std::string, sf::Texture> m_images;
  std::map<std::string, sf::SoundBuffer> m_soundEffects;
  std::map<std::string, sf::Font> m_fonts;
  std::map<std::string, GUIStyle> m_styles;

  ResourceLoader();
  ~ResourceLoader();

public:

  static ResourceLoader& GetInstance()
  {
    static ResourceLoader instance;
    return instance;
  }

  void LoadStyles();
  void LoadTextures();
  void LoadSoundEffects();
  void LoadFonts();

  GUIStyle GetStyle(std::string styleName);

  bool isTextureLoaded(std::string imageFile);
  sf::Texture GetTexture(std::string imageFile);

  bool isSoundLoaded(std::string soundFile);
  sf::SoundBuffer GetSoundEffect(std::string soundFile);

  bool isFontLoaded(std::string fontFile);
  sf::Font GetFont(std::string fontFile);
};

