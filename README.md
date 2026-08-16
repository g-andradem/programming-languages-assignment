# programming-languages-assignment

## Ferramentas Utilizadas
SFML + CMake + vcpkg + VS Code.

# 🎮 SFML
É a biblioteca que fornece as funcionalidades do jogo

- janela
- teclado/mouse
- gráficos 2D
- sprites/texturas
- áudio
- fontes
- eventos
- etc.

# ⚙️ Entendendo o `CMakeLists.txt`

O `CMakeLists.txt` é o arquivo responsável por configurar como o projeto será compilado e quais bibliotecas serão utilizadas.

### 1. Versão mínima do CMake

```cmake
cmake_minimum_required(VERSION 3.20)
```

Define a **versão mínima do CMake** necessária para compilar o projeto.

---

### 2. Nome do projeto

```cmake
project(MeuRPG)
```

Define o nome do projeto como `MeuRPG`.

---

### 3. Versão do C++

```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

Define que o projeto utilizará o **C++17**.

* `CMAKE_CXX_STANDARD 17` → seleciona o C++17.
* `CMAKE_CXX_STANDARD_REQUIRED ON` → exige que o compilador suporte C++17.

---

### 4. Encontrando o SFML

```cmake
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)
```

Procura a **SFML 3** instalada no sistema e solicita os componentes necessários:

| Componente | Função                                          |
| ---------- | ----------------------------------------------- |
| `Graphics` | Sprites, texturas, fontes, desenhos etc.        |
| `Window`   | Janelas e gerenciamento de eventos              |
| `System`   | Vetores, tempo e outras funcionalidades básicas |

O `REQUIRED` significa que o CMake considera o SFML **obrigatório**. Se ele não for encontrado, a configuração do projeto falhará.

---

### 5. Adicionando os arquivos `.cpp`

```cmake
add_executable(MeuRPG src/main.cpp)
```

Cria o executável `MeuRPG` utilizando o arquivo `main.cpp`.

Conforme o projeto cresce, podemos adicionar os outros arquivos `.cpp`:

```cmake
add_executable(MeuRPG
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Map.cpp
)
```

> 💡 Cada novo arquivo `.cpp` que fizer parte da compilação pode ser adicionado aqui.

---

### 6. Bibliotecas necessárias

```cmake
target_link_libraries(
    MeuRPG
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
```

Informa ao CMake que o executável `MeuRPG` precisa das bibliotecas do SFML.

* `SFML::Graphics` → recursos gráficos.
* `SFML::Window` → janela e eventos.
* `SFML::System` → funcionalidades básicas do SFML.
* `PRIVATE` → essas dependências são necessárias para o próprio executável.

# ⚙️ Vcpkg
O vcpkg é um gerenciador de bibliotecas C/C++.

Mistura conceitual de: pip + requirements.txt do Python.

* `"name": "meu-rpg"` → nome do nosso projeto
* `"version-string": "0.1.0"` → versão do projeto
* `"dependencies": ["sfml"]` → dependencias


# ⚙️ Sobre o CMakePresets

```cmake
"CMAKE_TOOLCHAIN_FILE": "$env{HOME}/dev/vcpkg/scripts/buildsystems/vcpkg.cmake"
```
aponta para o arquivo do vcpkg que permite ao CMake conversar com o vcpkg.

```
{
    "version": 6,
    "configurePresets": [
        {
            "name": "default",
            "displayName": "RPG Default",
            "generator": "Ninja",
            "binaryDir": "${sourceDir}/build",
            "cacheVariables": {
                "CMAKE_TOOLCHAIN_FILE": "CAMINHO DO VCPKG.CMAKE"
            }
        }
    ]
}
```

* `$env{HOME}/Projects/tools/vcpkg/scripts/buildsystems/vcpkg.cmake Exemplo de Caminho` → Exemplo de Caminho

> 💡 CMakePresets esta no .GitIgnore, tem um caminho proprio que cada pessoa deve possuir

# 💻 Ambiente de Desenvolvimento

### Vs Code

# 💾 Instalados no Sistema

### Comandos para Conferir as Versoes

- g++ --version
- cmake --version
- git --version
- vcpkg --version

### Comandos para o vcpkg

* `mkdir -p ~/dev` → Criar Pasta
* `cd ~/dev` → Entrar na Pasta
* `git clone https://github.com/microsoft/vcpkg.git` → Clonar o Repositorio
* `cd ~/dev/vcpkg` → Entrar na Pasta do vcpkg

`sudo pacman -Syu base-devel git curl zip unzip tar cmake ninja` → Se necessario instalar para o proximo passo

* `./bootstrap-vcpkg.sh` → Executar o Instalador
* `echo 'export PATH="$HOME/dev/vcpkg:$PATH"' >> ~/.bashrc` → Fazer o vcpkg ser universal
* `source ~/.bashrc` → Atualizar

### Comandos para o SFML

* `cd ~/Projects/RPG` → Abra o Projeto
* `vcpkg install` → Instale

### Comandos para o CMake

* `cmake --preset default` → Coloca o CMake como padrao
* `cmake --build build` → Constroi o Jogo
* `./build/MeuRPG` → Abre o Jogo
* `cmake --build build && ./build/MeuRPG` → Constroi o Jogo/Atualiza o Jogo e Abre

# 📝 Anotacoes

### Tamanho de Pixel Art Utilizada

16 x 16
32 x 32 Talvez depois


# 🏗️ Divisão do Projeto

(Ver pelo arquivo .md)

meu-jogo/
│
├── CMakeLists.txt
├── CMakePresets.json
├── .gitignore
│
├── assets/
│   ├── textures/
│   │   ├── player/
│   │   ├── enemies/
│   │   ├── tiles/
│   │   ├── maps/
│   │   └── ui/
│   │
│   ├── fonts/
│   │
│   ├── sounds/
│   │   ├── music/
│   │   └── sfx/
│   │
│   └── data/
│       ├── maps/
│       ├── enemies/
│       ├── items/
│       └── characters/
│
├── src/
│   ├── main.cpp
│   │
│   ├── core/ (core/ → cérebro do jogo, Aqui ficam coisas que controlam o funcionamento geral)
│   │   ├── Game.hpp
│   │   ├── Game.cpp
│   │   ├── GameState.hpp
│   │   ├── GameState.cpp
│   │   ├── GameTime.hpp
│   │   └── GameTime.cpp
│   │
│   ├── player/ (player/ → personagem, Tudo relacionado ao personagem principal)
│   │   ├── Player.hpp
│   │   ├── Player.cpp
│   │   ├── Character.hpp
│   │   └── Character.cpp
│   │
│   ├── enemies/
│   │   ├── Enemy.hpp
│   │   ├── Enemy.cpp
│   │   ├── EnemyManager.hpp
│   │   └── EnemyManager.cpp
│   │
│   ├── world/
│   │   ├── Map.hpp
│   │   ├── Map.cpp
│   │   ├── Tile.hpp
│   │   ├── Tile.cpp
│   │   ├── World.hpp
│   │   └── World.cpp
│   │
│   ├── screens/
│   │   ├── MainMenu.hpp
│   │   ├── MainMenu.cpp
│   │   ├── GameScreen.hpp
│   │   ├── GameScreen.cpp
│   │   ├── TutorialScreen.hpp
│   │   ├── TutorialScreen.cpp
│   │   ├── CharacterCustomization.hpp
│   │   ├── CharacterCustomization.cpp
│   │   ├── ScoreScreen.hpp
│   │   └── ScoreScreen.cpp
│   │
│   ├── ui/
│   │   ├── Button.hpp
│   │   ├── Button.cpp
│   │   ├── Label.hpp
│   │   ├── Label.cpp
│   │   └── UIManager.hpp
│   │
│   ├── systems/
│   │   ├── CollisionSystem.hpp
│   │   ├── CollisionSystem.cpp
│   │   ├── InputSystem.hpp
│   │   ├── InputSystem.cpp
│   │   ├── AnimationSystem.hpp
│   │   └── AnimationSystem.cpp
│   │
│   └── utils/
│       ├── ResourceManager.hpp
│       ├── ResourceManager.cpp
│       ├── Constants.hpp
│       └── Utils.hpp
│
├── saves/
│
├── build/                 ← .gitignore
└── vcpkg_installed/       ← .gitignore