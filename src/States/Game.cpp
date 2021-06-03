/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Game
*/

#include "../../include/States/Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Draw()
{
    DrawText("We are Rocket League", 450, 100, 25, RED);
    DrawRectangleRounded(_rectGame, 50, 50, BLUE);
}

void Game::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();

    _rectGame = {_screenWidth / 4, _screenHeight / 4, 350, 100};
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