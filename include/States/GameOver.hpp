/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** GameOver
*/

#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_

#include "State.hpp"

class GameOver : public State
{
    public:
        GameOver();
        ~GameOver();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

    private:
};

#endif /* !GAMEOVER_HPP_ */
