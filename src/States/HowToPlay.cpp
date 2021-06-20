/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** HowToPlay
*/

#include "../../include/States/HowToPlay.hpp"

HowToPlay::HowToPlay()
{
    _bg.LoadFile("../assets/pictures/howtoplay.png");
}

HowToPlay::~HowToPlay()
{
}

bool HowToPlay::CheckMouse(Raylib::Vector2 mouse, Raylib::Rectangle rect, Raylib::Text text, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        rect.Draw(50, 50, BLACK);
        if (state == 1)
            _textBack.Draw(rect.x + _screenWidth / 30, rect.y + _screenHeight / 60, (_screenWidth / 13) - (_screenHeight / 15), PINK);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return true;
    }
    return false;
}

void HowToPlay::Draw()
{
    _bg.Draw({0, 0}, 0, _scale, WHITE);
    _back.Draw(50, 50, WHITE);
    _textBack = "Back";
}

void HowToPlay::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
    _mouse = GetMousePosition();

    _back = {_screenWidth / static_cast<float>(4.3), _screenHeight / static_cast<float>(12), _screenWidth / 6, _screenHeight / 10};
    _textBack.Draw(_back.x + _screenWidth / 30, _back.y + _screenHeight / 60, (_screenWidth / 13) - (_screenHeight / 15), BLACK);
    _scale = _screenWidth / _bg.getWidth();
}

void HowToPlay::Clear()
{
    ClearBackground(RAYWHITE);
}

void HowToPlay::HandleInput()
{
    if (CheckMouse(_mouse, _back, _textBack, 1) == true)
        _context->TransitionTo(new Menu);
}

void HowToPlay::Reset()
{
}

void HowToPlay::UpdateScale()
{
    _scale = _scale / _bg.getWidth() * _screenWidth;
}
