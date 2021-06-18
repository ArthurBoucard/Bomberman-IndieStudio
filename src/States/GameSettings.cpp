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
    _verif = 0;
    _skinChoicePl1 = 0;
    _skinChoicePl2 = 0;

    _button.Load("../assets/sound/button.wav");
}

GameSettings::~GameSettings()
{
}

bool GameSettings::CheckMouse(Vector2 mouse, Rectangle rect, const char *text, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        if (state == 2 && _nbTotalPlayers > 1 && _nbTotalPlayers <= 4)
            DrawText(text, _screenWidth / 1.1, _screenHeight / 1.2, (_screenWidth / 7) - (_screenHeight / 10), GRAY);
        if (state == 3)
            DrawText(text, _screenWidth / 2.5, _screenHeight / 1.15, (_screenWidth / 10) - (_screenHeight / 15), GRAY);
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
    if (_verif == 0)
    {
        DrawText(_nbPlayersText.c_str(), _screenWidth / 3.8, _screenHeight / 6, (_screenWidth / 12) - (_screenHeight / 18), WHITE);
        DrawText(std::to_string(_nbPlayers).c_str(), _screenWidth / 2, _screenHeight / static_cast<float>(2.6), (_screenWidth / 10) - (_screenHeight / 15), WHITE);
        if (_nbPlayers > 0)
        {
            DrawText("-", _screenWidth / 3, _screenHeight / 2.6, (_screenWidth / 10) - (_screenHeight / 15), WHITE);
            _rectMiPlayers = {_screenWidth / 3, _screenHeight / static_cast<float>(2.455), _screenWidth / 34, _screenHeight / 15};
        }
        if (_nbPlayers < 2 && _nbTotalPlayers != 4)
        {
            DrawText("+", _screenWidth / 1.5, _screenHeight / 2.6, (_screenWidth / 10) - (_screenHeight / 15), WHITE);
            _rectPlPlayers = {_screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(2.455), _screenWidth / 30, _screenHeight / 15};
        }

        DrawText(_nbIAText.c_str(), _screenWidth / 3, _screenHeight / 1.5, (_screenWidth / 12) - (_screenHeight / 18), WHITE);
        DrawText(std::to_string(_nbIA).c_str(), _screenWidth / 2, _screenHeight / 1.2, (_screenWidth / 10) - (_screenHeight / 15), WHITE);
        if (_nbIA > 0)
        {
            DrawText("-", _screenWidth / 3, _screenHeight / 1.2, (_screenWidth / 10) - (_screenHeight / 15), WHITE);
            _rectMiIA = {_screenWidth / 3, _screenHeight / static_cast<float>(1.17), _screenWidth / 34, _screenHeight / 15};
        }
        if (_nbIA < 4 && _nbTotalPlayers != 4)
        {
            DrawText("+", _screenWidth / 1.5, _screenHeight / 1.2, (_screenWidth / 10) - (_screenHeight / 15), WHITE);
            _rectPlIA = {_screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(1.17), _screenWidth / 30, _screenHeight / 15};
        }
        _nbTotalPlayers = _nbPlayers + _nbIA;
        if (_nbTotalPlayers > 1)
        {
            DrawText("=>", _screenWidth / 1.1, _screenHeight / 1.2, (_screenWidth / 7) - (_screenHeight / 10), WHITE);
            _rectValidate = {_screenWidth / static_cast<float>(1.1), _screenHeight / static_cast<float>(1.155), _screenWidth / 14, _screenHeight / 10};
        }
    }
    if (_verif == 1)
    {
        _rectMiIA = {};
        _rectMiPlayers = {};
        _rectPlIA = {};
        _rectPlPlayers = {};
        _rectValidate = {};
        if (_nbPlayers == 2)
        {
            DrawText("Choose your skin", _screenWidth / 4.2, _screenHeight / 7, (_screenWidth / 10) - (_screenHeight / 15), RAYWHITE);
            DrawText("Player 1 :", _screenWidth / 8, _screenHeight / 2.6, (_screenWidth / 15) - (_screenHeight / 17), RAYWHITE);
            DrawText("Player 2 :", _screenWidth / 8, _screenHeight / 1.5, (_screenWidth / 15) - (_screenHeight / 17), RAYWHITE);
            DrawText(">", _screenWidth / 1.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            _rectAfterPlayer1 = {_screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(2.455), _screenWidth / 30, _screenHeight / 15};
            DrawText("<", _screenWidth / 3, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            _rectPrevPlayer1 = {_screenWidth / 3, _screenHeight / static_cast<float>(2.455), _screenWidth / 34, _screenHeight / 15};
            DrawText(">", _screenWidth / 1.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            _rectAfterPlayer2 = {_screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(1.455), _screenWidth / 30, _screenHeight / 15};
            DrawText("<", _screenWidth / 3, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            _rectPrevPlayer2 = {_screenWidth / 3, _screenHeight / static_cast<float>(1.455), _screenWidth / 34, _screenHeight / 15};

            if (_skinChoicePl1 == 0)
                DrawText("RED", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), RED);
            if (_skinChoicePl1 == 1)
                DrawText("YELLOW", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), YELLOW);
            if (_skinChoicePl1 == 2)
                DrawText("WHITE", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            if (_skinChoicePl1 == 3)
                DrawText("GREEN", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), GREEN);
            if (_skinChoicePl1 == 4)
                DrawText("PURPLE", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), PURPLE);
            if (_skinChoicePl1 == 5)
                DrawText("PINK", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), PINK);
            if (_skinChoicePl1 == 6)
                DrawText("BLUE", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), BLUE);
            if (_skinChoicePl1 == 7)
                DrawText("BLACK", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), BLACK);
            if (_skinChoicePl1 == 8)
                DrawText("BROWN", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), BROWN);
            if (_skinChoicePl1 > 8)
                _skinChoicePl1 = 0;
            if (_skinChoicePl1 < 0)
                _skinChoicePl1 = 8;

            if (_skinChoicePl2 == 0)
                DrawText("RED", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), RED);
            if (_skinChoicePl2 == 1)
                DrawText("YELLOW", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), YELLOW);
            if (_skinChoicePl2 == 2)
                DrawText("WHITE", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            if (_skinChoicePl2 == 3)
                DrawText("GREEN", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), GREEN);
            if (_skinChoicePl2 == 4)
                DrawText("PURPLE", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), PURPLE);
            if (_skinChoicePl2 == 5)
                DrawText("PINK", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), PINK);
            if (_skinChoicePl2 == 6)
                DrawText("BLUE", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), BLUE);
            if (_skinChoicePl2 == 7)
                DrawText("BLACK", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), BLACK);
            if (_skinChoicePl2 == 8)
                DrawText("BROWN", _screenWidth / 2.5, _screenHeight / 1.5, (_screenWidth / 11) - (_screenHeight / 16), BROWN);
            if (_skinChoicePl2 > 8)
                _skinChoicePl2 = 0;
            if (_skinChoicePl2 < 0)
                _skinChoicePl2 = 8;
        }
        if (_nbPlayers == 1)
        {
            DrawText("Choose your skin", _screenWidth / 4.2, _screenHeight / 7, (_screenWidth / 10) - (_screenHeight / 15), RAYWHITE);
            DrawText("Player :", _screenWidth / 8, _screenHeight / 2.6, (_screenWidth / 15) - (_screenHeight / 17), RAYWHITE);
            DrawText(">", _screenWidth / 1.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            _rectAfterPlayer1 = {_screenWidth / static_cast<float>(1.5), _screenHeight / static_cast<float>(2.455), _screenWidth / 30, _screenHeight / 15};
            DrawText("<", _screenWidth / 3, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            _rectPrevPlayer1 = {_screenWidth / 3, _screenHeight / static_cast<float>(2.455), _screenWidth / 34, _screenHeight / 15};

            if (_skinChoicePl1 == 0)
                DrawText("RED", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), RED);
            if (_skinChoicePl1 == 1)
                DrawText("YELLOW", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), YELLOW);
            if (_skinChoicePl1 == 2)
                DrawText("WHITE", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), WHITE);
            if (_skinChoicePl1 == 3)
                DrawText("GREEN", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), GREEN);
            if (_skinChoicePl1 == 4)
                DrawText("PURPLE", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), PURPLE);
            if (_skinChoicePl1 == 5)
                DrawText("PINK", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), PINK);
            if (_skinChoicePl1 == 6)
                DrawText("BLUE", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), BLUE);
            if (_skinChoicePl1 == 7)
                DrawText("BLACK", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), BLACK);
            if (_skinChoicePl1 == 8)
                DrawText("BROWN", _screenWidth / 2.5, _screenHeight / 2.6, (_screenWidth / 11) - (_screenHeight / 16), BROWN);
            if (_skinChoicePl1 > 8)
                _skinChoicePl1 = 0;
            if (_skinChoicePl1 < 0)
                _skinChoicePl1 = 8;
            _skinChoicePl2 = -1;
        }
        if (_nbPlayers == 0)
        {
            _skinChoicePl1 = -1;
            _skinChoicePl2 = -1;
        }
        if (_skinChoicePl1 != _skinChoicePl2)
        {
            DrawText("PLAY", _screenWidth / 2.5, _screenHeight / 1.15, (_screenWidth / 10) - (_screenHeight / 15), WHITE);
            _rectPlay = {_screenWidth / static_cast<float>(2.5), _screenHeight / static_cast<float>(1.15), _screenWidth / 6, _screenHeight / static_cast<float>(10.5)};
        }
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
        _button.Play();
        _nbPlayers++;
    }
    if (CheckMouse(_mouse, _rectMiPlayers, "", 1) == true && _nbPlayers > 0)
    {
        _button.Play();
        _nbPlayers--;
    }
    if (CheckMouse(_mouse, _rectPlIA, "", 1) == true && _nbIA < 4 && _nbTotalPlayers != 4)
    {
        _button.Play();
        _nbIA++;
    }
    if (CheckMouse(_mouse, _rectMiIA, "", 1) == true && _nbIA > 0)
    {
        _button.Play();
        _nbIA--;
    }
    if (CheckMouse(_mouse, _rectValidate, "=>", 2) == true && _nbTotalPlayers > 1 && _verif == 0)
    {
        _button.Play();
        _verif = 1;
    }
    if (CheckMouse(_mouse, _rectPrevPlayer1, "", 1) == true && _verif == 1)
    {
        _button.Play();
        _skinChoicePl1--;
    }
    if (CheckMouse(_mouse, _rectAfterPlayer1, "", 1) == true && _verif == 1)
    {
        _button.Play();
        _skinChoicePl1++;
    }
    if (CheckMouse(_mouse, _rectPrevPlayer2, "", 1) == true && _verif == 1)
    {
        _button.Play();
        _skinChoicePl2--;
    }
    if (CheckMouse(_mouse, _rectAfterPlayer2, "", 1) == true && _verif == 1)
    {
        _button.Play();
        _skinChoicePl2++;
    }
    if (CheckMouse(_mouse, _rectValidate, "=>", 2) && _nbPlayers == 0 && _verif == 1)
    {
        _button.Play();
        _context->TransitionTo(new Game(_nbPlayers, _nbIA, _skinChoicePl1, _skinChoicePl2));
    }
    if (CheckMouse(_mouse, _rectPlay, "PLAY", 3) && _verif == 1)
    {
        _button.Play();
        _context->TransitionTo(new Game(_nbPlayers, _nbIA, _skinChoicePl1, _skinChoicePl2));
    }
}

void GameSettings::Reset()
{
}