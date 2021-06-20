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
<<<<<<< HEAD
{
    _bg.Draw({0, 0}, 0, _scale, WHITE);
=======
{    
   Vector2 pos = {0, 0};
    _bg.Draw(pos, 0, _scale, WHITE);
>>>>>>> 81da35adc7dca01ec50754e29b801b5d2ef5a685
}

void HowToPlay::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
<<<<<<< HEAD

    _scale = _screenWidth / _bg.getWidth();
=======
    if (IsWindowResized())
        UpdateScale();
>>>>>>> 81da35adc7dca01ec50754e29b801b5d2ef5a685
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
