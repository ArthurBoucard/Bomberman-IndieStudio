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
        Position() {}
        Position(int posX, int posY, int posZ);
        ~Position();

        void link(int id);
        int getLink();
        float getX();
        float getY();
        float getZ();
        void setX(float x);
        void setY(float y);
        void setZ(float z);
    protected:
        int _link;
        float _x;
        float _y;
        float _z;
    private:
};

#endif /* !POSITION_HPP_ */
