/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Solid
*/

#ifndef SOLID_HPP_
#define SOLID_HPP_

#include "Components.hpp"
#include "Position.hpp"
#include "../Raylib/Raylib.hpp"

class Solid {
    public:
        Solid();
        ~Solid();

        void link(int id);
        int getLink();
        void updateRect(Position pos);
        Rectangle getRect();

    protected:
        int _link;
        Rectangle _rect;
    private:
};

#endif /* !SOLID_HPP_ */
