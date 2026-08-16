#include <SFML/Graphics.hpp>

class Player {
    public:
        Player();

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

        sf::Vector2f getPosition();

        void updateAnimation(float deltaTime);

    private:
        sf::Texture texture;
        sf::Sprite sprite;

        sf::Texture walkTexture_1;
        sf::Texture walkTexture_2;

        int hp;
        int level;
        float speed;

        int currentFrame;
        float animationTimer;
        float animationSpeed;
};