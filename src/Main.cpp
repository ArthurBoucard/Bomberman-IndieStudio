/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Main
*/

#include "../include/Main.hpp"

int main(int ac, char **av)
{
    if (ac != 1)
        return 84;

    Bomberman bomberman;
    bomberman.GameLoop();

    return 0;
}

