/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Flame
*/

#ifndef FLAME_HPP_
#define FLAME_HPP_

#include "Components.hpp"
#include "../Raylib/Raylib.hpp"
#include "Position.hpp"

class Flame {
    public:
        Flame(int dist, int direction, Position pos);
        ~Flame();

        void link(int id);
        int getLink() const;
        void move();
        int getDist() const;
        clock_t getClock() const;
        Position getBombPos() const;
        int getDirection() const;
        void resetClock();
    protected:
        int _link;
        int _dist;
        int _direction; // 1 = UP | 2 = RIGHT | 3 = DOWN | 4 = LEFT
        clock_t _clock;
        Position _bombPos;
    private:
};

#endif /* !FLAME_HPP_ */
