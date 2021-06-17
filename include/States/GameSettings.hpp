/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** GameSettings
*/

#ifndef GAMESETTINGS_HPP_
#define GAMESETTINGS_HPP_

#include "../StatesManagement/State.hpp"
#include "../StatesManagement/Context.hpp"
#include "../States/Menu.hpp"
#include "../Map/Map.hpp"

class GameSettings : public State
{
public:
    GameSettings();
    ~GameSettings();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();
    bool CheckMouse(Vector2, Rectangle, const char *, int state);

private:
    Texture2D _bg;

    Vector2 _mouse;

    Rectangle _rectPlPlayers;
    Rectangle _rectMiPlayers;
    Rectangle _rectPlIA;
    Rectangle _rectMiIA;
    Rectangle _rectValidate;

    float _screenWidth;
    float _screenHeight;

    int _nbPlayers;
    int _nbIA;
    int _nbTotalPlayers;

    std::string _nbPlayersText = "Number of players";
    std::string _nbIAText = "Number of AI";

    Sound _button;
};

#endif /* !GAME_HPP_ */
