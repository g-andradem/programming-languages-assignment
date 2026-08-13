# programming-languages-assignment

LEMBRAR: .GITIGNROE PARA VCPKG_INSTALLED

## Ferramentas Utilizadas
SFML + CMake + vcpkg + VS Code.

### SFML
É a biblioteca que realmente vai fornecer as funcionalidades do jogo:

janela
teclado/mouse
gráficos 2D
sprites/texturas
áudio
fontes
eventos
etc.


### CMake
Ele não é a biblioteca do jogo e nem um compilador.

Ele vai dizer algo como:

"Meu projeto tem esses arquivos .cpp, usa C++17, precisa da SFML e deve gerar um executável."

A grande vantagem é que você não precisa ficar fazendo manualmente:
g++ main.cpp ... -lsfml-graphics -lsfml-window ...

cmake_minimum_required(VERSION 3.20) <- versão minima do CMake

project(MeuRPG) <- nome do projeto

set(CMAKE_CXX_STANDARD 17) e set(CMAKE_CXX_STANDARD_REQUIRED ON) <- versão do C++

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED) <- encontra o SMFL e puxa oq é preciso

add_executable(MeuRPG src/main.cpp) <- vamos criar no projeto um executavel (adicionar todos os .cpp dps) 
ex.: 
add_executable(RPG
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Map.cpp
)

target_link_libraries(RPG PRIVATE SFML::Graphics SFML::Window SFML::System) <- fala que o executavel precisa dessas bibliotecas do SFML


### vcpkg
O vcpkg é um gerenciador de bibliotecas C/C++.

Pensa nele como uma mistura conceitual de: pip + requirements.txt do Python.

Você pode dizer:

- vcpkg install sfml

e ele instala a SFML e as dependências necessárias.

"name": "meu-rpg" <- nome do nosso projeto
"version-string": "0.1.0" <- versão do projeto
"dependencies": ["sfml"] <- dependencias


## CMakePresets


"CMAKE_TOOLCHAIN_FILE": "$env{HOME}/dev/vcpkg/scripts/buildsystems/vcpkg.cmake"<- aponta para o arquivo do vcpkg que permite ao CMake conversar com o vcpkg.


### Vs Code
O VS Code será simplesmente seu ambiente de desenvolvimento.


## Instaladas no Sistema
g++ --version
cmake --version
git --version
vcpkg --version

## Tamanho de Pixel Art Utilizada

16 x 16
32 x 32 Talvez depois