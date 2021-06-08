/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Position
*/

#include "../../include/Components/Position.hpp"

Position::Position(int posX, int posY)
{
    _pos = {posX, posY};
}

Position::~Position()
{
}

std::pair<int, int> Position::getPos()
{
    return _pos;
}
