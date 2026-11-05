#include <SFML/Graphics.hpp>

enum class TeacherAnimation
{
    Front,
    Diagonal,
    Side
};

class Teacher
{
    private:
        sf::Texture frontTexture;
        sf::Texture diagonalTexture;
        sf::Texture sideTexture;

        sf::Sprite sprite;

        float animationTimer = 0.0f;
        float animationInterval = 2.2f; // segundos entre sprites

        int animationFrame = 0; // 0 = frente, 1 = diagonal, 2 = lado
        int animationDirection = 1; // 1 = avançar, -1 = voltar

        TeacherAnimation currentAnimation = TeacherAnimation::Front;

        void updateAnimation(float deltaTime);
    public:
        Teacher();

        void update(float deltaTime);

        void draw(sf::RenderWindow& window);

        void setScale(float width, float height);
        void setOrigin(sf::Vector2f origin);
        void setPosition(float x, float y);

        sf::Vector2f getPosition();

        sf::FloatRect getLocalBounds();

        void setAnimation(TeacherAnimation animation);
        TeacherAnimation getCurrentAnimation() const;

        void decreaseAnimationInterval();
};