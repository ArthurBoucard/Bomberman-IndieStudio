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

void HowToPlay::Draw()
{
    _bg.Draw({0, 0}, 0, _scale, WHITE);
}

void HowToPlay::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();

    _scale = _screenWidth / _bg.getWidth();
}

void HowToPlay::Clear()
{
    ClearBackground(RAYWHITE);
}

void HowToPlay::HandleInput()
{}

void HowToPlay::Reset()
{}


void HowToPlay::UpdateScale()
{
    _scale = _scale / _bg.getWidth() * _screenWidth;
}
