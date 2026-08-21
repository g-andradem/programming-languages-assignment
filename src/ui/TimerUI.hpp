#pragma once

#include <SFML/Graphics.hpp>
#include "../core/GameTime.hpp"

class Timer;

class TimerUI {
    public:
        TimerUI();

        void update(const GameTime& gameTime);
        void draw(sf::RenderWindow& window);
    private:
        
        sf::Font font;
        sf::Text text;
};