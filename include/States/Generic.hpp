/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Generic
*/

#ifndef GENERIC_HPP_
#define GENERIC_HPP_

#include "State.hpp"

class Generic : public State
{
    public:
        Generic();
        ~Generic();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

    private:
};

#endif /* !GENERIC_HPP_ */
