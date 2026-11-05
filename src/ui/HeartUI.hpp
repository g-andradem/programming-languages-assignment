#pragma once

#include <SFML/Graphics.hpp>

class HeartUI
{
    private:
        sf::Texture heartTexture;
        sf::Sprite hearts[3];

        int lives;
    public:
        HeartUI();

        void setLives(int lives);
        void loseLife();

        void draw(sf::RenderWindow& window);
};