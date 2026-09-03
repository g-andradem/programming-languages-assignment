#include "HeartUI.hpp"
#include <iostream>

HeartUI::HeartUI()
    : heartTexture(),
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
        // seleciona a area da pixel arte que vai ser utilizada
        hearts[i].setTextureRect(
            sf::IntRect({0, 0}, {32, 32})
        );
        hearts[i].setScale({4.f, 4.f});
        hearts[i].setPosition({
            (6.55 * 40.f) + i*90.f, 
            0.2 * 40.f
        });
    }
}

void HeartUI::loseLife()
{
    if (lives > 0) {
        lives--;
    }
}

void HeartUI::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < lives; ++i) {
        window.draw(hearts[i]);
    }
}