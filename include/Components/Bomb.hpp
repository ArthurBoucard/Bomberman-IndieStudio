/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Components.hpp"
#include "../Raylib/Raylib.hpp"

class Bomb {
    public:
        Bomb();
        ~Bomb();

        void link(int id);
        void linkPlayer(int id);
        int getLink();
        int getPlayerLink();
        int getRadius();
        int getTimeLeft();
    protected:
        int _link;
        int _playerLink;
        int _radius;
        int _timeLeft;
    private:
};

#endif /* !BOMB_HPP_ */
