#pragma once

#include <SFML/Graphics.hpp>

enum class GameAction {
    Play,
    Paused,
    Exit
};

class GameScreen {
private:


public:
    //MainMenu();

    //MenuAction handleEvent(const sf::Event& event);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    //void centerText(sf::Text& text, float x);

    //void updateSelection();

    //int getSelectedButton() const;
};