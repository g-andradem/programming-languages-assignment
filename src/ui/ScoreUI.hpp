#pragma once

#include <SFML/Graphics.hpp>
#include "../core/Time.hpp"

class Score;

class ScoreUI {
    public:
        ScoreUI();

        void update(const Score& Score);
        void draw(sf::RenderWindow& window);
    private:
        
        sf::Font font;
        sf::Text text;
};