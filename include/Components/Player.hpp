/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Components.hpp"
#include "../Raylib/Raylib.hpp"

class Player : public Components {
    public:
        Player(std::string name, int id);
        ~Player();

        void link(int id);
        int getLink();
        std::string getPlayerName();
        int getPlayerID(); // 0 = player 1 || 1 = player 2 || 2 = AI
    protected:
        int _link;
        std::string _name;
        int _id;
    private:
};

#endif /* !PLAYER_HPP_ */
