/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Game
*/

#include "../../include/States/Game.hpp"

Game::Game()
{
    Map map = Map();

    map.createMap();
    map.proceduralGenClassical();
    _map = map.getMap();

    _brick = LoadTexture("../assets/pictures/block.png");
    _wall = LoadTexture("../assets/pictures/wall.png");
    _grass = LoadTexture("../assets/pictures/grass.png");

    _camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    _camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    _camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;

    _model = LoadModel("../assets/pictures/guy.iqm");
    _texture = LoadTexture("../assets/pictures/guytex.png");
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
    _position = { -4.5, 0.0f, 4.25};

    _spherePos = { -4.5f, 0.0f, 4.25f };
}

Game::~Game()
{
}

void Game::Draw()
{
    BeginMode3D(_camera);
    for (float x = 0, w = 0; x < _map.size(); x++, w += 60)
    {
        for (float z = 0, h = 0; z < _map[x].size(); z++, h += 60)
        {
            if (_map[x][z] == ' ')
                DrawCubeTexture(_grass, (Vector3){x-6, -1, z-9}, 1, 1, 1, WHITE);
            if (_map[x][z] == 'X')
                DrawCubeTexture(_wall, (Vector3){x-6, 0, z-9}, 1, 1, 1, WHITE);
            if (_map[x][z] == '#')
                DrawCubeTexture(_brick, (Vector3){x-6, 0, z-9}, 1, 1, 1, WHITE);
        }
    }
    DrawModelEx(_model, _position, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 0.15f, 0.15f, 0.15f }, WHITE);

    if (IsKeyDown(KEY_RIGHT_SHIFT)) {
        Vector3 pos = { _position.x, _position.y + 0.3f, _position.z};
        DrawSphere(pos, 0.3, DARKGRAY);
        DrawSphereWires(pos, 0.3, 16, 16, BLACK);
    }

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

    if (IsKeyDown(KEY_LEFT))
    {
        _position.x -= _speed;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        _position.x += _speed;
    }
    if (IsKeyDown(KEY_UP))
    {
        _position.z -= _speed;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        _position.z += _speed;
    }
}

void Game::Reset()
{
}