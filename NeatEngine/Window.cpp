#include "stdafx.h"
#include "Window.h"
#include "InputManager.h"
#include "CCamera.h"
#include "OutputLog.h"
#include "GameObject.h"
#include "Component.h"

Window::Window(std::string title, sf::Vector2i size, bool fullscreen, sf::Color clearColor)
{
  m_fullScreen = fullscreen;
  m_title = title;
  m_size = size;
  m_clearColor = clearColor;

  m_window = nullptr;
  m_window = new sf::RenderWindow();

  ResetWindow();
}

Window::~Window()
{
  m_window->close();
}

void Window::Update()
{
  // Clear
  m_window->clear(m_clearColor);

  if (InputManager::GetInstance()->KeyPressed(sf::Keyboard::F11) && m_window->hasFocus())
  {
    m_fullScreen = !m_fullScreen;

    ResetWindow();
  }
}

void Window::Display()
{
  m_window->display();
}

void Window::ResetWindow()
{
  if (m_fullScreen)
  {
    m_window->create(sf::VideoMode::getFullscreenModes()[0], m_title, sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
  }
  else
  {
    m_window->create(sf::VideoMode(m_size.x, m_size.y), m_title, sf::Style::Titlebar | sf::Style::Close);
  }
}

void Window::Draw(const sf::Drawable& drawable, unsigned int camera)
{
  if (m_cameras.size() == 0)
  {
    m_window->draw(drawable);
  }
  else if (camera <= m_cameras.size())
  {
    m_window->setView(m_cameras[camera]->GetView());
    m_window->draw(drawable);
  }
}

sf::RenderWindow* Window::GetRenderWindow()
{
  return m_window;
}

void Window::SetFullscreen(bool fullscreen)
{
  m_fullScreen = fullscreen;
}
bool Window::GetFullscreen()
{
  return m_fullScreen;
}

void Window::SetSize(sf::Vector2i size)
{
  m_size = size;

  ResetWindow();
}

sf::Vector2i Window::GetSize()
{
  return m_size;
}

void Window::AddCamera(GameObject* newCamera)
{
  std::vector<CCamera*> cams;

  for (Component* comp : newCamera->GetComponents())
  {
    CCamera* camCast = dynamic_cast<CCamera*> (comp);

    if (camCast != nullptr)
    {
      cams.push_back(camCast);
    }
  }

  if (cams.size() > 0)
  {
    for (CCamera* camera : cams)
    {
      m_cameras.push_back(camera);
    }
  }
  else
  {
    OutputLog::GetInstance().AddLine("No camera component on passed object!", MessageType::ERROR);
  }

  
}