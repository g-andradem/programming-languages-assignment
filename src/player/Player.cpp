#include "Player.hpp"

#include <iostream>

Player::Player(): 
    texture(),
    sprite(texture),
    speed(1.f)
{
    if (!texture.loadFromFile("assets/textures/characters/sprite_PLAYER_frente.png")){
        // tratar erro depois
        std::cout << "Erro ao carregar textura!\n";
        return;
    }
    if (!frontTexture.loadFromFile("assets/textures/characters/sprite_PLAYER_frente.png")){
        // tratar erro depois
        std::cerr << "Erro ao carregar sprite do player (frente)\n";
        return;
    }
    if (!sideTexture.loadFromFile("assets/textures/characters/sprite_PLAYER_lado.png")){
        std::cerr << "Erro ao carregar sprite da professora (lado)\n";
    }

    sprite.setTextureRect(
        sf::IntRect({0, 0}, {32, 32})
    );

    sprite.setScale({3.f, 3.f});
}

void Player::update(float deltaTime){
    // float speed = 1.f; // pixels por segundo
    // float deltaTime = clock.restart().asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        sprite.move({-speed, 0.f});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        sprite.move({speed, 0.f});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        sprite.move({0.f, -speed});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        sprite.move({0.f, speed});
}

void Player::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

void Player::setPosition(float WIDHT, float HEIGHT){
    sprite.setPosition({WIDHT, HEIGHT});
}

sf::Vector2f Player::getPosition(){
    return sprite.getPosition();
}

void Player::setAnimation(PlayerAnimation animation)
{
    currentAnimation = animation;

    switch (animation)
    {
        case PlayerAnimation::Front:
            sprite.setTexture(frontTexture);
            break;

        case PlayerAnimation::Side:
            sprite.setTexture(sideTexture);
            break;
    }
}