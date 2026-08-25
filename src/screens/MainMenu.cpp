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

    title.setString("MEU RPG");
    title.setCharacterSize(64);
    title.setPosition({300.f, 150.f});

    playButton.setString("Jogar");
    playButton.setCharacterSize(32);
    playButton.setPosition({350.f, 350.f});

    settingsButton.setString("Configuracoes");
    settingsButton.setCharacterSize(32);
    settingsButton.setPosition({300.f, 420.f});

    exitButton.setString("Sair");
    exitButton.setCharacterSize(32);
    exitButton.setPosition({350.f, 490.f});
}

void MainMenu::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {

        if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
            selectedButton--;

            if (selectedButton < 0)
                selectedButton = 2;
        }

        if (keyPressed->scancode == sf::Keyboard::Scancode::Down) {
            selectedButton++;

            if (selectedButton > 2)
                selectedButton = 0;
        }

        if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {
            // Ação do botão selecionado
        }
    }
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

int MainMenu::getSelectedButton() const
{
    return selectedButton;
}