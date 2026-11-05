#include "PauseScreen.hpp"
#include <iostream>

PauseScreen::PauseScreen():
    title(font),
    resumeButton(font),
    exitButton(font)
{
    if (!font.openFromFile("assets/fonts/ROGENZ(DEMO).ttf")) {
        std::cerr << "Erro ao carregar fonte!\n";
    }

    // Fundo escuro transparente
    overlay.setSize({832.f, 832.f});
    overlay.setFillColor(sf::Color(0, 0, 0, 180));

    // Título
    title.setString("PAUSADO");
    title.setCharacterSize(90);
    title.setLetterSpacing(1.1f);
    title.setFillColor(sf::Color::White);

    title.setOrigin({
        title.getLocalBounds().position.x +
        title.getLocalBounds().size.x / 2.f,
        title.getLocalBounds().position.y +
        title.getLocalBounds().size.y / 2.f
    });

    title.setPosition({416.f, 180.f});

    // Botões
    resumeButton.setString("Continuar");
    exitButton.setString("Sair");

    updateSelection();
}

PauseAction PauseScreen::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        // Voltar ao jogo com ESC
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            return PauseAction::Play;

        if (keyPressed->scancode == sf::Keyboard::Scancode::W)
        {
            selectedButton--;

            if (selectedButton < 0)
                selectedButton = 1;

            updateSelection();
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::S)
        {
            selectedButton++;

            if (selectedButton > 1)
                selectedButton = 0;

            updateSelection();
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
        {
            if (selectedButton == 0){
                return PauseAction::Play;
            }
            if (selectedButton == 1)
                return PauseAction::Exit;
        }
    }

    return PauseAction::None;
}

void PauseScreen::update(float deltaTime)
{
    // Atualizações do menu, se necessário.
}

void PauseScreen::draw(sf::RenderWindow& window)
{
    window.draw(overlay);

    window.draw(title);

    window.draw(resumeButton);
    window.draw(exitButton);
}

void PauseScreen::updateSelection()
{
    resumeButton.setCharacterSize(52);
    exitButton.setCharacterSize(52);

    if (selectedButton == 0)
        resumeButton.setCharacterSize(70);

    else if (selectedButton == 1)
        exitButton.setCharacterSize(70);

    centerText(resumeButton, 416.f);
    centerText(exitButton, 416.f);

    resumeButton.setPosition({
        resumeButton.getPosition().x, 340.f
    });

    exitButton.setPosition({
        exitButton.getPosition().x, 500.f
    });
}

void PauseScreen::centerText(sf::Text& text, float x)
{
    auto bounds = text.getLocalBounds();

    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
    });

    text.setPosition({
        x,
        text.getPosition().y
    });
}