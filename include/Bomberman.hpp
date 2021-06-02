/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Bomberman
*/

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include <iostream>

#include "Raylib/Raylib.hpp"
#include "StatesManagement/Context.hpp"
#include "StatesManagement/State.hpp"
#include "States/Menu.hpp"
#include "States/Game.hpp"

class Bomberman
{
    public:
        Bomberman();
        ~Bomberman();

        void GameLoop();

    protected:
    private:
};

#endif /* !BOMBERMAN_HPP_ */
