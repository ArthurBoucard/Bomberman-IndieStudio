/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Menu
*/

#include "../../include/States/Menu.hpp"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Draw()
{
    DrawText("Bomberman!", 190, 200, 20, BLACK);
}

void Menu::Update()
{}

void Menu::Clear()
{
    ClearBackground(RAYWHITE);
}

void Menu::HandleInput()
{}

void Menu::Reset()
{}