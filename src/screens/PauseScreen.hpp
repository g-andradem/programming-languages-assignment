#pragma once

#include <SFML/Graphics.hpp>

enum class PauseAction
{
    None,
    Play,
    Exit
};

class PauseScreen
{
    private:
        sf::Font font;

        sf::Text title;
        sf::Text resumeButton;
        sf::Text exitButton;

        sf::RectangleShape overlay;

        int selectedButton = 0;

        void updateSelection();
        void centerText(sf::Text& text, float x);
    public:
        PauseScreen();

        PauseAction handleEvent(const sf::Event& event);

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);
};