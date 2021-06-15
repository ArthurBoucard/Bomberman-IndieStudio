/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** GameOver
*/

#include "../../include/States/GameOver.hpp"

GameOver::GameOver()
{
    _musicEnd = LoadMusicStream("../assets/music/endGame.mp3");
    PlayMusicStream(_musicEnd);
}

GameOver::~GameOver()
{
}

bool GameOver::CheckMouse(Vector2 mouse, Rectangle rect, std::string text, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        DrawRectangleRounded(rect, 50, 50, BLACK);
        if (state == 1)
            DrawText(text.c_str(), rect.x + _screenWidth / 50, rect.y + _screenHeight / 25, (_screenWidth / 20) - (_screenHeight / 23), WHITE);
        if (state == 2)
            DrawText(text.c_str(), rect.x + _screenWidth / 25, rect.y + _screenHeight / 25, (_screenWidth / 20) - (_screenHeight / 23), WHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return true;
    }
    return false;
}

void GameOver::Draw()
{
    DrawText(_gameOver.c_str(), _screenWidth / static_cast<float>(4.5), _screenHeight / 4, (_screenWidth / 8) - (_screenHeight / 15), WHITE);
    DrawRectangleRounded(_rectBack, 50, 50, WHITE);
    DrawRectangleRounded(_rectAgain, 50, 50, WHITE);
}

void GameOver::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
    _mouse = GetMousePosition();
    _rectBack = {_screenWidth / 6, _screenHeight / static_cast<float>(1.5), _screenWidth / 4, _screenHeight / 8};
    _rectAgain = {_screenWidth / static_cast<float>(1.8), _screenHeight / static_cast<float>(1.5), _screenWidth / 4, _screenHeight / 8};

    DrawText(_back.c_str(), _rectBack.x + _screenWidth / 50, _rectBack.y + _screenHeight / 25, (_screenWidth / 20) - (_screenHeight / 23), BLACK);
    DrawText(_again.c_str(), _rectAgain.x + _screenWidth / 25, _rectAgain.y + _screenHeight / 25, (_screenWidth / 20) - (_screenHeight / 23), BLACK);
    UpdateMusicStream(_musicEnd);
}

void GameOver::Clear()
{
    ClearBackground(BLACK);
}

void GameOver::HandleInput()
{
    if (CheckMouse(_mouse, _rectBack, _back.c_str(), 1) == true)
        _context->TransitionTo(new Menu);
    if (CheckMouse(_mouse, _rectAgain, _again.c_str(), 2) == true)
        _context->TransitionTo(new Menu);
}

void GameOver::Reset()
{
}