#include "HeartUI.hpp"
#include <iostream>

// Construtor do UI Corações
HeartUI::HeartUI(): 
    heartTexture(),
    hearts{
        sf::Sprite(heartTexture),
        sf::Sprite(heartTexture),
        sf::Sprite(heartTexture)
    },
    lives(3)
{
    if (!heartTexture.loadFromFile("assets/textures/hud/heart_art.png")) {
        std::cerr << "ERRO: nao carregou o coracao!\n";
    } 

    for (int i = 0; i < 3; ++i) {
        hearts[i].setTextureRect(
            sf::IntRect({0, 0}, {32, 32})
        );
        hearts[i].setScale({4.f, 4.f});
        hearts[i].setPosition({
            (6.55f * 40.f) + i * 90.f,
            0.2 * 40.f
        });
    }
}

// Perder uma Vida
void HeartUI::loseLife()
{
    if (lives > 0) {
        lives--;
    }
}

// Setter das Vidas
void HeartUI::setLives(int lives)
{
    this->lives = std::clamp(lives, 0, 3);
}

// Desenhar as Vidas
void HeartUI::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < lives; ++i) {
        window.draw(hearts[i]);
    }
}