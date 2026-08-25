#pragma once

#include <SFML/Graphics.hpp>

class MainMenu {
private:
    sf::Font font;

    sf::Text title;
    sf::Text playButton;
    sf::Text settingsButton;
    sf::Text exitButton;

    int selectedButton = 0;

public:
    MainMenu();

    void handleEvent(const sf::Event& event);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    int getSelectedButton() const;
};