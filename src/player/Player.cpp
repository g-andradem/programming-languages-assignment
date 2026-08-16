#include "Player.hpp"

#include <iostream>

Player::Player(): 
    texture(),
    sprite(texture),
    hp(100),
    level(1),
    speed(1.f),
    currentFrame(0),
    animationTimer(0.f),
    animationSpeed(0.15f)
{
    if (!texture.loadFromFile(
        "assets/textures/characters/sprite_andre0.png"
    )) {
        // tratar erro depois
        std::cout << "Erro ao carregar textura!\n";
        return;
    }

    // idleTexture.loadFromFile("assets/textures/characters/andre_idle.png");
    // walkTexture.loadFromFile("assets/textures/characters/andre_walk.png");
    // attackTexture.loadFromFile("assets/textures/characters/andre_attack.png");

    sprite.setTextureRect(
        sf::IntRect({0, 0}, {16, 16})
    );

    sprite.setScale({4.f, 4.f});
    sprite.setPosition({375.f, 275.f});
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

    //updateAnimation(deltaTime);
}

void Player::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

sf::Vector2f Player::getPosition(){
    return sprite.getPosition();
}

void Player::updateAnimation(float deltaTime){
    animationTimer += deltaTime;

    if (animationTimer >= animationSpeed)
    {
        animationTimer = 0.f;

        currentFrame++;

        if (currentFrame >= 4)
            currentFrame = 0;

        sprite.setTextureRect(
            sf::IntRect(
                {currentFrame * 16, 0},
                {16, 16}
            )
        );
    }
}