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
#include "CDropdown.h"
#include "CDefaultParticleEmitter.h"

GameObject* CreateSplashScreen(InitialisationData data)
{
  SplashScreen* pTemp = new SplashScreen();
  return (GameObject*)pTemp;
}

const bool bSplashScreen = ObjectFactory::GetInstance().Register("SplashScreen", CreateSplashScreen);

SplashScreen::SplashScreen()
{
  m_active = true;
  m_started = false;

  AddComponent(new CRectShape(this, sf::FloatRect(0, 0, Game::instance.GetWindow()->GetSize().x, Game::instance.GetWindow()->GetSize().y), sf::Color(30, 30, 30)));

  AddComponent(new CText(this, "Neat Engine", sf::Vector2f(Game::instance.GetWindow()->GetSize().x / 2, 0), "DefaultStyle", 122, alignment::TOPCENTER));

  m_button = new CMyButton(this, "SplashButton", "Continue",
    sf::FloatRect(Game::instance.GetWindow()->GetSize().x / 2, Game::instance.GetWindow()->GetSize().y - 100, Game::instance.GetWindow()->GetSize().x / 2, 50),
    "DefaultStyle", 22, alignment::MIDDLECENTER);
  AddComponent(m_button);

  m_buttonSound = new CAudio(this, "resources/sounds/Pickup_Coin.wav", true);
  AddComponent(m_buttonSound);

  m_nameTextfield = new CTextfield(this, sf::Vector2f(Game::instance.GetWindow()->GetSize().x / 2, Game::instance.GetWindow()->GetSize().y / 2), 500,
    1, "Enter Your Name...", "DefaultStyle", 22, 0, alignment::MIDDLECENTER);
  AddComponent(m_nameTextfield);

  std::vector<std::string> options;
  options.push_back("1");
  options.push_back("2");
  options.push_back("3");
  options.push_back("4");
  options.push_back("5");
  m_settingsDropdown = new CDropdown(this, options, sf::Vector2f(Game::instance.GetWindow()->GetSize().x / 2, Game::instance.GetWindow()->GetSize().y / 1.65),
    300, "DefaultStyle", 22, 0, alignment::MIDDLECENTER);
  AddComponent(m_settingsDropdown);

}
SplashScreen::~SplashScreen()
{
}

void SplashScreen::Update(float deltaTime)
{
  if (m_started)
  {
    if (InputManager::GetInstance()->ButtonClicked(sf::Mouse::Left))
    {
      AddComponent(new CDefaultParticleEmitter(sf::Vector2f(InputManager::GetInstance()->GetMousePosition())));
      OutputLog::GetInstance().AddLine("Emitter Added!");
    }
  }
}

void SplashScreen::ButtonPressed(std::string buttonId)
{
  OutputLog::GetInstance().AddLine("Name: " + m_nameTextfield->GetText() + "  Setting: " + m_settingsDropdown->GetSelectedOption(), MessageType::MESSAGE);

  m_nameTextfield->SetDormant(true);
  m_settingsDropdown->SetDormant(true);
  m_button->SetDormant(true);

  m_buttonSound->Play();

  m_started = true;

  //Game::instance.m_SceneManager.SetScene("DefaultScene");
}