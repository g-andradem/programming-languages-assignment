#include "NameInputScreen.hpp"
#include <iostream>

// Construtor da Tela de Inserir Nome
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
    centerText(instruction, 416.f, 230.f);

    nameText.setCharacterSize(35);
    nameText.setFillColor(sf::Color::Yellow);
    centerText(nameText, 416.f, 360.f);
}

// Eventos da Tela de Inserir Nome
NameInputAction NameInputScreen::handleEvent(const sf::Event& event)
{
    if (const auto* textEntered = event.getIf<sf::Event::TextEntered>())
    {
        char32_t unicode = textEntered->unicode;

        if (unicode >= 32 && unicode != 127 &&
            playerName.getSize() < 20)
        {
            playerName += unicode;
            nameText.setString(playerName);
            centerText(nameText, 416.f, 360.f);
        }
    }

    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Backspace)
        {
            if (!playerName.isEmpty())
            {
                playerName.erase(playerName.getSize() - 1);
                nameText.setString(playerName);
                centerText(nameText, 416.f, 360.f);
            }
        }

        if (keyPressed->code == sf::Keyboard::Key::Enter)
        {
            if (!playerName.isEmpty())
                return NameInputAction::Play;
        }
    }

    return NameInputAction::None;
}

// Centralizar Texto
void NameInputScreen::centerText(sf::Text& texto, float x, float y)
{
    sf::FloatRect bounds = texto.getLocalBounds();

    texto.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
    });

    texto.setPosition({x, y});
}

// Desenhar a Tela de Inserir o Nome
void NameInputScreen::draw(sf::RenderTarget& window)
{
    window.draw(backgroundSprite);
    window.draw(instruction);
    window.draw(nameText);
}

// Getter do Nome do Jogador
const sf::String& NameInputScreen::getPlayerName() const
{
    return playerName;
}

// Reset da Tela de Inserir Nome do Jogador
void NameInputScreen::reset()
{
    playerName.clear();
    nameText.setString("");
}
