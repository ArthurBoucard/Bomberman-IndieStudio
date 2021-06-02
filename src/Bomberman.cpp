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
    Context *context = new Context(new Introduction());
    Raylib::Window window(GetScreenWidth(), GetScreenHeight(), "Indie studio");

    while (!window.ShouldClose()) {
        BeginDrawing();
            context->Draw();
            context->Update();
            context->Clear();
        EndDrawing();
    }

    CloseAudioDevice();
}