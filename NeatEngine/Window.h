#pragma once
class CCamera;
class GameObject;

class Window
{
private:
  bool m_fullScreen;
  std::string m_title;
  sf::Vector2i m_size;

  sf::RenderWindow* m_window;
  sf::Color m_clearColor;
  std::vector<CCamera*> m_cameras;

public:
  Window(std::string title, sf::Vector2i size, bool fullscreen, sf::Color clearColor = sf::Color(100, 100, 100));
  ~Window();

  void SetFullscreen(bool fullscreen);
  bool GetFullscreen();

  void SetSize(sf::Vector2i size);
  sf::Vector2i GetSize();

  sf::RenderWindow* GetRenderWindow();

  void Update();
  void Display();

  void Draw(const sf::Drawable& drawable, unsigned int camera = 0);

  void ResetWindow();

  void AddCamera(GameObject* newCamera);
};

