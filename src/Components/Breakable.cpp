/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Breakable
*/

#include "../../include/Components/Breakable.hpp"

Breakable::Breakable()
{
}

Breakable::~Breakable()
{
}

void Breakable::link(int id)
{
    _link = id;
}

int Breakable::getLink() const
{
    return _link;
}

void Breakable::breakBrick()
{
    //Spawn power-UP
}
