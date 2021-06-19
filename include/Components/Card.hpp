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
        int getLink() const;

        void setRect(Raylib::Rectangle rect);
        Raylib::Rectangle getRect() const;

        void setHead(Image img);
        Image getHead() const;

        void setName(std::string name);
        std::string getName() const;

        Image getPowerUpSpeed() const;
        void setNbPowerUpSpeed(int nb);
        int getNbPowerUpSpeed() const;

        Image getPowerUpBombUp() const;
        void setNbPowerUpBombUp(int nb);
        int getNbPowerUpSBombUp() const;

        Image getPowerUpFlameUp() const;
        void setNbPowerUpFlameUp(int nb);
        int getNbPowerUpFlameUp() const;

        Image getPowerUpWallPass() const;
        void setNbPowerUpWallPass(int nb);
        int getNbPowerUpWallPass() const;
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
