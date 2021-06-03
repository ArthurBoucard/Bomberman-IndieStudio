/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Introduction
*/

#include "../../include/States/Introduction.hpp"

Introduction::Introduction()
{
    _music.LoadMusic("../assets/music/poutine.mp3");
    _music.Play();
    _bouboule.LoadFile("../assets/pictures/Bouboule.png");

    _scrennHeight = GetScreenHeight();
    _scrennWidth = GetScreenWidth();
}

Introduction::~Introduction()
{
}

void Introduction::Draw()
{
    Vector2 pos = {(_scrennWidth / 2 - _bouboule.getWidth() / 2 * _scale), (_scrennHeight / 2 - _bouboule.getHeight() / 2 * _scale)};
    _bouboule.DrawEx(pos, 0, _scale, WHITE);
}

void Introduction::Update()
{
    _music.Update();
    UpdateScale();
}

void Introduction::Clear()
{
    ClearBackground(RAYWHITE);
}

void Introduction::HandleInput()
{
    if (IsKeyPressed(KEY_SPACE))
        _context->TransitionTo(new Menu);
}

void Introduction::Reset()
{
}

void Introduction::UpdateScale()
{
    if ((_bouboule.getWidth() / 2 * _scale) < _scrennWidth + 20)
        _scale = _scale - 0.0001;
    else
        _scale = _scale - 0.014;

    if ((_bouboule.getWidth() / 2 * _scale) < _scrennWidth)
        _context->TransitionTo(new Menu);
}