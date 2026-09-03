#pragma once

#include <SFML/Graphics.hpp>

enum class MenuAction {
    None,
    Play,
    Score,
    Settings,
    Exit
};

class MainMenu {
private:
    sf::Font font;

    sf::Text title;
    sf::Text playButton;
    sf::Text scoreButton;
    sf::Text settingsButton;
    sf::Text exitButton;

    int selectedButton = 0;

public:
    MainMenu();

    MenuAction handleEvent(const sf::Event& event);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    void updateSelection();

    int getSelectedButton() const;
};