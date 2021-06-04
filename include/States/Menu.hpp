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
    bool CheckMouse(Vector2, Rectangle, const char *, int state);

private:
    Rectangle _rect_game;
    Rectangle _rect_settings;
    Rectangle _rect_tuto;
    Rectangle _rect_stat;
    Vector2 _mouse;
    Texture2D _bg;
    Music _music_menu;

    float _screenWidth;
    float _screenHeight;
    const char *_play_game = (char *)"PLAY GAME";
    const char *_title = (char *)"BOMBERMAN";
    const char *_settings = (char *)"SETTINGS";
    const char *_tuto = (char *)"HOW TO PLAY";
    const char *_stat = (char *)"STATS";
};

#endif /* !Menu_HPP_ */
