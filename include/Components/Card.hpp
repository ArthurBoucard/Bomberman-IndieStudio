/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Card
*/

#ifndef CARD_HPP_
#define CARD_HPP_

#include "Components.hpp"
#include "../Raylib/Raylib.hpp"

class Card {
    public:
        Card();
        ~Card();

        void link(int id);
        int getLink();

        void setRect(Raylib::Rectangle rect);
        Raylib::Rectangle getRect();
        void setHead(Image img);
        Image getHead();
        void setName(std::string _name);
        std::string getName();
    protected:
        int _link;
        Raylib::Rectangle _rect;
        Image _head;
        std::string _name;
        Image _powerUpSpeed;
        int _nbPowerUpSpeed;
        Image _powerUpBombUp;
        int _nbPowerUpBombUp;
        Image _powerUpFlameUp;
        int _nbPowerUpFlameUp;
        Image _powerUpWallPass;
        int _nbPowerUpWallPass;
    private:
};

#endif /* !CARD_HPP_ */
