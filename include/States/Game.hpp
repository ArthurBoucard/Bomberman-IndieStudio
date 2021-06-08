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
#include "../Map/Map.hpp"
#include "../Components/Entity.hpp"

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
        std::vector<std::string> _map;

        Texture2D _brick;
        Texture2D _wall;
        Texture2D _grass;

        Camera _camera = {0};

        std::vector<Entity *> _wallList;
        std::vector<Entity *> _brickList;
        std::vector<Entity *> _groundList;
};

#endif /* !GAME_HPP_ */
