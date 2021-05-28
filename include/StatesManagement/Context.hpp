/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Context
*/

#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

#include <iostream>
#include "State.hpp"

class Context
{
    private:
        State *_state;

    public:
        Context(State *state);

        ~Context();

    void TransitionTo(State *state);

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();
};

#endif /* !CONTEXT_HPP_ */
