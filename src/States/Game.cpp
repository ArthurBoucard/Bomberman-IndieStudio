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
}

Game::~Game()
{
}

void Game::Draw()
{
    BeginMode3D(_camera);
        for (float x = 0, w = 0; x < _map.size(); x++, w += 60) {
            for (float z = 0, h = 0; z < _map[x].size(); z++, h += 60) {
                if (_map[x][z] == ' ')
                    DrawCubeTexture(_grass, (Vector3){x-6, -1, z-9}, 1, 1, 1, WHITE);
                else if (_map[x][z] == 'X')
                    DrawCubeTexture(_wall, (Vector3){x-6, 0, z-9}, 1, 1, 1, WHITE);
                else if (_map[x][z] == '#') {
                    DrawCubeTexture(_brick, (Vector3){x-6, 0, z-9}, 1, 1, 1, WHITE);
                    Entity *brick = new Entity;
                    Position pos(x, z);
                    brick->addComponents(pos);
                    _brickList.push_back(brick);
                }
            }
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
}

void Game::Reset()
{
}