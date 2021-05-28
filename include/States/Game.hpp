/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "State.hpp"

class Game : public State
{
    public:
        Game();
        ~Game();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

    private:
};

#endif /* !GAME_HPP_ */
