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
#include "../Raylib/Raylib.hpp"

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

        void UpdateScale();

    private:
        float _scale = 5;
        float _scrennWidth;
        float _scrennHeight;

        Raylib::Music _music;

        Raylib::Texture2D _bouboule;
};

#endif /* !INTRODUCTION_HPP_ */
