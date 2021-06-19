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
    //DrawTextureEx(_bg, {_screenWidth, _screenHeight}, 0, 0, WHITE);
        _bg.Draw(0, 0, RAYWHITE);

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