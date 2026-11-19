#include <SFML/Graphics.hpp>

enum class ResultsAction {
    None,
    Menu
};

class ResultsScreen
{
    private:
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        sf::Font font;
        sf::Text title;
        sf::Text playerText;
        sf::Text scoreTitle;
        sf::Text scoreText;
        sf::Text message;

    public:
        ResultsScreen();

        ResultsAction handleEvent(const sf::Event& event);
        void setResults(const sf::String& playerName, int finalScore);
        void centerText(sf::Text& texto, float x, float y);
        void draw(sf::RenderTarget& target);
};