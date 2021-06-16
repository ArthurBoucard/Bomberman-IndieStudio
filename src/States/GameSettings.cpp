/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** GameSettings
*/

#include "../../include/States/GameSettings.hpp"
#include <string>

GameSettings::GameSettings()
{
    _bg = LoadTexture("../assets/pictures/bg.png");
    _nbIA = 0;
    _nbPlayers = 0;

    _button = LoadSound("../assets/sound/button.wav");
}

GameSettings::~GameSettings()
{
}

bool GameSettings::CheckMouse(Vector2 mouse, Rectangle rect, const char *text, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        if (state == 2)
            DrawText(text, _screenWidth / static_cast<float>(1.1), _screenHeight / static_cast<float>(1.2), (_screenWidth / 7) - (_screenHeight / 10), GRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return true;
    }
    return false;
}

void GameSettings::Draw()
{
    DrawTexture(_bg, 0, 0, RAYWHITE);
}

void GameSettings::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
    _mouse = GetMousePosition();

    DrawText(_nbPlayersText.c_str(), _screenWidth / static_cast<float>(3.8), _screenHeight / 6, (_screenWidth / 12) - (_screenHeight / 18), WHITE);
    DrawText(std::to_string(_nbPlayers).c_str(), _screenWidth / 2, _screenHeight / static_cast<float>(2.6), (_screenWidth / 10) - (_screenHeight / 15), WHITE);
    if (_nbPlayers > 0)
    {
        DrawText("-", _screenWidth / 3, _screenHeight / static_cast<float>(2.6), (_screenWidth / 10) - (_screenHeight / 15), WHITE);
        _rectMiPlayers = {_screenWidth / 3, _screenHeight / static_cast<float>(2.455), _screenWidth / 34, _screenHeight / 15};
    }
    if (_nbPlayers < 2 && _nbTotalPlayers != 4)
    {
        DrawText("+", _screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(2.6), (_screenWidth / 10) - (_screenHeight / 15), WHITE);
        _rectPlPlayers = {_screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(2.455), _screenWidth / 30, _screenHeight / 15};
    }

    DrawText(_nbIAText.c_str(), _screenWidth / 3, _screenHeight / static_cast<float>(1.5), (_screenWidth / 12) - (_screenHeight / 18), WHITE);
    DrawText(std::to_string(_nbIA).c_str(), _screenWidth / 2, _screenHeight / static_cast<float>(1.2), (_screenWidth / 10) - (_screenHeight / 15), WHITE);
    if (_nbIA > 0)
    {
        DrawText("-", _screenWidth / 3, _screenHeight / static_cast<float>(1.2), (_screenWidth / 10) - (_screenHeight / 15), WHITE);
        _rectMiIA = {_screenWidth / 3, _screenHeight / static_cast<float>(1.17), _screenWidth / 34, _screenHeight / 15};
    }
    if (_nbIA < 4 && _nbTotalPlayers != 4)
    {
        DrawText("+", _screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(1.2), (_screenWidth / 10) - (_screenHeight / 15), WHITE);
        _rectPlIA = {_screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(1.17), _screenWidth / 30, _screenHeight / 15};
    }
    _nbTotalPlayers = _nbPlayers + _nbIA;
    if (_nbTotalPlayers > 1)
    {
        DrawText("=>", _screenWidth / static_cast<float>(1.1), _screenHeight / static_cast<float>(1.2), (_screenWidth / 7) - (_screenHeight / 10), WHITE);
        _rectValidate = {_screenWidth / static_cast<float>(1.1), _screenHeight / static_cast<float>(1.155), _screenWidth / static_cast<float>(14), _screenHeight / 10};
    }
}

void GameSettings::Clear()
{
    ClearBackground(RAYWHITE);
}

void GameSettings::HandleInput()
{
    if (CheckMouse(_mouse, _rectPlPlayers, "", 1) == true && _nbPlayers < 2 && _nbTotalPlayers != 4)
    {
        PlaySound(_button);
        _nbPlayers++;
    }
    if (CheckMouse(_mouse, _rectMiPlayers, "", 1) == true && _nbPlayers > 0)
    {
        PlaySound(_button);
        _nbPlayers--;
    }
    if (CheckMouse(_mouse, _rectPlIA, "", 1) == true && _nbIA < 4 && _nbTotalPlayers != 4)
    {
        PlaySound(_button);
        _nbIA++;
    }
    if (CheckMouse(_mouse, _rectMiIA, "", 1) == true && _nbIA > 0)
    {
        PlaySound(_button);
        _nbIA--;
    }
    if (CheckMouse(_mouse, _rectValidate, "=>", 2) == true && _nbTotalPlayers > 1)
    {
        PlaySound(_button);
        _context->TransitionTo(new Game(_nbPlayers, _nbIA));
    }
}

void GameSettings::Reset()
{
}