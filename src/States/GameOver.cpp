/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** GameOver
*/

#include "../../include/States/GameOver.hpp"

GameOver::GameOver()
{
    _bgGameOver = LoadTexture("../assets/pictures/GameOver.png");
}

GameOver::~GameOver()
{
}

void GameOver::Draw()
{
    DrawTexture(_bgGameOver, 0, 0, RAYWHITE);
}

void GameOver::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
}

void GameOver::Clear()
{
}

void GameOver::HandleInput()
{
}

void GameOver::Reset()
{
}