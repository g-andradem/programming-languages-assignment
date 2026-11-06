#include "ResultsScreen.hpp"
#include <iostream>

ResultsScreen::ResultsScreen(
    const sf::String& playerName,
    int finalScore
): 
    backgroundSprite(backgroundTexture),
    title(font),
    playerText(font),
    scoreTitle(font),
    scoreText(font),
    message(font)
{
    if (!backgroundTexture.loadFromFile("assets/textures/background.jpg")) {
        std::cerr << "Erro ao carregar imagem de fundo!\n";
    }
    
    backgroundSprite.setTextureRect(
        sf::IntRect({0, 0}, {832, 832})
    );

    if (!font.openFromFile("assets/fonts/ROGENZ(DEMO).ttf")) {
        std::cerr << "Erro ao carregar fonte!\n";
    }

    title.setString("FIM DE JOGO");
    title.setCharacterSize(60);
    title.setFillColor(sf::Color::Red);
    title.setPosition({250.f, 120.f});

    playerText.setString("Parabens, " + playerName);
    playerText.setCharacterSize(35);
    playerText.setFillColor(sf::Color::White);
    playerText.setPosition({260.f, 250.f});

    scoreTitle.setString("PONTUACAO FINAL");
    scoreTitle.setCharacterSize(30);
    scoreTitle.setFillColor(sf::Color::White);
    scoreTitle.setPosition({280.f, 300.f});

    scoreText.setString(std::to_string(finalScore));
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreText.setPosition({250.f, 410.f});

    message.setString("Obrigado por jogar!");
    message.setCharacterSize(25);
    message.setFillColor(sf::Color::White);
    message.setPosition({250.f, 520.f});
}

void ResultsScreen::update()
{

}

void ResultsScreen::draw(sf::RenderTarget& window)
{
    window.draw(backgroundSprite);
    window.draw(title);
    window.draw(playerText);
    window.draw(scoreTitle);
    window.draw(scoreText);
    window.draw(message);
}
