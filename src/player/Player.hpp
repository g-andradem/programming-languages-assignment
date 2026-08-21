#include <SFML/Graphics.hpp>

enum class PlayerAnimation {
    Front,
    Side
};

class Player {
    public:
        Player();

        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

        sf::Vector2f getPosition();

        void updateAnimation(float deltaTime);

        void updateTexture();

        void setPosition(float WIDHT, float HEIGHT);

        void setAnimation(PlayerAnimation animation);

    private:
        sf::Texture frontTexture;
        sf::Texture sideTexture;

        sf::Texture texture;
        sf::Sprite sprite;

        float speed;

        PlayerAnimation currentAnimation;
};