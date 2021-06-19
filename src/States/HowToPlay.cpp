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
    Vector2 pos = {(_screenWidth / 2 - _bg.getWidth() / 2 * _scale), (_screenHeight / 2 - _bg.getHeight() / 2 * _scale)};
    _bg.Draw(pos, 0, _scale, WHITE);

   // DrawTextureEx(_bg, {0, 0}, 0, 1, WHITE);
       // _bg.Draw(0, 0, RAYWHITE);

}

void HowToPlay::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
}

void HowToPlay::Clear()
{}

void HowToPlay::HandleInput()
{}

void HowToPlay::Reset()
{}