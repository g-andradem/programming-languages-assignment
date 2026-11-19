#include "Player.hpp"
#include <iostream>

// Construtor do Jogador
Player::Player(Score& score): 
    texture(),
    sprite(texture),
    score(score),
    scoreTimer(1.f)
{
    if (!texture.loadFromFile("assets/textures/characters/sprite_PLAYER_frente.png")){
        std::cout << "Erro ao carregar player!\n";
        return;
    }
    if (!frontTexture.loadFromFile("assets/textures/characters/sprite_PLAYER_frente.png")){
        std::cerr << "Erro ao carregar sprite do player (frente)\n";
        return;
    }
    if (!rightTexture.loadFromFile("assets/textures/characters/sprite_PLAYER_direita.png")){
        std::cerr << "Erro ao carregar sprite do player (direita)\n";
    }
    if (!leftTexture.loadFromFile("assets/textures/characters/sprite_PLAYER_esquerda.png")){
        std::cerr << "Erro ao carregar sprite do player (esquerda)\n";
    }

    sprite.setTextureRect(
        sf::IntRect({0, 0}, {32, 32})
    );

    sprite.setScale({3.f, 3.f});
}

// Update do Jogador
void Player::update(float deltaTime)
{
    updateStun(deltaTime);

    if (isStunned)
    {
        currentAnimation = PlayerAnimation::Front;
        sprite.setTexture(frontTexture);
        return;
    }

    bool isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        currentAnimation = PlayerAnimation::Left;
        isMoving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        currentAnimation = PlayerAnimation::Right;
        isMoving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        currentAnimation = PlayerAnimation::Front;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        currentAnimation = PlayerAnimation::Front;
    }

    if (isMoving)
    {
        scoreTimer.update(deltaTime);

        if (scoreTimer.isFinished())
        {
            score.addPoints(100);
            scoreTimer.reset();
        }
    }
    else
    {
        currentAnimation = PlayerAnimation::Front;
        scoreTimer.reset();
    }

    updateAnimation(deltaTime, currentAnimation);
}

// Desenhar Jogador
void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

// Colocar Jogador na Posição
void Player::setPosition(float WIDHT, float HEIGHT)
{
    sprite.setPosition({WIDHT, HEIGHT});
}

// Atualizar Animação do Jogador
void Player::updateAnimation(float deltaTime, PlayerAnimation animation)
{
    switch (animation)
    {
        case PlayerAnimation::Front:
            sprite.setTexture(frontTexture);
            break;

        case PlayerAnimation::Left:
            sprite.setTexture(leftTexture);
            break;
        case PlayerAnimation::Right:
            sprite.setTexture(rightTexture);
            break;
    }
}

// Getter da Animação
PlayerAnimation Player::getCurrentAnimation() const
{
    return currentAnimation;
}

// Setter da Origem do Jogador
void Player::setOrigin(sf::Vector2f origin)
{
    sprite.setOrigin(origin);
}

// Getter do Limite Local
sf::FloatRect Player::getLocalBounds()
{
    return sprite.getLocalBounds();
}

// Retirar vida do Jogador
void Player::takeDamage()
{
    if (health <= 0 || isStunned)
        return;

    health--;

    if (health > 0)
    {
        isStunned = true;
        stunTimer = stunDuration;

        currentAnimation = PlayerAnimation::Front;
        sprite.setTexture(frontTexture);

        scoreTimer.reset();
    }
}

// Atualizar o Atordoamento
void Player::updateStun(float deltaTime)
{
    if (!isStunned)
        return;

    stunTimer -= deltaTime;

    if (stunTimer <= 0.f)
    {
        stunTimer = 0.f;
        isStunned = false;
    }
}

// Getter da Vida do Jogador
int Player::getHealth() const
{
    return health;
}

// Getter do Atordoamento do Jogador
bool Player::getIsStunned() const
{
    return isStunned;
}

// Reset do Jogador
void Player::reset()
{
    health = 3;
    isStunned = false;
}