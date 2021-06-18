/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../StatesManagement/State.hpp"
#include "../StatesManagement/Context.hpp"
#include "../States/Menu.hpp"
#include "../Map/Map.hpp"
#include "../Components/Entity.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

class Game : public State {
    public:
        Game(int nbPlayer, int nbIA);
        ~Game();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();
        void moveAi(std::size_t positionIndex, std::size_t playerIndex);

        Texture2D getSkin();

        void ReadFiles();

        void spawnBomb(int nbPlayer);
        bool testCollision(int dir, Position *pos);
        void deleteEntity(int id);
    private:
        float _screenWidth;
        float _screenHeight;

        int _nbPlayer;
        int _nbIA;

        Rectangle _rectGame;
        std::vector<std::string> _map;

        Camera _camera = {0};

        int _lastWall = 0;
        bool _lastCol = true;
        int _lastDir = 0;

        std::vector<std::string> _files;

        std::vector<Position *> _positionList;
        std::vector<Breakable *> _breakableList;
        std::vector<Texture2DComp *> _texture2DList;
        std::vector<Player *> _playerList;
        std::vector<Model3D *> _model3DList;
        std::vector<Jump *> _jumpList;
        std::vector<Bomb *> _bombList;
        std::vector<Solid *> _solidList;
        std::vector<Flame *> _flameList;
        std::vector<PowerUp *> _powerUpList;

        std::vector<int> _skin = {1, 2, 3, 4, 5, 6, 7 ,8, 9};

        Raylib::Music _music;
        Sound _poseBomb;
};

#endif /* !GAME_HPP_ */
