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

float Position::getX()
{
    return _x;
}

float Position::getY()
{
    return _y;
}

float Position::getZ()
{
    return _z;
}

void Position::setX(float x)
{
    _x = x;
}

void Position::setY(float y)
{
    _y = y;
}

void Position::setZ(float z)
{
    _z = z;
}
