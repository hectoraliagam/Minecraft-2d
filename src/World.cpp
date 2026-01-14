#include "World.hpp"

World::World()
{
  blocks.resize(WIDTH * HEIGHT, BlockType::Air);

  for (unsigned y = 0; y < HEIGHT; ++y)
  {
    for (unsigned x = 0; x < WIDTH; ++x)
    {
      if (y > HEIGHT / 2)
      {
        blocks[y * WIDTH + x] = BlockType::Dirt;
      }
    }
  }
}

BlockType World::getBlock(unsigned x, unsigned y) const
{
  if (x >= WIDTH || y >= HEIGHT)
  {
    return BlockType::Air;
  }

  return blocks[y * WIDTH + x];
}

bool World::isSolid(BlockType type) const
{
  return type != BlockType::Air;
}

bool World::checkGroundCollision(const sf::FloatRect &playerBounds, float &groundY) const
{
  unsigned startX = playerBounds.position.x / TILE_SIZE;
  unsigned endX = (playerBounds.position.x + playerBounds.size.x) / TILE_SIZE;
  unsigned footY = (playerBounds.position.y + playerBounds.size.y) / TILE_SIZE;

  for (unsigned x = startX; x <= endX; ++x)
  {
    BlockType block = getBlock(x, footY);
    if (isSolid(block))
    {
      groundY = footY * TILE_SIZE;
      return true;
    }
  }
  return false;
}

void World::draw(sf::RenderTarget &target) const
{
  sf::RectangleShape tile({TILE_SIZE, TILE_SIZE});

  for (unsigned y = 0; y < HEIGHT; ++y)
  {
    for (unsigned x = 0; x < WIDTH; ++x)
    {
      BlockType block = getBlock(x, y);
      if (block == BlockType::Air)
      {
        continue;
      }

      tile.setPosition(
          {static_cast<float>(x * TILE_SIZE),
           static_cast<float>(y * TILE_SIZE)});

      switch (block)
      {
      case BlockType::Dirt:
        tile.setFillColor(sf::Color(110, 70, 40));
        break;
      case BlockType::Grass:
        tile.setFillColor(sf::Color::Green);
        break;
      case BlockType::Stone:
        tile.setFillColor(sf::Color(100, 100, 100));
        break;
      default:
        break;
      }
      target.draw(tile);
    }
  }
}
