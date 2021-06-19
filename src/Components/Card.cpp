/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Card
*/

#include "../../include/Components/Card.hpp"

Card::Card()
{
}

Card::~Card()
{
}

void Card::link(int id)
{
    _link = id;
}

int Card::getLink()
{
    return _link;
}
