#include <SFML/Graphics.hpp>

class ResultsScreen
{
    private:
        sf::Font font;
        
        sf::Text title;
        sf::Text playerText;
        sf::Text scoreTitle;
        sf::Text scoreText;
        sf::Text message;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

    public:
        ResultsScreen(
            const sf::String& playerName,
            int finalScore
        );

        void update();

        void draw(sf::RenderTarget& target);
};