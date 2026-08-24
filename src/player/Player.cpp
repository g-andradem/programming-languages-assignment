#include "Player.hpp"

#include <iostream>

Player::Player(Score& score): 
    texture(),
    sprite(texture),
    score(score),
    scoreTimer(1.f)
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

    bool isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        currentAnimation = PlayerAnimation::Side;
        isMoving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        currentAnimation = PlayerAnimation::Side;
        isMoving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        currentAnimation = PlayerAnimation::Front;
        isMoving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        currentAnimation = PlayerAnimation::Front;
        isMoving = true;
    }

    if (isMoving)
    {
        scoreTimer.update(deltaTime);

        if (scoreTimer.isFinished())
        {
            score.addPoints(100);
            scoreTimer.reset();

            printf("Pontos: %d\n", score.getPoints());
        }
    }
    else
    {
        scoreTimer.reset();
    }

    updateAnimation(deltaTime, currentAnimation);
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

void Player::updateAnimation(float deltaTime, PlayerAnimation animation){

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