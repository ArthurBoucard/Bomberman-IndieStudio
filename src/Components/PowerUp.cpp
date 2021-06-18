/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** PowerUp
*/

#include "../../include/Components/PowerUp.hpp"
#include "../../include/Components/Player.hpp"

PowerUp *PowerUp::getPower() const {
    return _power;
}

void PowerUp::setPower() {
    int power = GetRandomValue(0, 0);
    if (power == 0)
        _power = new Speed;
}

void Speed::usePower(Player *player) const
{
    float speed = player->getSpeed();

    player->setSpeed(speed + 0.05);
}