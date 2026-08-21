#include "Student.hpp"

Student::Student(const sf::Texture& texture):
    sprite(texture){
}

void Student::setScale(float width, float height){
    sprite.setScale({width, height});
}

void Student::setOrigin(sf::Vector2f origin){
    sprite.setOrigin(origin);
}

void Student::setPosition(float x, float y){
    sprite.setPosition({x, y});
}

void Student::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Student::getLocalBounds(){
    return sprite.getLocalBounds();
}