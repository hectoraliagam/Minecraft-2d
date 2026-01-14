#include "Game.hpp"

Game::Game()
    : window(
          sf::VideoMode(sf::Vector2u{960u, 540u}),
          "Minecraft 2D"),
      world()
{
  window.setVerticalSyncEnabled(true);
}

void Game::run()
{
  while (window.isOpen())
  {
    float dt = clock.restart().asSeconds();

    processEvents();
    update(dt);
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

void Game::update(float dt)
{
  player.handleInput();
  player.update(dt);

  float groundY;
  if (world.checkGroundCollision(player.getBounds(), groundY))
  {
    sf::FloatRect bounds = player.getBounds();
    float playerBottom = bounds.position.y + bounds.size.y;

    if (playerBottom > groundY)
    {
      player.setOnGround(true);
    }
  }
  else
  {
    player.setOnGround(false);
  }
}

void Game::render()
{
  window.clear(sf::Color(135, 206, 235));
  world.draw(window);
  player.draw(window);
  window.display();
}
