#pragma once

#include <SFML/Graphics.hpp>
#include "World.hpp"

class Game
{
public:
  Game();
  void run();

private:
  void processEvents();
  void update();
  void render();

private:
  sf::RenderWindow window;
  World world;
};
