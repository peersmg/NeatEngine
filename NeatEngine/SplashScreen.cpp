#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "InputManager.h"
#include "OutputLog.h"

#include "CText.h"
#include "CMyButton.h"

SplashScreen::SplashScreen()
{
  m_active = true;

  AddComponent(new CText(this, "Neat Engine", sf::Vector2f(Game::instance.GetWindow()->GetSize().x / 2, 0), "DefaultStyle", 122, alignment::TOPCENTER));

  AddComponent(new CMyButton(this, "SplashButton", "Continue", 
    sf::FloatRect(Game::instance.GetWindow()->GetSize().x / 2, Game::instance.GetWindow()->GetSize().y - 100, Game::instance.GetWindow()->GetSize().x/2, 50),
    "DefaultStyle", 12, alignment::MIDDLECENTER));


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

  Game::instance.m_SceneManager.SetScene("DefaultScene");
}