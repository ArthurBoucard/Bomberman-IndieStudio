/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Bomb
*/

#include "../../include/Components/Bomb.hpp"

Bomb::Bomb(int radius)
{
    _clock = clock();
    _isExplode = false;
    _radius = radius;
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

bool Bomb::getIsExplode()
{
    return _isExplode;
}

clock_t Bomb::getClock()
{
    return _clock;
}

void Bomb::setRadius(int radius)
{
    _radius = radius;
}

void Bomb::setIsExplode(bool isExplode)
{
    _isExplode = isExplode;
}
