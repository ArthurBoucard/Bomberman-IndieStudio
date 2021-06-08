/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Position
*/

#include "../../include/Components/Position.hpp"

Position::Position(int posX, int posY, int posZ)
{
    _x = posX;
    _y = posY;
    _z = posZ;
}

Position::~Position()
{
}

void Position::link(int id)
{
    _link = id;
}

int Position::getLink()
{
    return _link;
}

int Position::getX()
{
    return _x;
}

int Position::getY()
{
    return _y;
}

int Position::getZ()
{
    return _z;
}
