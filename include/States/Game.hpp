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
#include "../States/Pause.hpp"
#include "../Map/Map.hpp"
#include "../Components/Entity.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

class Game : public State
{
public:
    Game(int nbPlayer, int nbIA, int skin1, int skin2);
    Game(int nbPlayer, int nbIA, const std::vector<std::string> &map, const std::vector<std::string> &saveSkin);
    ~Game();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();
    void moveAi(std::size_t positionIndex, std::size_t playerIndex);

    Texture2D getSkin(int);
    Texture2D getSkin();

    void spawnBomb(int nbPlayer);
    bool testCollision(int dir, Position *pos);
    void deleteEntity(int id);

    void saveMap();

private:
    float _screenWidth;
    float _screenHeight;

    int _nbPlayer;
    int _nbIA;
    Rectangle _rectGame;
    std::vector<std::string> _map;
    std::vector<std::string> _saveMap;
    std::vector<std::string> _saveSkin;

    int _skinChoicePl1;
    int _skinChoicePl2;

    Camera _camera = {0};

    float _speed = 0.05;

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

    std::vector<int> _skin = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Raylib::Music _music;
    Raylib::Sound _poseBomb;
    Raylib::Sound _explosionBomb;
    Raylib::Sound _deathPlayer;
};

#endif /* !GAME_HPP_ */
