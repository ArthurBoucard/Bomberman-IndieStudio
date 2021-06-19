/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Components.hpp"
#include "Position.hpp"
#include "../Raylib/Raylib.hpp"

#include <cmath>

class Player : public Components {
    public:
        Player(std::string name, int id);
        ~Player();

        void link(int id);
        int getLink() const;
        std::string getPlayerName() const;
        int getPlayerID() const; // 0 = player 1 || 1 = player 2 || 2 = AI
        void setClock(clock_t cl);
        clock_t getClock() const;
        void setSpeed(float speed);
        float getSpeed() const;
        void updateBBox(Position pos);
        BoundingBox getBBox() const;
        void setIsAlive(bool b);
        bool getIsAlive() const;
        std::size_t getNbBomb() const;
        void setNbBomb(std::size_t n);
        std::size_t getFlameSize() const;
        void setFlameSize(std::size_t);

    protected:
        int _link;
        std::string _name;
        int _id;
        clock_t _start;
        float _speed;
        Mesh _mesh;
        BoundingBox _bBox;
        bool _isAlive;
        std::size_t _nbBombs;
        std::size_t _flameSize;
    private:
};

#endif /* !PLAYER_HPP_ */
