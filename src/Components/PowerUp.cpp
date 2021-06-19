/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** PowerUp
*/

#include "../../include/Components/PowerUp.hpp"

PowerUp::PowerUp()
{
    ipower = GetRandomValue(0, 2);
}

void PowerUp::setPower()
{
    if (ipower == 0)
        _power = new Speed;
    if (ipower == 1)
        _power = new BombPower;
    if (ipower == 2)
        _power = new FlameUp;
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

PowerUp *PowerUp::getPower() const
{
    return _power;
}

void PowerUp::usePower(Player *player)
{
    _power->usePower(player);
}

Texture2D PowerUp::getTexture() const
{
    return _power->_tex;
}

Speed::Speed()
{
    _power = nullptr;
    _tex = LoadTexture("../assets/pictures/SpeedUp.png");
}

Speed::~Speed()
{
}

void Speed::usePower(Player *player)
{
    float speed = player->getSpeed();

    player->setSpeed(speed + 0.01);
}

BombPower::BombPower()
{
    _power = nullptr;
    _tex = LoadTexture("../assets/pictures/bombUp.png");
}

BombPower::~BombPower()
{
}

void BombPower::usePower(Player *player)
{
    int nbBomb = player->getNbBomb();

    player->setNbBomb(nbBomb + 1);
}

FlameUp::FlameUp()
{
    _power = nullptr;
    _tex = LoadTexture("../assets/pictures/fireUp.png");
}

FlameUp::~FlameUp()
{
}

void FlameUp::usePower(Player *player)
{
    std::size_t flame = player->getFlameSize();

    player->setFlameSize(flame + 1);
}