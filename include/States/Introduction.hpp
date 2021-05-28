/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Introduction
*/

#ifndef INTRODUCTION_HPP_
#define INTRODUCTION_HPP_

#include "State.hpp"

class Introduction : public State
{
    public:
        Introduction();
        ~Introduction();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

    private:
};

#endif /* !INTRODUCTION_HPP_ */
