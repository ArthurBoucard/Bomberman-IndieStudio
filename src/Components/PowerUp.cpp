/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** PowerUp
*/

#include "../../include/Components/PowerUp.hpp"

PowerUp::PowerUp() {
    int power = GetRandomValue(0, 0);
    if (power == 0)
        _power = new Speed;
}

PowerUp::~PowerUp()
{
    delete _power;
}

void PowerUp::link(int id)
{
    _link = id;
}

int PowerUp::getLink() const
{
    return _link;
}


PowerUp *PowerUp::getPower() const {
    return _power;
}

void PowerUp::usePower(Player *player) const {
    _power->usePower(player);
}

Texture2D PowerUp::getTexture() const {
    return _power->_tex;
}

Speed::Speed()
{
    _power = nullptr;
    _tex = LoadTexture("../../assets/pictures/SpeedUp.png");
}

void Speed::usePower(Player *player) const
{
    float speed = player->getSpeed();

    player->setSpeed(speed + 0.05);
}