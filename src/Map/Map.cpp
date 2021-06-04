/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Map
*/

#include "../../include/Map/Map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

void Map::createMap()
{
    std::ifstream mapFile("../assets/map.txt");
	std::vector<std::string> map;
	std::string line;

    try {
        if (mapFile) {
            while (getline(mapFile, line))
                map.push_back(line);
        }
    }
    catch(Exception const& e) {
        std::cerr << "Error: could not open \"./map\"" << e.what() << std::endl;
        exit(84);
    }
    _map = map;
}

std::vector<std::string> Map::getMap() const
{
    return _map;
}

void Map::reset()
{
    _map.empty();
}

void Map::proceduralGenClassical()
{
    srand (time(NULL));

    for (int i = 2; i < _map.size(); i += 2)
        for (int j = 2; j < _map[i].length(); j += 2)
            _map[i][j] = 'X';

    for (int i = 1; i < _map.size(); i++)
        for (int j = 1; j < _map[i].length(); j++)
            if (_map[i][j] == ' ' && rand() % 5 != 0)
                _map[i][j] = '#';

    for (int i = 1; i < _map.size(); i++)
        for (int j = 1; j < _map[i].length(); j++)
            if (_map[i][j] == '$')
                _map[i][j] = ' ';
}