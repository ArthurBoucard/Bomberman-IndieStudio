/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Game
*/

#include "../../include/States/Game.hpp"

Game::Game(int nbPlayer, int nbIA)
{
    srand (time(NULL));
    Map map = Map();

    _nbPlayer = nbPlayer;
    _nbIA = nbIA;

    map.createMap();
    map.proceduralGenClassical();
    map.placePlayers(_nbPlayer, _nbIA);
    _map = map.getMap();

    Texture2D brickT = LoadTexture("../assets/pictures/block.png");
    Texture2D wallT = LoadTexture("../assets/pictures/wall.png");
    Texture2D grassT = LoadTexture("../assets/pictures/grass.png");

    _camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    _camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    _camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;

    ReadFiles();

    Model model1 = LoadModel("../assets/skin/guy.iqm");
    model1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin();

    Model model2 = LoadModel("../assets/skin/guy.iqm");
    model2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin();

    Model model3 = LoadModel("../assets/skin/guy.iqm");
    model3.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin();

    Model model4 = LoadModel("../assets/skin/guy.iqm");
    model4.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin();

    int whichAI = 0;

    for (float x = 0, w = 0; x < _map.size(); x++, w += 60) {
        for (float z = 0, h = 0; z < _map[x].size(); z++, h += 60) {
            if (_map[x][z] != 'X') {
                Entity *ground = new Entity;
                Position *pos = new Position(x, z, -1);
                pos->link(ground->getId());
                _positionList.push_back(pos);
                Texture2DComp *tex = new Texture2DComp(grassT);
                tex->link(ground->getId());
                _texture2DList.push_back(tex);
            }
            if (_map[x][z] == 'X') {
                Entity *wall = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(wall->getId());
                _positionList.push_back(pos);
                Texture2DComp *tex = new Texture2DComp(wallT);
                tex->link(wall->getId());
                _texture2DList.push_back(tex);
                Solid *solid = new Solid();
                solid->link(wall->getId());
                _solidList.push_back(solid);
            }
            if (_map[x][z] == '#') {
                Entity *brick = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(brick->getId());
                _positionList.push_back(pos);
                Breakable *br = new Breakable;
                br->link(brick->getId());
                _breakableList.push_back(br);
                Texture2DComp *tex = new Texture2DComp(brickT);
                tex->link(brick->getId());
                _texture2DList.push_back(tex);
                Solid *solid = new Solid();
                solid->link(brick->getId());
                _solidList.push_back(solid);
            }
            if (_map[x][z] == '@') {
                Entity *AI = new Entity;                            //Entity
                Position *pos = new Position(x, z, 0);              //Position
                pos->link(AI->getId());
                _positionList.push_back(pos);
                Player *pl = new Player("AI", 2);                   //Player
                pl->link(AI->getId());
                _playerList.push_back(pl);
                Model3D *mod = new Model3D();                       //Model3D
                if (whichAI == 0)
                    mod->setModel(model3);
                else
                    mod->setModel(model4);
                mod->link(AI->getId());
                _model3DList.push_back(mod);
                Jump *jp = new Jump();                              //Jump
                jp->link(AI->getId());
                _jumpList.push_back(jp);
                whichAI++;
            }
            if (_map[x][z] == '0' || _map[x][z] == '1') {
                Entity *player = new Entity;                        //Entity
                Position *pos = new Position(x, z, 0);              //Position
                pos->link(player->getId());
                _positionList.push_back(pos);
                Player *pl = new Player("player", _map[x][z] - 48); //Player
                pl->link(player->getId());
                _playerList.push_back(pl);
                Model3D *mod = new Model3D();                       //Model3D
                if (_map[x][z] == '0')
                    mod->setModel(model1);
                else
                    mod->setModel(model2);
                mod->link(player->getId());
                _model3DList.push_back(mod);
                Jump *jp = new Jump();                              //Jump
                jp->link(player->getId());
                _jumpList.push_back(jp);
            }
        }
    }
}

Game::~Game()
{
    for (std::size_t i = 0; i < _model3DList.size(); i++)
        UnloadModel(_model3DList[i]->getModel());
}

void Game::Draw()
{
    //Animation of bomb placement
    for (std::size_t i = 0, j = 0; i < _jumpList.size(); i++, j = 0) {
        for (j = 0; _jumpList[i]->getLink() != _model3DList[j]->getLink(); j++) {}
        if (_jumpList[i]->getJump()) {
            _jumpList[i]->setFrameCount(_jumpList[i]->getFrameCount() + 1);
            UpdateModelAnimation(_model3DList[j]->getModel(), _jumpList[i]->getAnim(), _jumpList[i]->getFrameCount());
            if (_jumpList[i]->getFrameCount() >= _jumpList[i]->getAnim().frameCount) {
                _jumpList[i]->setFrameCount(0);
                _jumpList[i]->setJump(false);
            }
        }
    }
    BeginMode3D(_camera);
        for (std::size_t i = 0, j = 0; i < _positionList.size(); i++, j = 0) {
            // Draw Texture
            for (j = 0; j < _texture2DList.size(); j++)
                if (_texture2DList[j]->getLink() == _positionList[i]->getLink())
                    DrawCubeTexture(_texture2DList[j]->getTexture(),
                        (Vector3){_positionList[i]->getX() - 6,
                            _positionList[i]->getZ(),
                                _positionList[i]->getY() - 9},
                                    1, 1, 1, WHITE);
            // Draw Model3D
            for (j = 0; j < _model3DList.size(); j++)
                if (_model3DList[j]->getLink() == _positionList[i]->getLink())
                    DrawModelEx(_model3DList[j]->getModel(),
                        (Vector3){_positionList[i]->getX() - 6,
                            _positionList[i]->getZ() - 0.5f,
                                _positionList[i]->getY() - 9},
                                    (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f,
                                        (Vector3){ 0.15f, 0.15f, 0.15f }, WHITE);
            // Draw Bomb
            for (j = 0; j < _bombList.size(); j++) {
                if (_bombList[j]->getLink() == _positionList[i]->getLink()) {
                    DrawSphere({_positionList[i]->getX() - 6,
                        _positionList[i]->getZ() - 0.1f,
                            _positionList[i]->getY() - 9},
                                0.4f, DARKGRAY);
                    DrawSphereWires({_positionList[i]->getX() - 6,
                        _positionList[i]->getZ() - 0.1f,
                            _positionList[i]->getY() - 9},
                                0.4f, 16, 16, BLACK);
                }
            }
            // Draw Flame
            for (j = 0; j < _flameList.size(); j++) {
                if (_flameList[j]->getLink() == _positionList[i]->getLink()) {
                    DrawSphere({_positionList[i]->getX() - 6,
                        _positionList[i]->getZ() - 0.1f,
                            _positionList[i]->getY() - 9},
                                0.35f, RED);
                    DrawSphereWires({_positionList[i]->getX() - 6,
                        _positionList[i]->getZ() - 0.1f,
                            _positionList[i]->getY() - 9},
                                0.35f, 16, 16, ORANGE);
                }
            }
        }
    EndMode3D();
}

void Game::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();

    for (std::size_t i = 0; i < _bombList.size(); i++) {
        clock_t end = clock();
        if (end - _bombList[i]->getClock() >= 900000)
            _bombList[i]->setIsExplode(true);
    }
    // Make bomb explode
    for (std::size_t i = 0, p = 0; i < _bombList.size(); i++) {
        if (_bombList[i]->getIsExplode()) {
            for (p = 0; _bombList[i]->getLink() != _positionList[p]->getLink(); p++) {}
            for (int dir = 1; dir <= 4; dir++) {
                Entity *flame = new Entity;
                Flame *fl = new Flame(_bombList[i]->getRadius(), dir, *_positionList[p]);
                fl->link(flame->getId());
                _flameList.push_back(fl);
                Position *pos = new Position(_positionList[p]->getX(), _positionList[p]->getY(), _positionList[p]->getZ());
                pos->link(flame->getId());
                _positionList.push_back(pos);
            }
            deleteEntity(_bombList[i]->getLink());
        }
    }
    // Move flames of exploded bomb
    for (std::size_t i = 0, p = 0, p2 = 0, k = 0, m = 0; i < _flameList.size(); i++) {
        clock_t end = clock();
        if (end - _flameList[i]->getClock() >= 30000) {
            _flameList[i]->resetClock();
            if (_flameList[i]->getDist() == 0) {
                deleteEntity(_flameList[i]->getLink());
                break;
            }
            for (p = 0; _flameList[i]->getLink() != _positionList[p]->getLink(); p++) {}
            _flameList[i]->move();
            if (_flameList[i]->getDirection() == 1) {
                _positionList[p]->setX(_positionList[p]->getX() - 1);
                for (k = 0; k < _solidList.size(); k++) {
                    for (p2 = 0; p2 < _positionList.size(); p2++) {
                        if (_positionList[p]->getX() == _positionList[p2]->getX() &&
                            _positionList[p]->getY() == _positionList[p2]->getY() &&
                            _positionList[p]->getZ() == _positionList[p2]->getZ()) {
                            if (_solidList[k]->getLink() == _positionList[p2]->getLink()) {
                                for (m = 0; m < _breakableList.size(); m++)
                                    if (_breakableList[m]->getLink() == _positionList[p2]->getLink()) {
                                        _breakableList[m]->breakBrick();
                                        deleteEntity(_breakableList[m]->getLink());
                                    }
                                deleteEntity(_flameList[i]->getLink());
                                break;
                            }
                        }
                    }
                }
            } else if (_flameList[i]->getDirection() == 2) {
                _positionList[p]->setY(_positionList[p]->getY() + 1);
                for (k = 0; k < _solidList.size(); k++) {
                    for (p2 = 0; p2 < _positionList.size(); p2++) {
                        if (_positionList[p]->getX() == _positionList[p2]->getX() &&
                            _positionList[p]->getY() == _positionList[p2]->getY() &&
                            _positionList[p]->getZ() == _positionList[p2]->getZ()) {
                            if (_solidList[k]->getLink() == _positionList[p2]->getLink()) {
                                for (m = 0; m < _breakableList.size(); m++)
                                    if (_breakableList[m]->getLink() == _positionList[p2]->getLink()) {
                                        _breakableList[m]->breakBrick();
                                        deleteEntity(_breakableList[m]->getLink());
                                    }
                                deleteEntity(_flameList[i]->getLink());
                                break;
                            }
                        }
                    }
                }
            } else if (_flameList[i]->getDirection() == 3) {
                _positionList[p]->setX(_positionList[p]->getX() + 1);
                for (k = 0; k < _solidList.size(); k++) {
                    for (p2 = 0; p2 < _positionList.size(); p2++) {
                        if (_positionList[p]->getX() == _positionList[p2]->getX() &&
                            _positionList[p]->getY() == _positionList[p2]->getY() &&
                            _positionList[p]->getZ() == _positionList[p2]->getZ()) {
                            if (_solidList[k]->getLink() == _positionList[p2]->getLink()) {
                                for (m = 0; m < _breakableList.size(); m++)
                                    if (_breakableList[m]->getLink() == _positionList[p2]->getLink()) {
                                        _breakableList[m]->breakBrick();
                                        deleteEntity(_breakableList[m]->getLink());
                                    }
                                deleteEntity(_flameList[i]->getLink());
                                break;
                            }
                        }
                    }
                }
            } else if (_flameList[i]->getDirection() == 4) {
                _positionList[p]->setY(_positionList[p]->getY() - 1);
                for (k = 0; k < _solidList.size(); k++) {
                    for (p2 = 0; p2 < _positionList.size(); p2++) {
                        if (_positionList[p]->getX() == _positionList[p2]->getX() &&
                            _positionList[p]->getY() == _positionList[p2]->getY() &&
                            _positionList[p]->getZ() == _positionList[p2]->getZ()) {
                            if (_solidList[k]->getLink() == _positionList[p2]->getLink()) {
                                for (m = 0; m < _breakableList.size(); m++)
                                    if (_breakableList[m]->getLink() == _positionList[p2]->getLink()) {
                                        _breakableList[m]->breakBrick();
                                        deleteEntity(_breakableList[m]->getLink());
                                    }
                                deleteEntity(_flameList[i]->getLink());
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::Clear()
{
    ClearBackground(RAYWHITE);
}

void Game::HandleInput()
{
    Vector2 mouse = GetMousePosition();

    // PLayer control
    if (_nbPlayer > 0) {
        for (std::size_t i = 0, j = 0; i < _playerList.size(); i++) {
            if (_playerList[i]->getPlayerID() == 0) {
                for (j = 0; _playerList[i]->getLink() != _positionList[j]->getLink(); j++) {}
                if (IsKeyDown(KEY_A))
                    _positionList[j]->setX(_positionList[j]->getX() - _speed);
                if (IsKeyDown(KEY_D))
                    _positionList[j]->setX(_positionList[j]->getX() + _speed);
                if (IsKeyDown(KEY_W))
                    _positionList[j]->setY(_positionList[j]->getY() - _speed);
                if (IsKeyDown(KEY_S))
                    _positionList[j]->setY(_positionList[j]->getY() + _speed);
                break;
            }
        }
    }
    if (_nbPlayer == 2) {
        for (std::size_t i = 0, j = 0; i < _playerList.size(); i++) {
            if (_playerList[i]->getPlayerID() == 1) {
                for (j = 0; _playerList[i]->getLink() != _positionList[j]->getLink(); j++) {}
                if (IsKeyDown(KEY_LEFT))
                    if (testCollision(4, j))
                        _positionList[j]->setX(_positionList[j]->getX() - _speed);
                if (IsKeyDown(KEY_RIGHT))
                    if (testCollision(2, j))
                        _positionList[j]->setX(_positionList[j]->getX() + _speed);
                if (IsKeyDown(KEY_UP))
                    if (testCollision(1, j))
                        _positionList[j]->setY(_positionList[j]->getY() - _speed);
                if (IsKeyDown(KEY_DOWN))
                    if (testCollision(3, j))
                        _positionList[j]->setY(_positionList[j]->getY() + _speed);
                break;
            }
        }
    }
    // Bombs
    if (IsKeyPressed(KEY_Q) && _nbPlayer > 0)
        spawnBomb(0);
    if (IsKeyPressed(KEY_RIGHT_SHIFT) && _nbPlayer == 2)
        spawnBomb(1);
}

void Game::Reset()
{
}

Texture2D Game::getSkin()
{
    int r = rand() % (_files.size() - 1);

    std::string str = "../assets/skin/texture/" + _files[r];

    _files.erase(_files.begin() + r);
    return LoadTexture(str.c_str());
}

void Game::ReadFiles()
{

    DIR *dir; struct dirent *diread;

    if ((dir = opendir("../assets/skin/texture")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            _files.push_back(diread->d_name);
        }
        closedir (dir);
    }

    std::vector<std::string>::iterator it;

    it = find(_files.begin(), _files.end(), ".");
    if (it != _files.end()) {
        int index = std::distance(_files.begin(), it);
        _files.erase(_files.begin() + index);
    }

    it = find(_files.begin(), _files.end(), "..");
    if (it != _files.end()) {
        int index = std::distance(_files.begin(), it);
        _files.erase(_files.begin() + index);
    }
}

void Game::spawnBomb(int nbPlayer)
{
    for (std::size_t i = 0, j = 0, k = 0; i < _playerList.size(); i++) {
        if (_playerList[i]->getPlayerID() == nbPlayer) {
            for (j = 0; _playerList[i]->getLink() != _positionList[j]->getLink(); j++) {}
            // bool isBomb = false;                                                        //
            // for (std::size_t k = 0; k < _bombList.size(); k++)                          //
            //     if (_bombList[k]->getPlayerLink() == _playerList[i]->getLink())         // Verify that a bomb already exist
            //         isBomb = true;                                                      // = only one bomb per player for
            // if (!isBomb) {                                                              // the moment
                Entity *bomb = new Entity;
                Position *pos = new Position(round(_positionList[j]->getX()), round(_positionList[j]->getY()), round(_positionList[j]->getZ()));
                pos->link(bomb->getId());
                _positionList.push_back(pos);
                Bomb *b = new Bomb(3);
                b->link(bomb->getId());
                b->linkPlayer(_playerList[i]->getLink());
                _bombList.push_back(b);
            // }
            for (k = 0; _playerList[i]->getLink() != _jumpList[k]->getLink(); k++) {}
            _jumpList[k]->setJump(true);
            _jumpList[k]->setFrameCount(0);
        }
    }
}

bool Game::testCollision(int direction, int pPos) // 1 = UP | 2 = RIGHT | 3 = DOWN | 4 = LEFT
{
    std::size_t sPos;
    std::size_t bPos;

    if (_lastWall != direction && _lastWall != 0) {
        _lastWall = 0;
        return true;
    }

    for (bPos = 0; bPos < _solidList.size(); bPos++) {
        for (sPos = 0; _solidList[bPos]->getLink() != _positionList[sPos]->getLink(); sPos++) {}
        if (round(_positionList[pPos]->getX()) == _positionList[sPos]->getX() &&
            round(_positionList[pPos]->getY()) == _positionList[sPos]->getY()) {
            _lastWall = direction;
            return false;
            }
    }
    _lastWall = 0;
    return true;
}

void Game::deleteEntity(int id)
{
    int i;

    for (i = 0; i < _positionList.size(); i++)
        if (_positionList[i]->getLink() == id)
            _positionList.erase(_positionList.begin() + i);
    for (i = 0; i < _breakableList.size(); i++)
        if (_breakableList[i]->getLink() == id)
            _breakableList.erase(_breakableList.begin() + i);
    for (i = 0; i < _texture2DList.size(); i++)
        if (_texture2DList[i]->getLink() == id)
            _texture2DList.erase(_texture2DList.begin() + i);
    for (i = 0; i < _playerList.size(); i++)
        if (_playerList[i]->getLink() == id)
            _playerList.erase(_playerList.begin() + i);
    for (i = 0; i < _model3DList.size(); i++)
        if (_model3DList[i]->getLink() == id)
            _model3DList.erase(_model3DList.begin() + i);
    for (i = 0; i < _jumpList.size(); i++)
        if (_jumpList[i]->getLink() == id)
            _jumpList.erase(_jumpList.begin() + i);
    for (i = 0; i < _bombList.size(); i++)
        if (_bombList[i]->getLink() == id)
            _bombList.erase(_bombList.begin() + i);
    for (i = 0; i < _solidList.size(); i++)
        if (_solidList[i]->getLink() == id)
            _solidList.erase(_solidList.begin() + i);
    for (i = 0; i < _flameList.size(); i++)
        if (_flameList[i]->getLink() == id)
            _flameList.erase(_flameList.begin() + i);
}
