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
        Bomb(int radius);
        ~Bomb();

        void link(int id);
        void linkPlayer(int id);
        int getLink() const;
        int getPlayerLink() const;
        int getRadius() const;
        int getTimeLeft() const;
        bool getIsExplode() const;
        clock_t getClock() const;

        void setRadius(int radius);
        void setIsExplode(bool isExplode);
    protected:
        int _link;
        int _playerLink;
        int _radius;
        int _timeLeft;
        clock_t _clock;
        bool _isExplode;
    private:
};

#endif /* !BOMB_HPP_ */
