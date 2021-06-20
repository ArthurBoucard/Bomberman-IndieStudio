/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Card
*/

#include "../../include/Components/Card.hpp"

Card::Card(int id)
{
    _id = id;

    _powerUpSpeed = LoadTexture("../assets/pictures/SpeedUp.png");
    _powerUpFlameUp = LoadTexture("../assets/pictures/fireUp.png");
    _powerUpBombUp = LoadTexture("../assets/pictures/bombUp.png");
    _powerUpWallPass = LoadTexture("../assets/pictures/bombUp.png");
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

int Card::getId() const
{
    return _id;
}


void Card::setHead(std::string str)
{
    _head = LoadTexture(str.c_str());
}

Texture2D Card::getHead() const
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

Texture2D Card::getPowerUpSpeed() const
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

Texture2D Card::getPowerUpBombUp() const
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

Texture2D Card::getPowerUpFlameUp() const
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

Texture2D Card::getPowerUpWallPass() const
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
