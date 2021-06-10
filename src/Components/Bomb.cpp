/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Bomb
*/

#include "../../include/Components/Bomb.hpp"

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

void Bomb::link(int id)
{
    _link = id;
}

void Bomb::linkPlayer(int id)
{
    _playerLink = id;
}

int Bomb::getLink()
{
    return _link;
}

int Bomb::getPlayerLink()
{
    return _playerLink;
}

int Bomb::getRadius()
{
    return _radius;
}

int Bomb::getTimeLeft()
{
    return _timeLeft;
}
