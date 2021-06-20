/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Pause
*/

#ifndef PAUSE_HPP_
#define PAUSE_HPP_

#include "../StatesManagement/State.hpp"
#include "../../include/States/Game.hpp"
#include "../Raylib/Raylib.hpp"

#include <iostream>
#include <fstream>
#include <vector>

class Pause : public State
{
public:
    Pause(int nbPlayer, int nbIA, const std::vector<std::string> &map, int, int, const std::vector<std::string> skin);
    Pause();
    ~Pause();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();
    bool CheckMouse(Vector2, Raylib::Rectangle, int state);

    void SaveInFile();

private:
    Vector2 _mouse;

    Raylib::Rectangle _rectAgain;
    Raylib::Rectangle _rectBack;
    Raylib::Rectangle _rectResume;

    Texture2D _bg;

    float _screenHeight;
    float _screenWidth;

    std::string _pauseText = "PAUSE";
    std::string _playAgain = "Play Again";
    std::string _resume = "Resume";
    std::string _backMenu = "Save and Quit";

    int _skinChoicePl1;
    int _skinChoicePl2;

    Raylib::Music _music;
    Raylib::Sound _button;

    std::vector<std::string> _map;
    std::vector<std::string> _saveSkin;

    unsigned int _nbPlayer;
    unsigned int _nbIA;
};

#endif /* !PAUSE_HPP_ */
