/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Menu
*/

#ifndef Menu_HPP_
#define Menu_HPP_

#include "../StatesManagement/State.hpp"
#include "../StatesManagement/Context.hpp"
#include "../States/Game.hpp"

class Menu : public State
{
public:
    Menu();
    ~Menu();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();
    bool CheckMouse(Vector2, Rectangle, const char *, int);

private:
    Rectangle _settingsRect;
    Vector2 _settingsVect;
    Texture2D _settingsText;

    Rectangle _statRect;
    Vector2 _statVect;
    Texture2D _statText;

    Rectangle _questRect;
    Vector2 _questVect;
    Texture2D _questText;

    Rectangle _rect_game;
    Vector2 _mouse;
    Texture2D _bg;

    float _screenWidth;
    float _screenHeight;
    const char *_play_game = (char *)"PLAY GAME";
    const char *_title = (char *)"BOMBERMAN";
    const char *_empty = (char *)"";
};

#endif /* !Menu_HPP_ */
