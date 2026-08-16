#include "Tile.hpp"

Tile::Tile(const sf::Texture& texture, bool walkable):
    sprite(texture),
    walkable(walkable)
{
    sprite.setScale({4.f, 4.f});
}

void Tile::setPosition(float x, float y){
    sprite.setPosition({x, y});
}

void Tile::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

bool Tile::isWalkable() const{
    return walkable;
}