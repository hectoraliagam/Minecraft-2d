#include "World.hpp"

World::World()
{
  tiles.reserve(WIDTH * HEIGHT);

  for (unsigned y = 0; y < HEIGHT; ++y)
  {
    for (unsigned x = 0; x < WIDTH; ++x)
    {
      sf::RectangleShape tile;
      tile.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
      tile.setPosition(sf::Vector2f(
          static_cast<float>(x * TILE_SIZE),
          static_cast<float>(y * TILE_SIZE)));

      if (y < HEIGHT / 2)
      {
        tile.setFillColor(sf::Color(110, 70, 40));
      }
      else
      {
        tile.setFillColor(sf::Color::Transparent);
      }

      tiles.push_back(tile);
    }
  }
}

void World::update()
{
}

bool World::checkGroundCollision(const sf::FloatRect &playerBounds, float &groundY) const
{
  for (const auto &tile : tiles)
  {
    if (tile.getFillColor() == sf::Color::Transparent)
    {
      continue;
    }

    if (tile.getGlobalBounds().findIntersection(playerBounds))
    {
      groundY = tile.getPosition().y;
      return true;
    }
  }
  return false;
}

void World::draw(sf::RenderTarget &target)
{
  for (const auto &tile : tiles)
  {
    target.draw(tile);
  }
}
