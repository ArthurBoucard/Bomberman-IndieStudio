/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Bomberman
*/

#include "../include/Bomberman.hpp"

Bomberman::Bomberman()
{
}

Bomberman::~Bomberman()
{
}

void Bomberman::GameLoop()
{
    Context *context = new Context(new Menu);
    Raylib::Window window(1000, 650, "Indie Studio");

    while (!window.ShouldClose()) {
        BeginDrawing();
            context->Draw();
            context->Clear();
        EndDrawing();
        // context->TransitionTo(new Game);
        // usleep(1000000);
    }
}