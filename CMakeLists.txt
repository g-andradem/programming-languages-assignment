cmake_minimum_required(VERSION 3.20)

project(MeuRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(MeuRPG
    src/main.cpp
    src/player/Player.cpp
    src/world/Map.cpp
    src/world/Tile.cpp
    src/world/Object.cpp
    src/world/Wall.cpp
    src/teacher/Teacher.cpp
    src/core/Time.cpp
    src/core/Score.cpp
    src/core/Timer.cpp
    src/ui/TimerUI.cpp
    src/ui/ScoreUI.cpp
    src/ui/HeartUI.cpp
    src/screens/MainMenu.cpp
    src/screens/ScoreMenu.cpp
    src/score/ScoreFile.cpp
)

target_link_libraries(MeuRPG PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)