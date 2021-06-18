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

#include <iostream>
#include <vector>

class Pause : public State
{
public:
    Pause(int nbPlayer, int nbIA, const std::vector<std::string> &map);
    Pause();
    ~Pause();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();
    bool CheckMouse(Vector2, Raylib::Rectangle, int state);

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
    std::string _backMenu = "Back To Menu";

    std::vector<std::string> _map;

    unsigned int _nbPlayer;
    unsigned int _nbIA;
};

#endif /* !PAUSE_HPP_ */
