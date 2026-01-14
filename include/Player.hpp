#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
  Player();

  void handleInput();
  void update(float dt);
  void draw(sf::RenderTarget &target);

  sf::FloatRect getBounds() const;
  void setOnGround(bool value);

private:
  sf::RectangleShape body;

  sf::Vector2f velocity;
  bool onGround = false;

  static constexpr float SPEED = 220.f;
  static constexpr float GRAVITY = 1400.f;
  static constexpr float JUMP_FORCE = 520.f;
};
