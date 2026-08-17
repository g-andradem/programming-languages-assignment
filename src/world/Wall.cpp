#include "Wall.hpp"

Wall::Wall(const sf::Texture& texture):
    sprite(texture)
{
    sprite.setScale({4.f, 4.f});
}

void Wall::setPosition(float x, float y){
    sprite.setPosition({x, y});
}

void Wall::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}