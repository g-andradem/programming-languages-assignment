#include "NameInputScreen.hpp"
#include <iostream>

NameInputScreen::NameInputScreen():
    font(),
    instruction(font),
    nameText(font),
    backgroundSprite(backgroundTexture)
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

    instruction.setString("Digite seu nome:");
    instruction.setCharacterSize(80);
    instruction.setFillColor(sf::Color::White);
    instruction.setPosition({150.f, 230.f});

    nameText.setCharacterSize(35);
    nameText.setFillColor(sf::Color::Yellow);
    nameText.setPosition({350.f, 360.f});
}

NameInputAction NameInputScreen::handleEvent(const sf::Event& event)
{
    // Recebe caracteres digitados
    if (const auto* textEntered = event.getIf<sf::Event::TextEntered>())
    {
        char32_t unicode = textEntered->unicode;

        // Caracteres imprimíveis
        if (unicode >= 32 && unicode != 127 &&
            playerName.getSize() < 20)
        {
            playerName += unicode;
            nameText.setString(playerName);
        }
    }

    // Captura teclas especiais
    if (const auto* keyPressed =
        event.getIf<sf::Event::KeyPressed>())
    {
        // Apagar último caractere
        if (keyPressed->code == sf::Keyboard::Key::Backspace)
        {
            if (!playerName.isEmpty())
            {
                playerName.erase(playerName.getSize() - 1);
                nameText.setString(playerName);
            }
        }

        // Confirmar nome
        if (keyPressed->code == sf::Keyboard::Key::Enter)
        {
            if (!playerName.isEmpty())
                return NameInputAction::Play;
        }
    }

    return NameInputAction::None;
}

void NameInputScreen::draw(sf::RenderTarget& window)
{
    window.draw(backgroundSprite);

    window.draw(instruction);
    window.draw(nameText);
}

const sf::String& NameInputScreen::getPlayerName() const
{
    return playerName;
}

void NameInputScreen::reset()
{
    playerName.clear();
    nameText.setString("");
}
