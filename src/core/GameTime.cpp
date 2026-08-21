#include "GameTime.hpp"

GameTime::GameTime()
    : elapsedTime(0.f),
      minutes(3),
      seconds(0)
{
}

void GameTime::update(float deltaTime)
{
    elapsedTime += deltaTime;

    // 1 segundo real = 1 minuto no jogo
    if (elapsedTime >= 1.f){
        elapsedTime -= 1.f;

        seconds--;

        if (seconds <= -1){
            seconds = 59;
            minutes--;
        }
    }
}

int GameTime::getMinutes() const{
    return minutes;
}

int GameTime::getSeconds() const{
    return seconds;
}