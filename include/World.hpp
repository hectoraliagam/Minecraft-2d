#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class World
{
public:
  World();

  void update();
  void draw(sf::RenderTarget&target);

private:
  static constexpr unsigned TILE_SIZE = 32;
  static constexpr unsigned WIDTH = 30;
  static constexpr unsigned HEIGHT = 17;

  std::vector<sf::RectangleShape> tiles;
};
