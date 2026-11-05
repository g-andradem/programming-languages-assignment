#pragma once

#include <SFML/Graphics.hpp>

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
        int handleEvent(const sf::Event& event);
};