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
    float screenWidth = GetScreenWidth();
    float screenHeight = GetScreenHeight();
    DrawText("We are Rocket League", 450, 100, 25, RED);
    Rectangle rect_game = {screenWidth / 4, screenHeight / 4, 350, 100};
    DrawRectangleRounded(rect_game, 50, 50, BLUE);
    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, rect_game))
    {
        DrawRectangleRounded(rect_game, 50, 50, RED);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            _context->TransitionTo(new Menu);
    }
}

void Game::Update()
{
}

void Game::Clear()
{
    ClearBackground(RAYWHITE);
}

void Game::HandleInput()
{
}

void Game::Reset()
{
}