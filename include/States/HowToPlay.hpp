/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** HowToPlay
*/

#ifndef HOWTOPLAY_HPP_
#define HOWTOPLAY_HPP_

#include "../StatesManagement/State.hpp"
#include "../StatesManagement/Context.hpp"
#include "../States/Menu.hpp"

class HowToPlay : public State
{
public:
    HowToPlay();
    ~HowToPlay();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();
    void UpdateScale();

    bool CheckMouse(Raylib::Vector2, Raylib::Rectangle, Raylib::Text, int state);

private:
    Raylib::Texture2D _bg;

    Raylib::Rectangle _back;
    Raylib::Text _textBack;
    Raylib::Vector2 _vectBack;
    Raylib::Vector2 _mouse;

    float _screenWidth;
    float _screenHeight;
    float _scale = 1;
    float _temp;
};

#endif /* !HOWTOPLAY_HPP_ */
