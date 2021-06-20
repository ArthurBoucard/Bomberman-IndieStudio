/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../Exception.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>

class Map {
    public:
        Map();
        ~Map();

        void createMap();
        std::vector<std::string> getMap() const;
        void reset();
        void proceduralGenClassical();
        void proceduralGenLab();
        void placePlayers(int nbPlayer, int nbIA);
        void RandomMap();
    protected:
    private:
        std::vector<std::string> _map;
};

#endif /* !MAP_HPP_ */
