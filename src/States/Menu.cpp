/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Menu
*/

#include "../../include/States/Menu.hpp"

Menu::Menu()
{
    _settingsText = LoadTexture("../assets/pictures/settings.png");
    _statText = LoadTexture("../assets/pictures/stat.png");
    _questText = LoadTexture("../assets/pictures/question.png");
    _bg = LoadTexture("../assets/pictures/bg.png");
}

Menu::~Menu()
{
}

bool Menu::CheckMouse(Vector2 mouse, Rectangle rect, const char *text, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        if (state == 1)
        {
            DrawRectangleRounded(rect, 50, 50, RED);
            DrawText(text, rect.x + 25, rect.y + 25, 50, BLACK);
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return true;
    }
    return false;
}

void Menu::Draw()
{
    DrawTexture(_bg, 0, 0, RAYWHITE);
    DrawTextureRec(_settingsText, _settingsRect, _settingsVect, BLUE);
    DrawTextureRec(_statText, _statRect, _statVect, BLUE);
    DrawTextureRec(_questText, _questRect, _questVect, BLUE);
    DrawRectangleRounded(_rect_game, 50, 50, RAYWHITE);
    DrawText(_play_game, _rect_game.x + 25, _rect_game.y + 25, 50, BLACK);
    DrawText(_title, _screenWidth / 4, _screenHeight / 6, 80, WHITE);
}

void Menu::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
    _mouse = GetMousePosition();
    _rect_game = {_screenWidth / (float)3.2, _screenHeight / 2, _screenWidth / 4, _screenHeight / 8};

    _settingsRect = {192, 512, 64, 64};
    _settingsVect = {192, 512};

    _statRect = {702, 512, 64, 64};
    _statVect = {702, 512};

    _questRect = {448, 512, 64, 64};
    _questVect = {448, 512};
}

void Menu::Clear()
{
    ClearBackground(RAYWHITE);
}

void Menu::HandleInput()
{
    if (CheckMouse(_mouse, _rect_game, _play_game, 1) == true)
        _context->TransitionTo(new Game);
    if (CheckMouse(_mouse, _statRect, _empty, 0) == true)
    {
        printf("OK\n");
    }
}

void Menu::Reset()
{
}