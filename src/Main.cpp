/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Main
*/

#include "../include/Main.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 1)
            throw Exception("invalid number of arguments");
    }
    catch(Exception const& e) {
        std::cerr << "ERROR : " << e.what() << std::endl;
        exit(84);
    }

    Bomberman bomberman;
    bomberman.GameLoop();

    return 0;
}

