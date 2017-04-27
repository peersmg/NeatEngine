#include "stdafx.h"
#include "ResourceLoader.h"
#include "OutputLog.h"

ResourceLoader::ResourceLoader()
{
}


ResourceLoader::~ResourceLoader()
{
}

void ResourceLoader::LoadStyles()
{
  // Add styles here
  m_styles["DefaultStyle"] = GUIStyle();

  //////////////////

  for (auto &element : m_styles)
  {
    element.second.LoadAll();
  }
}

void ResourceLoader::LoadTextures()
{
  std::vector<std::string> textures;

  // Add images here
  textures.push_back("resources/Splashscreen.png");


  //////////////////

  for (int i = 0; i < textures.size(); i++)
  {
    sf::Texture temp;
    temp.loadFromFile(textures[i]);
    m_images[textures[i]] = temp;
  }
}

void ResourceLoader::LoadSoundEffects()
{
  std::vector<std::string> soundEffects;

  // Add sounds here
  //soundEffects.push_back("");


  //////////////////

  for (int i = 0; i < soundEffects.size(); i++)
  {
    sf::SoundBuffer temp;
    temp.loadFromFile(soundEffects[i]);
    m_soundEffects[soundEffects[i]] = temp;
  }
}

void ResourceLoader::LoadFonts()
{
  std::vector<std::string> fonts;

  // Add fonts here
  fonts.push_back("fonts/SquaresBold.otf"); 
  fonts.push_back("fonts/lucon.ttf");

  //////////////////

  for (int i = 0; i < fonts.size(); i++)
  {
    sf::Font temp;
    temp.loadFromFile(fonts[i]);
    m_fonts[fonts[i]] = temp;
  }
}

GUIStyle ResourceLoader::GetStyle(std::string styleName)
{
  if (m_styles.find(styleName) == m_styles.end())
  {
    return m_styles["DefaultStyle"];
    OutputLog::GetInstance().AddLine("Style \"" + styleName + "\" does not exist!", MessageType::ERROR);
  }
  else
  {
    return m_styles[styleName];
  }
}

bool ResourceLoader::isTextureLoaded(std::string imageFile)
{
  if (m_images.find(imageFile) == m_images.end())
  {
    return false;
  }
  else
  {
    return true;
  }
}

sf::Texture ResourceLoader::GetTexture(std::string imageFile)
{
  return m_images[imageFile];
}

bool ResourceLoader::isSoundLoaded(std::string soundFile)
{
  if (m_soundEffects.find(soundFile) == m_soundEffects.end())
  {
    return false;
  }
  else
  {
    return true;
  }
}

sf::SoundBuffer ResourceLoader::GetSoundEffect(std::string soundFile)
{
  return m_soundEffects[soundFile];
}

bool ResourceLoader::isFontLoaded(std::string fontFile)
{
  if (m_fonts.find(fontFile) == m_fonts.end())
  {
    return false;
  }
  else
  {
    return true;
  }
}

sf::Font ResourceLoader::GetFont(std::string fontFile)
{
  return m_fonts[fontFile];
}