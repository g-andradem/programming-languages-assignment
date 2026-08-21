#pragma once

class GameTime
{
public:
    GameTime();

    void update(float deltaTime);

    int getMinutes() const;
    int getSeconds() const;

private:
    float elapsedTime;

    int minutes;
    int seconds;
};