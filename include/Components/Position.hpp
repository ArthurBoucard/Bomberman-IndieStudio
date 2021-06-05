/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include <utility>

#include "Components.hpp"

class Position : public Components {
    public:
        Position(int posX, int posY);
        ~Position();

        std::pair<int, int> getPos() const;
    protected:
    private:
        std::pair<int, int> _pos;
};

#endif /* !POSITION_HPP_ */
