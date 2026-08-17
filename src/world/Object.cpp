#include "Object.hpp"

Object::Object(const sf::Texture& texture):
    sprite(texture)
{
    sprite.setScale({3.f, 3.f});

}

void Object::setOrigin(sf::Vector2f origin)
{
    sprite.setOrigin(origin);
}

void Object::setPosition(float x, float y){
    sprite.setPosition({x, y});
}

void Object::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Object::getLocalBounds()
{
    return sprite.getLocalBounds();
}