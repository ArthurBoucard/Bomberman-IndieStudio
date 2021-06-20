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
        Card(int id);
        ~Card();

        void link(int id);
        int getLink() const;
        int getId() const;

        void setHead(std::string str);
        Texture2D getHead() const;

        void setName(std::string name);
        std::string getName() const;

        Texture2D getPowerUpSpeed() const;
        void setNbPowerUpSpeed(int nb);
        int getNbPowerUpSpeed() const;

        Texture2D getPowerUpBombUp() const;
        void setNbPowerUpBombUp(int nb);
        int getNbPowerUpSBombUp() const;

        Texture2D getPowerUpFlameUp() const;
        void setNbPowerUpFlameUp(int nb);
        int getNbPowerUpFlameUp() const;

        Texture2D getPowerUpWallPass() const;
        void setNbPowerUpWallPass(int nb);
        int getNbPowerUpWallPass() const;
    protected:
        int _link;
        int _id;
        Texture2D _head;
        std::string _name;
        Texture2D _powerUpSpeed;
        int _nbPowerUpSpeed = 0;
        Texture2D _powerUpBombUp;
        int _nbPowerUpBombUp = 0;
        Texture2D _powerUpFlameUp;
        int _nbPowerUpFlameUp = 0;
        Texture2D _powerUpWallPass;
        int _nbPowerUpWallPass = 0;
    private:
};

#endif /* !CARD_HPP_ */
