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
    start = clock();
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
