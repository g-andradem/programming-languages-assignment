#include <SFML/Graphics.hpp>

#include "../core/Score.hpp"
#include "../core/Timer.hpp"

enum class PlayerAnimation
{
    Front,
    Left,
    Right
};

class Player {
    private:
        Score& score;

        Timer scoreTimer;

        sf::Texture frontTexture;
        sf::Texture rightTexture;
        sf::Texture leftTexture;

        sf::Texture texture;
        sf::Sprite sprite;

        PlayerAnimation currentAnimation;

        int health = 3;

        bool isStunned = false;

        float stunTimer = 0.f;
        float stunDuration = 2.f;
    public:
        Player(Score& score);

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

        sf::Vector2f getPosition();

        void setPosition(float WIDHT, float HEIGHT);

        void updateAnimation(float deltaTime, PlayerAnimation animation);
        PlayerAnimation getCurrentAnimation() const;

        void setOrigin(sf::Vector2f origin);
        sf::FloatRect getLocalBounds();

        void takeDamage();
        void updateStun(float deltaTime);

        bool getIsStunned() const;
        int getHealth() const;

        void reset();
};