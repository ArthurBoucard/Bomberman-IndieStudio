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
    GameOver();
    ~GameOver();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();

    bool CheckMouse(Vector2, Rectangle, std::string, int state);

private:
    Vector2 _mouse;
    Rectangle _rectBack;
    Rectangle _rectAgain;
    Music _musicEnd;

    float _screenWidth;
    float _screenHeight;
    std::string _gameOver = "GAME OVER";
    std::string _back = "BACK TO MENU";
    std::string _again = "PLAY AGAIN";
};

#endif /* !GAMEOVER_HPP_ */
