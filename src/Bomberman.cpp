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

    //exemple de gameloop
    while(1)
    {
        context->Draw();
        context->Clear();
        context->TransitionTo(new Game); //changement de states
        usleep(1000000);
    }
}