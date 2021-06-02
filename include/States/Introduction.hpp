/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Introduction
*/

#ifndef INTRODUCTION_HPP_
#define INTRODUCTION_HPP_

#include "../StatesManagement/State.hpp"
#include "../StatesManagement/Context.hpp"
#include "../States/Menu.hpp"

class Introduction : public State
{
    public:
        Introduction();
        ~Introduction();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

        void UpdateScale(Texture2D texture);

    private:
        int _width;
        int _height;
        float scale = 5;

        Image _bouboule;
        Music music;
};

#endif /* !INTRODUCTION_HPP_ */
