#include <SFML/Graphics.hpp>

enum class TeacherAnimation {
    Front,
    Diagonal,
    Side
};

class Teacher {
    public:
        Teacher();

        void update(float deltaTime);

        void draw(sf::RenderWindow& window);

        void setScale(float width, float height);
        void setOrigin(sf::Vector2f origin);
        void setPosition(float x, float y);

        sf::Vector2f getPosition();

        sf::FloatRect getLocalBounds();

        void updateAnimation(float deltaTime);

        void setAnimation(TeacherAnimation animation);

    private:
        sf::Texture frontTexture;
        sf::Texture diagonalTexture;
        sf::Texture sideTexture;

        sf::Sprite sprite;

        TeacherAnimation currentAnimation;
};