/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../StatesManagement/State.hpp"
#include "../StatesManagement/Context.hpp"
#include "../States/Menu.hpp"

class Game : public State {
    public:
        Game();
        ~Game();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

    private:
        float _screenWidth;
        float _screenHeight;

        Rectangle _rectGame;
};

#endif /* !GAME_HPP_ */
