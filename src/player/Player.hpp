#include <SFML/Graphics.hpp>

#include "../core/Score.hpp"
#include "../core/Timer.hpp"

enum class PlayerAnimation {
    Front,
    Left,
    Right
};

class Player {
    public:
        Player(Score& score);

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

        sf::Vector2f getPosition();

        void setPosition(float WIDHT, float HEIGHT);

        void updateAnimation(float deltaTime, PlayerAnimation animation);

        void setOrigin(sf::Vector2f origin);
        sf::FloatRect getLocalBounds();

    private:
        Score& score;

        Timer scoreTimer;
        /*
        Timer animationTimer(0.15f);
        Timer attackCooldown(2.f);
        Timer scoreTimer(1.f);
        Timer interactionTimer(0.5f);
        */

        sf::Texture frontTexture;
        sf::Texture rightTexture;
        sf::Texture leftTexture;

        sf::Texture texture;
        sf::Sprite sprite;

        PlayerAnimation currentAnimation;
};