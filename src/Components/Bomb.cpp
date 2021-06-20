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

int Bomb::getLink() const
{
    return _link;
}

int Bomb::getPlayerLink() const
{
    return _playerLink;
}

int Bomb::getRadius() const
{
    return _radius;
}

int Bomb::getTimeLeft() const
{
    return _timeLeft;
}

bool Bomb::getIsExplode() const
{
    return _isExplode;
}

clock_t Bomb::getClock() const
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
