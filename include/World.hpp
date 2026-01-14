#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Block.hpp"

class World
{
public:
  static constexpr unsigned TILE_SIZE = 32;
  static constexpr unsigned WIDTH = 40;
  static constexpr unsigned HEIGHT = 20;

  World();

  void draw(sf::RenderTarget &target) const;
  bool checkGroundCollision(const sf::FloatRect &playerBounds, float &groundY) const;

private:
  std::vector<BlockType> blocks;

  BlockType getBlock(unsigned x, unsigned y) const;
  bool isSolid(BlockType type) const;
};
