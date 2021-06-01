/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Introduction
*/

#include "../../include/States/Introduction.hpp"

Introduction::Introduction()
{
}

Introduction::~Introduction()
{
    // UnloadTexture(bouboule);
}

void Introduction::Draw()
{
    Texture2D bouboule = LoadTexture("./assets/img/Bouboule.png");

    DrawTexture(bouboule, 1000/2 - bouboule.width/2, 650/2 - bouboule.height/2, WHITE);
}

void Introduction::Update()
{}

void Introduction::Clear()
{
    ClearBackground(RAYWHITE);
}

void Introduction::HandleInput()
{}

void Introduction::Reset()
{}