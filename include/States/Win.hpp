/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Win
*/

#ifndef WIN_HPP_
#define WIN_HPP_

#include "State.hpp"

class Win : public State
{
    public:
        Win();
        ~Win();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

    private:
};

#endif /* !WIN_HPP_ */
