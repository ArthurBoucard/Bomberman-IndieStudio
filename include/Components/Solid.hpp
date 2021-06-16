/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Solid
*/

#ifndef SOLID_HPP_
#define SOLID_HPP_

#include "Components.hpp"
#include "../Raylib/Raylib.hpp"

class Solid {
    public:
        Solid();
        ~Solid();

        void link(int id);
        int getLink();

    protected:
        int _link;
    private:
};

#endif /* !SOLID_HPP_ */
