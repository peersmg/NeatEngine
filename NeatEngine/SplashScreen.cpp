#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "InputManager.h"
#include "OutputLog.h"
#include "ObjectFactory.h"

#include "CText.h"
#include "CMyButton.h"
#include "CRectShape.h"
#include "CAudio.h"
#include "CTextfield.h"

GameObject* CreateSplashScreen(InitialisationData data)
{
  SplashScreen* pTemp = new SplashScreen();
  return (GameObject*)pTemp;
}

const bool bSplashScreen = ObjectFactory::GetInstance().Register("SplashScreen", CreateSplashScreen);

SplashScreen::SplashScreen()
{
  m_active = true;

  AddComponent(new CRectShape(this, sf::FloatRect(0, 0, Game::instance.GetWindow()->GetSize().x, Game::instance.GetWindow()->GetSize().y), sf::Color(100, 50, 50)));

  AddComponent(new CText(this, "Neat Engine", sf::Vector2f(Game::instance.GetWindow()->GetSize().x / 2, 0), "DefaultStyle", 122, alignment::TOPCENTER));

  AddComponent(new CMyButton(this, "SplashButton", "Continue", 
    sf::FloatRect(Game::instance.GetWindow()->GetSize().x / 2, Game::instance.GetWindow()->GetSize().y - 100, Game::instance.GetWindow()->GetSize().x/2, 50),
    "DefaultStyle", 12, alignment::MIDDLECENTER));
  
  m_buttonSound = new CAudio(this, "resources/Pickup_Coin.wav", true);
  AddComponent(m_buttonSound);

  AddComponent(new CTextfield(this, sf::Vector2f(Game::instance.GetWindow()->GetSize().x / 2, Game::instance.GetWindow()->GetSize().y / 2), 500, 
               1, "Enter Your Name...", "DefaultStyle", 22, 0, alignment::MIDDLECENTER));
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::Update(float deltaTime)
{
  
}

void SplashScreen::ButtonPressed(std::string buttonId)
{
  OutputLog::GetInstance().AddLine("Button Pressed", MessageType::MESSAGE);

  //m_buttonSound->Play();

  //Game::instance.m_SceneManager.SetScene("DefaultScene");
}