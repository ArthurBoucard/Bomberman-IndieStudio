/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Flame
*/

#include "../../include/Components/Flame.hpp"

Flame::Flame(int dist, int direction, Position pos)
{
    _dist = dist;
    _clock = clock();
    _bombPos = pos;
    _direction = direction;
}

Flame::~Flame()
{
}

void Flame::link(int id)
{
    _link = id;
}

int Flame::getLink() const
{
    return _link;
}

void Flame::move()
{
    _dist--;
}

int Flame::getDist() const
{
    return _dist;
}

clock_t Flame::getClock() const
{
    return _clock;
}

Position Flame::getBombPos() const
{
    return _bombPos;
}

int Flame::getDirection() const
{
    return _direction;
}

void Flame::resetClock()
{
    _clock = clock();
}
