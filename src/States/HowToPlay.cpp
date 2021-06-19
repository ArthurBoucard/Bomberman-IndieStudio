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
   Vector2 pos = {0, 0};
    _bg.Draw(pos, 0, _scale, WHITE);
}

void HowToPlay::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
    if (IsWindowResized())
        UpdateScale();
}

void HowToPlay::Clear()
{}

void HowToPlay::HandleInput()
{}

void HowToPlay::Reset()
{}


void HowToPlay::UpdateScale()
{
    _scale = _scale / _bg.getWidth() * _screenWidth;  
}
