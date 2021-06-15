/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Solid
*/

#include "../../include/Components/Solid.hpp"

Solid::Solid()
{
}

Solid::~Solid()
{
}

void Solid::link(int id)
{
    _link = id;
}

int Solid::getLink()
{
    return _link;
}
