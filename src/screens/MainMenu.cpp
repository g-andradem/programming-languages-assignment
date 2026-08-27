#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu()
    : title(font),
      playButton(font),
      settingsButton(font),
      exitButton(font)
{
    
    if (!font.openFromFile("assets/fonts/JetBrainsMono-Regular.ttf")) {
        std::cerr << "Erro ao carregar fonte!\n";
    }

    title.setString("COLANDO NA PROVA DE\nLINGUAGENS DE PROGRAMACAO");
    title.setCharacterSize(48);
    title.setPosition({
        416.f - title.getLocalBounds().size.x / 2.f,
        150.f
    });

    playButton.setString("Jogar");
    playButton.setCharacterSize(32);
    playButton.setPosition({
        416.f - playButton.getLocalBounds().size.x / 2.f,
        350.f
    });

    settingsButton.setString("Configuracoes");
    settingsButton.setCharacterSize(32);
    settingsButton.setPosition({
        416.f - settingsButton.getLocalBounds().size.x / 2.f,
        420.f
    });

    exitButton.setString("Sair");
    exitButton.setCharacterSize(32);
    exitButton.setPosition({
        416.f - exitButton.getLocalBounds().size.x / 2.f,
        490.f
    });

    updateSelection();
}

// Seleciona Opcao no Menu
MenuAction MainMenu::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed =
            event.getIf<sf::Event::KeyPressed>()) {

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
                return MenuAction::Settings;

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
    window.draw(playButton);
    window.draw(settingsButton);
    window.draw(exitButton);
}

void MainMenu::updateSelection()
{
    playButton.setString("Jogar");
    settingsButton.setString("Configuracoes");
    exitButton.setString("Sair");

    if (selectedButton == 0) {
        playButton.setString("> Jogar");
    }
    else if (selectedButton == 1) {
        settingsButton.setString("> Configuracoes");
    }
    else if (selectedButton == 2) {
        exitButton.setString("> Sair");
    }
}

int MainMenu::getSelectedButton() const
{
    return selectedButton;
}