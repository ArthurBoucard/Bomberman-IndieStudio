/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** PowerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "Player.hpp"

class PowerUp
{
public:
    PowerUp() = default;
    ~PowerUp() = default;
    PowerUp *getPower() const;
    void setPower();
    virtual void usePower(Player *player) const = 0;

protected:
    PowerUp *_power;
};

class Speed : public PowerUp
{
    void usePower(Player *player) const;
};
#endif /* !POWERUP_HPP_ */
