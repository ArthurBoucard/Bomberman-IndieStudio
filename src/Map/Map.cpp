/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Map
*/

#include "../../include/Map/Map.hpp"
#include "../../include/States/Game.hpp"
#include "ctime"


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

    try
    {
        if (mapFile)
        {
            while (getline(mapFile, line))
                map.push_back(line);
        }
    }
    catch (Exception const &e)
    {
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
    srand(time(NULL));

    for (int i = 2; i < _map.size(); i += 2)
        for (int j = 2; j < _map[i].length(); j += 2)
            _map[i][j] = 'X';

    for (int i = 1; i < _map.size(); i++)
        for (int j = 1; j < _map[i].length(); j++)
            if (_map[i][j] == ' ' && rand() % 5 != 0)
                _map[i][j] = '#';
}

void Map::placePlayers(int nbPlayer, int nbIA)  // 0 = player 1 || 1 = player 2 || @ = IA
{
    std::vector<std::pair<int, int>> pPos;

    for (int i = 1; i < _map.size(); i++)
        for (int j = 1; j < _map[i].length(); j++)
            if (_map[i][j] == 'S')
                pPos.push_back({i, j});

    if (nbPlayer == 2) {
        _map[pPos[0].first][pPos[0].second] = '0';
        pPos.erase(pPos.begin());
        _map[pPos[pPos.size() - 1].first][pPos[pPos.size() - 1].second] = '1';
        pPos.erase(pPos.end() - 1);
    } else if (nbPlayer == 1) {
        _map[pPos[0].first][pPos[0].second] = '0';
        pPos.erase(pPos.begin());
    }
    for (int x = 0; x < nbIA; x++)
        _map[pPos[x].first][pPos[x].second] = '@';

    for (int i = 1; i < _map.size(); i++)
        for (int j = 1; j < _map[i].length(); j++)
            if (_map[i][j] == '$' || _map[i][j] == 'S')
                _map[i][j] = ' ';
}

void Map::proceduralGenLab()
{
    srand(time(NULL));

    int k = 0;
    int length = 0;

    for (int i = 1; i < _map.size(); i += 1)
    {
        if (k == 3 || k == 6)
            i += 1;
        k++;
        for (int j = 3; j < _map[i].length() - 2; j += 3)
        {
            _map[i][j] = 'X';
            for (int i = 2; i < _map.size(); i += 4)
                for (int j = 2; j < _map[i].length() - 2; j += 2)
                    _map[i][j] = 'X';
            _map[i][j] = 'X';
            j += 1;
        }
    }
    for (int i = 1; i < _map.size(); i++)
        for (int j = 1; j < _map[i].length(); j++)
            if (_map[i][j] == ' ' && rand() % 5 != 0)
                _map[i][j] = '#';

    for (int i = 1; i < _map.size(); i++)
        for (int j = 1; j < _map[i].length(); j++)
            if (_map[i][j] == '$')
                _map[i][j] = ' ';
}

void Map::RandomMap()
{

    srand((unsigned) time(0));
    int randomNb = 0;

    randomNb = (rand() % 2);

    if (randomNb == 0)
        proceduralGenClassical();
    else
        proceduralGenLab();
}