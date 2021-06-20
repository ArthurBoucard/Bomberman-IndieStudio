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
#include "../States/GameOver.hpp"
#include "../States/GameSettings.hpp"
#include "../States/HowToPlay.hpp"
#include "../Raylib/Raylib.hpp"
#include "../States/Win.hpp"

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
    bool CheckMouse(Vector2, Raylib::Rectangle, int state);

    void LoadSave();

private:
    Raylib::Rectangle _rectPlayGame;
    Raylib::Rectangle _rectSettings;
    Raylib::Rectangle _rectHowToPlay;
    Raylib::Rectangle _rectStats;
    Raylib::Rectangle _rectLoad;

    Vector2 _mouse;

    float _screenWidth;
    float _screenHeight;

    Raylib::Text _playGame;
    Raylib::Text _title;
    Raylib::Text _settings;
    Raylib::Text _howToPlay;
    Raylib::Text _stat;
    Raylib::Text _load;

    Raylib::Music _music;
    Raylib::Sound _button;

    Raylib::Texture2D _bg;

    Raylib::WindowTools _window;

    unsigned int _nbPlayer;
    unsigned int _nbIA;
    std::vector<std::string> _map;
    std::vector<std::string> _skin;

    float _scale;
};

#endif /* !Menu_HPP_ */
