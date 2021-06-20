/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** GameOver
*/

#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_

#include "../StatesManagement/State.hpp"
#include "../StatesManagement/Context.hpp"
#include "../States/Menu.hpp"

class GameOver : public State
{
public:
    GameOver(int _nbPlayer, int _nbIA, int _skinChoicePl1, int _skinChoicePl2);
    ~GameOver();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();

    bool CheckMouse(Raylib::Vector2, Raylib::Rectangle, std::string, int state);

private:
    Raylib::Vector2 _mouse;
    Raylib::Rectangle _rectBack;
    Raylib::Rectangle _rectAgain;
    Raylib::Music _musicEnd;
    Raylib::Sound _button;

    float _screenWidth;
    float _screenHeight;
    std::string _gameOver = "GAME OVER";
    std::string _back = "BACK TO MENU";
    std::string _again = "PLAY AGAIN";

    int _nbPlayer;
    int _nbIA;
    int _skinChoicePl1;
    int _skinChoicePl2;
};

#endif /* !GAMEOVER_HPP_ */
