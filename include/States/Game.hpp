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

        Camera _camera = {0};

        Model _model;
        Texture2D _texture;
        Vector3 _position;

        float _speed = 0.05;

        std::vector<Position *> _positionList;
        std::vector<Breakable *> _breakableList;
        std::vector<Texture2DComp *> _texture2DList;
};

#endif /* !GAME_HPP_ */
