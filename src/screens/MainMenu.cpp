#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu(): 
    title(font),
    subTitle(font),
    playButton(font),
    scoreButton(font),
    exitButton(font)
{
    
    if (!font.openFromFile("assets/fonts/ROGENZ(DEMO).ttf")) {
        std::cerr << "Erro ao carregar fonte!\n";
    }

    title.setString("PLANO B");
    title.setCharacterSize(100);
    title.setLetterSpacing(1.1f);
    title.setPosition({
        416.f - title.getLocalBounds().size.x / 2.f,
        150.f
    });

    subTitle.setString("DEFINITIVE EDITION");
    subTitle.setCharacterSize(50);
    subTitle.setLetterSpacing(1.2f);
    subTitle.setFillColor(sf::Color::Yellow);
    subTitle.setPosition({
        416.f - subTitle.getLocalBounds().size.x / 2.f,
        260.f
    });

    playButton.setString("Jogar");
    playButton.setPosition({
        416.f - playButton.getLocalBounds().size.x / 2.f,
        390.f
    });

    scoreButton.setString("Placar");
    scoreButton.setPosition({
        416.f - playButton.getLocalBounds().size.x / 2.f,
        460.f
    });

    exitButton.setString("Sair");
    exitButton.setPosition({
        416.f - exitButton.getLocalBounds().size.x / 2.f,
        530.f
    });

    updateSelection();
}

// Seleciona Opcao no Menu
MenuAction MainMenu::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {

        if (keyPressed->scancode == sf::Keyboard::Scan::W) {

            selectedButton--;

            if (selectedButton < 0)
                selectedButton = 2;

            updateSelection();
        }

        else if (keyPressed->scancode == sf::Keyboard::Scan::S) {

            selectedButton++;

            if (selectedButton > 2)
                selectedButton = 0;

            updateSelection();
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {

            if (selectedButton == 0)
                return MenuAction::Play;

            if (selectedButton == 1)
                return MenuAction::Score;

            if (selectedButton == 2)
                return MenuAction::Exit;
        }
    }

    return MenuAction::None;
}

void MainMenu::update(float deltaTime)
{
    // Atualizações do menu
}

void MainMenu::draw(sf::RenderWindow& window)
{
    window.draw(title);
    window.draw(subTitle);
    window.draw(playButton);
    window.draw(scoreButton);
    window.draw(exitButton);
}

void MainMenu::updateSelection()
{
    playButton.setCharacterSize(52);
    scoreButton.setCharacterSize(52);
    exitButton.setCharacterSize(52);

    if (selectedButton == 0)
        playButton.setCharacterSize(70);
    else if (selectedButton == 1)
        scoreButton.setCharacterSize(70);
    else if (selectedButton == 2)
        exitButton.setCharacterSize(70);

    centerText(playButton, 416.f);
    centerText(scoreButton, 416.f);
    centerText(exitButton, 416.f);
}

void MainMenu::centerText(sf::Text& text, float x)
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

int MainMenu::getSelectedButton() const
{
    return selectedButton;
}