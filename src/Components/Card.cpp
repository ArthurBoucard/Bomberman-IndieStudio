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

int Card::getLink() const
{
    return _link;
}

void Card::setRect(Raylib::Rectangle rect)
{
    _rect = rect;
}

Raylib::Rectangle Card::getRect() const
{
    return _rect;
}

void Card::setHead(Image img)
{
    _head = img;
}

Image Card::getHead() const
{
    return _head;
}

void Card::setName(std::string name)
{
    _name = name;
}

std::string Card::getName() const
{
    return _name;
}

Image Card::getPowerUpSpeed() const
{
    return _powerUpSpeed;
}

void Card::setNbPowerUpSpeed(int nb)
{
    _nbPowerUpSpeed = nb;
}

int Card::getNbPowerUpSpeed() const
{
    return _nbPowerUpSpeed;
}

Image Card::getPowerUpBombUp() const
{
    return _powerUpBombUp;
}

void Card::setNbPowerUpBombUp(int nb)
{
    _nbPowerUpBombUp = nb;
}

int Card::getNbPowerUpSBombUp() const
{
    return _nbPowerUpBombUp;
}

Image Card::getPowerUpFlameUp() const
{
    return _powerUpFlameUp;
}
void Card::setNbPowerUpFlameUp(int nb)
{
    _nbPowerUpFlameUp = nb;
}

int Card::getNbPowerUpFlameUp() const
{
    return _nbPowerUpFlameUp;
}

Image Card::getPowerUpWallPass() const
{
    return _powerUpWallPass;
}

void Card::setNbPowerUpWallPass(int nb)
{
    _nbPowerUpWallPass = nb;
}

int Card::getNbPowerUpWallPass() const
{
    return _nbPowerUpWallPass;
}
