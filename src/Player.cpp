#include "Player.hpp"

Player::Player()
{
  body.setSize({28.f, 28.f});
  body.setFillColor(sf::Color::Red);
  body.setPosition({100.f, 100.f});
}

void Player::handleInput()
{
  velocity.x = 0.f;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    velocity.x = -SPEED;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    velocity.x = SPEED;
  }

  if (onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
  {
    velocity.y = -JUMP_FORCE;
    onGround = false;
  }
}

void Player::update(float dt)
{
  velocity.y += GRAVITY * dt;
  body.move(velocity * dt);
}

void Player::draw(sf::RenderTarget &target)
{
  target.draw(body);
}

sf::FloatRect Player::getBounds() const
{
  return body.getGlobalBounds();
}

void Player::setOnGround(bool value)
{
  onGround = value;
  if (value)
  {
    velocity.y = 0.f;
  }
}
