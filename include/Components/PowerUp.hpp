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
    PowerUp();
    ~PowerUp();
    void link(int id);
    int getLink() const;
    PowerUp *getPower() const;
    void usePower(Player *player) const;
    Texture2D getTexture() const;

protected:
    PowerUp *_power;
    int _link;
    Texture2D _tex;
};

class Speed : public PowerUp
{
public:
    Speed();
    void usePower(Player *player) const;

};
#endif /* !POWERUP_HPP_ */
