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
)

target_link_libraries(MeuRPG PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)