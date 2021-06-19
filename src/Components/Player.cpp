/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Player
*/

#include "../../include/Components/Player.hpp"

Player::Player(std::string name, int id)
{
    _name = name;
    _id = id;
    _start = clock();
    _speed = 0.05;
    _mesh = GenMeshCube(0.5, 1, 0.5);
    _bBox = GetMeshBoundingBox(_mesh);
    _isAlive = true;
    _nbBombs = 1;
    _flameSize = 2;
}

Player::~Player()
{
}

void Player::link(int id)
{
    _link = id;
}

int Player::getLink() const
{
    return _link;
}

std::string Player::getPlayerName() const
{
    return _name;
}

int Player::getPlayerID() const
{
    return _id;
}

void Player::setClock(clock_t cl)
{
    _start = cl;
}

clock_t Player::getClock() const
{
    return _start;
}

void Player::setSpeed(float speed)
{
    _speed = speed;
}
float Player::getSpeed() const
{
    return _speed;
}
void Player::updateBBox(Position pos)
{
    return;
}

BoundingBox Player::getBBox() const
{
    return _bBox;
}

void Player::setIsAlive(bool b)
{
    _isAlive = b;
}

bool Player::getIsAlive() const
{
    return _isAlive;
}

std::size_t Player::getNbBomb() const
{
    return _nbBombs;
}

void Player::setNbBomb(std::size_t n)
{
    _nbBombs = n;
}

std::size_t Player::getFlameSize() const
{
    return _flameSize;
}
void Player::setFlameSize(std::size_t size)
{
    _flameSize = size;
}