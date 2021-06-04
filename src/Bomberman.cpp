/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Bomberman
*/

#include "../include/Bomberman.hpp"

Bomberman::Bomberman()
{
    InitAudioDevice();
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);
}

Bomberman::~Bomberman()
{
}

void Bomberman::GameLoop()
{
    Raylib::Window window(GetScreenWidth(), GetScreenHeight(), "Indie studio");
    Context *context = new Context(new Introduction());

    while (!window.ShouldClose()) {
        BeginDrawing();
            context->Clear();
            context->Draw();
            context->Update();
            context->HandleInput();
        EndDrawing();
    }
    CloseAudioDevice();
}
