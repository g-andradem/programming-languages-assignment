#include "Wall.hpp"

Wall::Wall(const sf::Texture& texture):
    sprite(texture)
{
    sprite.setScale({4.f, 4.f});
}

void Wall::setPosition(float x, float y){
    sprite.setPosition({x, y});
}

void Wall::setScale(float width, float height){
    sprite.setScale({width, height});
}

void Wall::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Wall::setOrigin(sf::Vector2f origin){
    sprite.setOrigin(origin);
}

void Wall::setRotation(float angle){
    sprite.setRotation(sf::degrees(angle));
}

sf::FloatRect Wall::getLocalBounds(){
    return sprite.getLocalBounds();
}

//sprite.setRotation(sf::degrees(90.f));