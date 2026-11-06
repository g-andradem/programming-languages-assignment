#pragma once

#include <SFML/Graphics.hpp>

enum class NameInputAction
{
    None,
    Play
};

class NameInputScreen
{
    private:
        sf::Font font;
        sf::Text instruction;
        sf::Text nameText;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        sf::String playerName;

    public:
        NameInputScreen();

        NameInputAction handleEvent(const sf::Event& event);
        void draw(sf::RenderTarget& target);

        const sf::String& getPlayerName() const;

        void reset();
};