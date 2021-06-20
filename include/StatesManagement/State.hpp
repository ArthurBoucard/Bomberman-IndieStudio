/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** IStates
*/

#ifndef ISTATES_HPP_
#define ISTATES_HPP_

#include <iostream>
#include <typeinfo>

#include "../Raylib/Raylib.hpp"

class Context;

class State {
    public:
        Context *_context = nullptr;

    public:
        virtual ~State() {};

        void SetContext(Context *context)
        {
            _context = context;
        }

        virtual void Draw() = 0;
        virtual void Update() = 0;
        virtual void Clear() = 0;
        virtual void HandleInput() = 0;
        virtual void Reset() = 0;
};

#endif /* !ISTATES_HPP_ */
