/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include <utility>

#include "Components.hpp"

class Position : public Components {
    public:
        Position(int posX, int posY, int posZ);
        ~Position();

        void link(int id);
        int getLink();
        int getX();
        int getY();
        int getZ();
    protected:
        int _link;
        int _x;
        int _y;
        int _z;
    private:
};

#endif /* !POSITION_HPP_ */
