/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Menu
*/

#include "../../include/States/Menu.hpp"

Menu::Menu()
{
    _music_menu = LoadMusicStream("../assets/music/music_menu.mp3");
    PlayMusicStream(_music_menu);
    _bg = LoadTexture("../assets/pictures/bg.png");
}

Menu::~Menu()
{
}

bool Menu::CheckMouse(Vector2 mouse, Rectangle rect, const char *text, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        DrawRectangleRounded(rect, 50, 50, RED);
        if (state == 1)
            DrawText(text, rect.x + _screenWidth / 40, rect.y + _screenHeight / 30, (_screenWidth / 17) - (_screenHeight / 20), BLACK);
        if (state == 2)
            DrawText(text, rect.x + _screenWidth / 40, rect.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
        if (state == 3)
            DrawText(text, rect.x + _screenWidth / 90, rect.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
        if (state == 4)
            DrawText(text, rect.x + _screenWidth / 20, rect.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return true;
    }
    return false;
}

void Menu::Draw()
{
    DrawTexture(_bg, 0, 0, RAYWHITE);
    DrawRectangleRounded(_rect_game, 50, 50, RAYWHITE);
    DrawRectangleRounded(_rect_settings, 50, 50, RAYWHITE);
    DrawRectangleRounded(_rect_tuto, 50, 50, RAYWHITE);
    DrawRectangleRounded(_rect_stat, 50, 50, RAYWHITE);
}

void Menu::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
    _mouse = GetMousePosition();

    _rect_game = {_screenWidth / (float)2.7, _screenHeight / (float)2, _screenWidth / 4, _screenHeight / 8};
    _rect_settings = {_screenWidth / (float)6, _screenHeight / (float)1.3, _screenWidth / 6, _screenHeight / 10};
    _rect_tuto = {_screenWidth / (float)2.4, _screenHeight / (float)1.3, _screenWidth / (float)5.5, _screenHeight / (float)10};
    _rect_stat = {_screenWidth / (float)1.45, _screenHeight / (float)1.3, _screenWidth / (float)5.5, _screenHeight / (float)10};

    DrawText(_title, _screenWidth / (float)4.5, _screenHeight / 6, (_screenWidth / 8) - (_screenHeight / 15), WHITE);
    DrawText(_play_game, _rect_game.x + _screenWidth / 40, _rect_game.y + _screenHeight / 30, (_screenWidth / 17) - (_screenHeight / 20), BLACK);
    DrawText(_settings, _rect_settings.x + _screenWidth / 40, _rect_settings.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
    DrawText(_tuto, _rect_tuto.x + _screenWidth / 90, _rect_tuto.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
    DrawText(_stat, _rect_stat.x + _screenWidth / 20, _rect_tuto.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
    UpdateMusicStream(_music_menu);
}

void Menu::Clear()
{
    ClearBackground(RAYWHITE);
}

void Menu::HandleInput()
{
    if (CheckMouse(_mouse, _rect_game, _play_game, 1) == true)
        _context->TransitionTo(new GameOver);
    if (CheckMouse(_mouse, _rect_settings, _settings, 2) == true)
        printf("Settings\n");
    if (CheckMouse(_mouse, _rect_tuto, _tuto, 3) == true)
        printf("Tuto\n");
    if (CheckMouse(_mouse, _rect_stat, _stat, 4) == true)
        printf("Stat\n");
}

void Menu::Reset()
{
}