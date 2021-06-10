/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Game
*/

#include "../../include/States/Game.hpp"

Game::Game(int nbPlayer, int nbIA)
{
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

    Model model = LoadModel("../assets/pictures/guy.iqm");
    _texture = LoadTexture("../assets/pictures/guytex.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;

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
            }
            if (_map[x][z] == '#') {
                Entity *brick = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(brick->getId());
                _positionList.push_back(pos);
                Breakable *br = new Breakable;
                br->link(brick->getId());
                Texture2DComp *tex = new Texture2DComp(brickT);
                tex->link(brick->getId());
                _texture2DList.push_back(tex);
            }
            if (_map[x][z] == '@') {
                Entity *AI = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(AI->getId());
                _positionList.push_back(pos);
                Player *pl = new Player("AI", 0);
                pl->link(AI->getId());
                _playerList.push_back(pl);
                Model3D *mod = new Model3D(model);
                mod->link(AI->getId());
                _model3DList.push_back(mod);
            }
            if (_map[x][z] == '0' || _map[x][z] == '1') {
                Entity *player = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(player->getId());
                _positionList.push_back(pos);
                Player *pl = new Player("player", _map[x][z] - 48);
                pl->link(player->getId());
                _playerList.push_back(pl);
                Model3D *mod = new Model3D(model);
                mod->link(player->getId());
                _model3DList.push_back(mod);
            }
        }
    }
}

Game::~Game()
{
}

void Game::Draw()
{
    BeginMode3D(_camera);
        for (std::size_t i = 0, j = 0; i < _positionList.size(); i++, j = 0) {
            // Draw Texture
            bool isTexture2D = false;
            for (j = 0; j < _texture2DList.size(); j++) {
                if (_texture2DList[j]->getLink() == _positionList[i]->getLink()) {
                    isTexture2D = true;
                    break;
                }
            }
            if (isTexture2D)
                DrawCubeTexture(_texture2DList[j]->getTexture(),
                    (Vector3){_positionList[i]->getX() - 6,
                        _positionList[i]->getZ(),
                            _positionList[i]->getY() - 9},
                                1, 1, 1, WHITE);
            // Draw Model
            bool isModel3D = false;
            for (j = 0; j < _model3DList.size(); j++) {
                if (_model3DList[j]->getLink() == _positionList[i]->getLink()) {
                    isModel3D = true;
                    break;
                }
            }
            if (isModel3D)
                DrawModelEx(_model3DList[j]->getModel(),
                    (Vector3){_positionList[i]->getX() - 6,
                        _positionList[i]->getZ(),
                            _positionList[i]->getY() - 9},
                                (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f,
                                    (Vector3){ 0.15f, 0.15f, 0.15f }, WHITE);
        }
        // if (IsKeyDown(KEY_RIGHT_SHIFT)) {
        //     Vector3 pos = { _position.x, _position.y + 0.3f, _position.z};
        //     DrawSphere(pos, 0.3, DARKGRAY);
        //     DrawSphereWires(pos, 0.3, 16, 16, BLACK);
        // }
    EndMode3D();
}

void Game::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();

    _rectGame = {_screenWidth / 2, _screenHeight / 2, 350, 100};
}

void Game::Clear()
{
    ClearBackground(RAYWHITE);
}

void Game::HandleInput()
{
    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, _rectGame))
    {
        DrawRectangleRounded(_rectGame, 50, 50, RED);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            _context->TransitionTo(new Menu);
    }

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
                    _positionList[j]->setX(_positionList[j]->getX() - _speed);
                if (IsKeyDown(KEY_RIGHT))
                    _positionList[j]->setX(_positionList[j]->getX() + _speed);
                if (IsKeyDown(KEY_UP))
                    _positionList[j]->setY(_positionList[j]->getY() - _speed);
                if (IsKeyDown(KEY_DOWN))
                    _positionList[j]->setY(_positionList[j]->getY() + _speed);
                break;
            }
        }
    }
}

void Game::Reset()
{
}