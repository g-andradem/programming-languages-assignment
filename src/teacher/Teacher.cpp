#include "Teacher.hpp"
#include <iostream>

// Constutor da Professora
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

// Setter da Origem
void Teacher::setOrigin(sf::Vector2f origin)
{
    sprite.setOrigin(origin);
}

// Setter da Escala
void Teacher::setScale(float width, float height)
{
    sprite.setScale({width, height});
}

// Setter da Posição
void Teacher::setPosition(float x, float y)
{
    sprite.setPosition({x, y});
}

// Update da Professora
void Teacher::update(float deltaTime)
{
    updateAnimation(deltaTime);
}

// Desenhar a Professora
void Teacher::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

// Getter da Posição
sf::Vector2f Teacher::getPosition()
{
    return sprite.getPosition();
}

// Getter dos Limites Locais
sf::FloatRect Teacher::getLocalBounds()
{
    return sprite.getLocalBounds();
}

// Atualizar Animação da Professora
void Teacher::updateAnimation(float deltaTime)
{
    animationTimer += deltaTime;

    if (animationTimer < animationInterval)
        return;

    animationTimer -= animationInterval;

    animationFrame += animationDirection;

    if (animationFrame == 2)
        animationDirection = -1;

    else if (animationFrame == 0)
        animationDirection = 1;

    switch (animationFrame)
    {
        case 0:
            setAnimation(TeacherAnimation::Front);
            break;

        case 1:
            setAnimation(TeacherAnimation::Diagonal);
            break;

        case 2:
            setAnimation(TeacherAnimation::Side);
            break;
    }
}

// Setter da Animação
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

// Getter da Animação Atual
TeacherAnimation Teacher::getCurrentAnimation() const
{
    return currentAnimation;
}

// Diminuir Intervalo da Animação
void Teacher::decreaseAnimationInterval()
{
    animationInterval -= 0.5f;
}

// Reset da Professora
void Teacher::reset()
{
    animationInterval = 2.2f;
}