/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Pause
*/

#include "../../include/States/Pause.hpp"

bool Pause::CheckMouse(Vector2 mouse, Raylib::Rectangle rect, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        rect.Draw(50, 50, RED);
        if (state == 1)
            DrawText(_playAgain.c_str(), _screenWidth / static_cast<float>(4.7), _screenHeight / static_cast<float>(1.35), (_screenWidth / 16) - (_screenHeight / 21), BLACK);
        if (state == 2)
            DrawText(_backMenu.c_str(), _screenWidth / static_cast<float>(1.65), _screenHeight / static_cast<float>(1.35), (_screenWidth / 18) - (_screenHeight / 24), BLACK);
        if (state == 3)
            DrawText(_resume.c_str(), _screenWidth / 2.5, _screenHeight / 2.35, (_screenWidth / 11) - (_screenHeight / 17), BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return true;
    }
    return false;
}

Pause::Pause(int nbPlayer, int nbIA, const std::vector<std::string> &map, int skinChoicePl1, int skinChoicePl2)
{
    _skinChoicePl1 = skinChoicePl1;
    _skinChoicePl2 = skinChoicePl2;

    _bg = LoadTexture("../assets/pictures/bg.png");

    _music.LoadMusic("../assets/music/pause.mp3");
    _music.Play();

    _button.Load("../assets/sound/button.wav");

    _nbPlayer = nbPlayer;
    _nbIA = nbIA;
    _map = map;
}

Pause::~Pause()
{
}

void Pause::Draw()
{
    DrawTexture(_bg, 0, 0, RAYWHITE);
    DrawRectangleRounded(_rectAgain, 50, 50, RAYWHITE);
    DrawRectangleRounded(_rectBack, 50, 50, RAYWHITE);
    DrawRectangleRounded(_rectResume, 50, 50, RAYWHITE);
}

void Pause::Update()
{
    _music.Update();

    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();

    _mouse = GetMousePosition();
    DrawText(_pauseText.c_str(), _screenWidth / 2.8, _screenHeight / 6.8, (_screenWidth / 8) - (_screenHeight / 13), RAYWHITE);

    _rectAgain = {_screenWidth / static_cast<float>(5.5), _screenHeight / static_cast<float>(1.4), _screenWidth / 4, _screenHeight / 9};
    DrawText(_playAgain.c_str(), _screenWidth / 4.7, _screenHeight / 1.35, (_screenWidth / 16) - (_screenHeight / 21), BLACK);
    _rectBack = {_screenWidth / static_cast<float>(1.7), _screenHeight / static_cast<float>(1.4), _screenWidth / 4, _screenHeight / 9};
    DrawText(_backMenu.c_str(), _screenWidth / 1.65, _screenHeight / 1.35, (_screenWidth / 19) - (_screenHeight / 25), BLACK);
    _rectResume = {_screenWidth / static_cast<float>(3.3), _screenHeight / static_cast<float>(2.5), _screenWidth / static_cast<float>(2.5), _screenHeight / 7};
    DrawText(_resume.c_str(), _screenWidth / 2.5, _screenHeight / 2.35, (_screenWidth / 11) - (_screenHeight / 17), BLACK);
}

void Pause::Clear()
{
    ClearBackground(RAYWHITE);
}

void Pause::HandleInput()
{
    if (CheckMouse(_mouse, _rectAgain, 1) == true)
    {
        _button.Play();
        _context->TransitionTo(new Game(_nbPlayer, _nbIA, _skinChoicePl1, _skinChoicePl2));
    }
    if (CheckMouse(_mouse, _rectBack, 2) == true)
    {
        _button.Play();
        _context->TransitionTo(new Menu);
    }
    if (CheckMouse(_mouse, _rectResume, 3) == true)
    {
        _button.Play();
        _context->TransitionTo(new Game(_nbPlayer, _nbIA, _map, _skinChoicePl1, _skinChoicePl2));
    }
}

void Pause::Reset()
{
}