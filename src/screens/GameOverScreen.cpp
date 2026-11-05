#include "GameOverScreen.hpp"
#include <iostream>

GameOverScreen::GameOverScreen(): 
    font(),
    gameOverText(font),
    restartText(font),
    menuText(font)
{
    if (!font.openFromFile("assets/fonts/ROGENZ(DEMO).ttf"))
    {
        std::cerr << "Erro ao carregar fonte!\n";
    }

    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(70);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition({250.f, 200.f});

    restartText.setString("Pressione ENTER para jogar novamente");
    restartText.setCharacterSize(25);
    restartText.setPosition({350.f, 350.f});

    menuText.setString("Pressione ESC para voltar ao menu");
    menuText.setCharacterSize(25);
    menuText.setPosition({350.f, 400.f});
}

void GameOverScreen::draw(sf::RenderWindow& window)
{
    window.draw(gameOverText);
    window.draw(restartText);
    window.draw(menuText);
}