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

    private:
};

#endif /* !Menu_HPP_ */
