#include "Game.hpp"

Game::Game()
: window(
  sf::VideoMode(sf::Vector2u{960u, 540u}),
  "Minecraft 2D"
  ),
  world()
{
  window.setVerticalSyncEnabled(true);
}

void Game::run()
{
  while (window.isOpen())
  {
    processEvents();
    update();
    render();
  }
}

void Game::processEvents()
{
  while (auto event = window.pollEvent())
  {
    if (event->is<sf::Event::Closed>())
    {
      window.close();
    }
  }
}

void Game::update()
{
  world.update();
}

void Game::render()
{
  window.clear(sf::Color(135, 206, 235));
  world.draw(window);
  window.display();
}
