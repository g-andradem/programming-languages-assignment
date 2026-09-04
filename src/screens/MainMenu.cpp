#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu(): 
    title(font),
    subTitle(font),
    playButton(font),
    scoreButton(font),
    exitButton(font)
{
    
    if (!font.openFromFile("assets/fonts/JetBrainsMono-Regular.ttf")) {
        std::cerr << "Erro ao carregar fonte!\n";
    }

    title.setString("Obscur Clair");
    title.setCharacterSize(80);
    title.setPosition({
        416.f - title.getLocalBounds().size.x / 2.f,
        150.f
    });

    subTitle.setString("Definition Edition");
    subTitle.setCharacterSize(40);
    subTitle.setLetterSpacing(1.2f);
    subTitle.setFillColor(sf::Color::Yellow);

    sf::FloatRect bounds = subTitle.getLocalBounds();
    subTitle.setOrigin(
        bounds.position + bounds.size / 2.f
    );
    subTitle.setPosition({
        416.f,
        260.f
    });

    playButton.setString("Jogar");
    playButton.setCharacterSize(42);
    playButton.setPosition({
        416.f - playButton.getLocalBounds().size.x / 2.f,
        380.f
    });

    scoreButton.setString("Placar");
    scoreButton.setCharacterSize(42);
    scoreButton.setPosition({
        416.f - playButton.getLocalBounds().size.x / 2.f,
        450.f
    });

    exitButton.setString("Sair");
    exitButton.setCharacterSize(42);
    exitButton.setPosition({
        416.f - exitButton.getLocalBounds().size.x / 2.f,
        520.f
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
    playButton.setString("Jogar");
    scoreButton.setString("Placar");
    exitButton.setString("Sair");

    if (selectedButton == 0) {
        playButton.setCharacterSize(50);
        scoreButton.setCharacterSize(42);
        exitButton.setCharacterSize(42);

        //playButton.setFillColor(sf::Color::Yellow);

        playButton.setString("> Jogar");
    }
    else if (selectedButton == 1) {
        playButton.setCharacterSize(42);
        scoreButton.setCharacterSize(50);
        exitButton.setCharacterSize(42);

        scoreButton.setString("> Placar");
    }
    else if (selectedButton == 2) {
        playButton.setCharacterSize(42);
        scoreButton.setCharacterSize(42);
        exitButton.setCharacterSize(50);

        exitButton.setString("> Sair");
    }
}

int MainMenu::getSelectedButton() const
{
    return selectedButton;
}