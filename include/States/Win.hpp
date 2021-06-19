/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Win
*/

#ifndef WIN_HPP_
#define WIN_HPP_

#include "../StatesManagement/State.hpp"
#include "../States/Menu.hpp"

class Win : public State
{
public:
    Win(int nbPlayer, int nbIA, int skin1, int skin2);
    ~Win();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();

    bool CheckMouse(Vector2, Raylib::Rectangle, Raylib::Text, int state);

private:
    Raylib::Texture2D _bgWin;

    Raylib::Rectangle _rectBack;
    Raylib::Rectangle _rectAgain;

    int _screenWidth;
    int _screenHeight;

    Vector2 _mouse;

    Raylib::Text _win;
    Raylib::Text _back;
    Raylib::Text _again;

    int _nbPlayer;
    int _nbIA;
    int _skin1;
    int _skin2;
};

#endif /* !WIN_HPP_ */
