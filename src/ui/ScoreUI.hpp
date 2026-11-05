#pragma once

#include <SFML/Graphics.hpp>
#include "../core/Score.hpp"

class Score;

class ScoreUI
{
    private:
        sf::Font font;
        sf::Text text;
    public:
        ScoreUI();

        void update(const Score& Score);
        void draw(sf::RenderWindow& window);

        void setPosition(float x, float y);
};