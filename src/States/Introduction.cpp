/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Introduction
*/

#include "../../include/States/Introduction.hpp"

Introduction::Introduction()
{
    _width = 10000;
    _height = 10000 / 2.9;

    bouboule = Raylib::Texture("../assets/img/Bouboule.png");
    music = LoadMusicStream("../assets/music/poutine.mp3");
    PlayMusicStream(music);
}

Introduction::~Introduction()
{
}

void Introduction::Draw()
{
    Vector2 pos = {(GetScreenWidth()/2 - bouboule.getWidth()/2 * scale), (GetScreenHeight()/2 - bouboule.getHeight()/2 * scale)};
    DrawTextureEx(bouboule, pos, 0, scale, WHITE);

    UpdateScale();
}

void Introduction::Update()
{
    UpdateMusicStream(music);
}

void Introduction::Clear()
{
    ClearBackground(RAYWHITE);
}

void Introduction::HandleInput()
{}

void Introduction::Reset()
{}

void Introduction::UpdateScale()
{
    if ((bouboule.getWidth()/2 * scale) < GetScreenWidth() + 20)
        scale = scale - 0.0001;
    else
        scale = scale - 0.014;

    if ((bouboule.getWidth()/2 * scale) < GetScreenWidth())
        _context->TransitionTo(new Menu);
}