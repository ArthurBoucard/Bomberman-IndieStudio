/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Pause
*/

#ifndef PAUSE_HPP_
#define PAUSE_HPP_

#include "../StatesManagement/State.hpp"

class Pause : public State
{
    public:
        Pause();
        ~Pause();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

    private:
};

#endif /* !PAUSE_HPP_ */
