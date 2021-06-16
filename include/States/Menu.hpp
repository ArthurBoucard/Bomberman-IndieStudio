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
#include "../Raylib/Raylib.hpp"

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

    private:
        Raylib::Rectangle _rectPlayGame;
        Raylib::Rectangle _rectSettings;
        Raylib::Rectangle _rectHowToPlay;
        Raylib::Rectangle _rectStats;

        Vector2 _mouse;

        float _screenWidth;
        float _screenHeight;

        Raylib::Text _playGame;
        Raylib::Text _title;
        Raylib::Text _settings;
        Raylib::Text _howToPlay;
        Raylib::Text _stat;

        Raylib::Music _music;
        Sound _button;

        Raylib::Texture2D _bg;

        Raylib::WindowTools _window;
};

#endif /* !Menu_HPP_ */
