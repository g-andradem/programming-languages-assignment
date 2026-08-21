#include "Teacher.hpp"

#include <iostream>

Teacher::Teacher():
    sprite(frontTexture),
    currentAnimation(TeacherAnimation::Front)
{
    if (!frontTexture.loadFromFile("assets/textures/characters/sprite_professora.png")){
        std::cerr << "Erro ao carregar sprite da professora (frente)\n";
    }
    if (!diagonalTexture.loadFromFile("assets/textures/characters/sprite_professora_parcialmente_lado.png")){
        std::cerr << "Erro ao carregar sprite da professora (diagonal)\n";
    }
    if (!sideTexture.loadFromFile("assets/textures/characters/sprite_professora_completamente_lado.png")){
        std::cerr << "Erro ao carregar sprite da professora (lado)\n";
    }

    sprite.setTextureRect(
        sf::IntRect({0, 0}, {32, 32})
    );
}

void Teacher::setOrigin(sf::Vector2f origin){
    sprite.setOrigin(origin);
}

void Teacher::setScale(float width, float height){
    sprite.setScale({width, height});
}

void Teacher::setPosition(float x, float y){
    sprite.setPosition({x, y});
}

void Teacher::update(float deltaTime){
    updateAnimation(deltaTime);
}

void Teacher::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

sf::Vector2f Teacher::getPosition(){
    return sprite.getPosition();
}

sf::FloatRect Teacher::getLocalBounds(){
    return sprite.getLocalBounds();
}

void Teacher::updateAnimation(float deltaTime)
{
    // Por enquanto não precisamos do deltaTime.
}

void Teacher::setAnimation(TeacherAnimation animation)
{
    currentAnimation = animation;

    switch (animation)
    {
        case TeacherAnimation::Front:
            sprite.setTexture(frontTexture);
            break;

        case TeacherAnimation::Diagonal:
            sprite.setTexture(diagonalTexture);
            break;

        case TeacherAnimation::Side:
            sprite.setTexture(sideTexture);
            break;
    }
}
