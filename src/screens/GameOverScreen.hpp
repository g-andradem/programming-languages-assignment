#pragma once

#include <SFML/Graphics.hpp>

enum class GameOverAction
{
    None,
    PlayAgain,
    Menu
};

class GameOverScreen
{
    private:
        sf::Font font;
        sf::Text gameOverText;
        sf::Text restartText;
        sf::Text menuText;

    public:
        GameOverScreen();

        void draw(sf::RenderWindow& window);
        GameOverAction handleEvent(const sf::Event& event);
};