#include "ResultsScreen.hpp"
#include <iostream>

// Construtor da Tela de Resultados
ResultsScreen::ResultsScreen(): 
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

    playerText.setCharacterSize(35);
    playerText.setFillColor(sf::Color::White);

    scoreTitle.setString("PONTUACAO FINAL");
    scoreTitle.setCharacterSize(30);
    scoreTitle.setFillColor(sf::Color::White);

    scoreText.setCharacterSize(60);
    scoreText.setFillColor(sf::Color::Yellow);

    message.setString("Aperte ENTER para voltar ao Menu");
    message.setCharacterSize(25);
    message.setFillColor(sf::Color::White);
}

// Eventos da Tela de Resultado
ResultsAction ResultsScreen::handleEvent(const sf::Event& event)
{
    if (event.is<sf::Event::KeyPressed>())
    {
        auto key = event.getIf<sf::Event::KeyPressed>();

        if (key->code == sf::Keyboard::Key::Enter)
        {
            return ResultsAction::Menu;
        }
    }
    return ResultsAction::None;
}

// Setter dos Resultados
void ResultsScreen::setResults(const sf::String& playerName, int finalScore)
{
    playerText.setString("Parabens, " + playerName);
    scoreText.setString(std::to_string(finalScore));

    centerText(title, 416.f, 150.f);
    centerText(playerText, 416.f, 280.f);
    centerText(scoreTitle, 416.f, 330.f);
    centerText(scoreText, 416.f, 430.f);
    centerText(message, 416.f, 540.f);
}

// Centralizar o Texto
void ResultsScreen::centerText(sf::Text& texto, float x, float y)
{
    sf::FloatRect bounds = texto.getLocalBounds();

    texto.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
    });

    texto.setPosition({x, y});
}

// Desenhar a Tela de Resultados
void ResultsScreen::draw(sf::RenderTarget& window)
{
    window.draw(backgroundSprite);
    window.draw(title);
    window.draw(playerText);
    window.draw(scoreTitle);
    window.draw(scoreText);
    window.draw(message);
}
