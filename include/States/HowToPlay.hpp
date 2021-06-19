/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** HowToPlay
*/

#ifndef HOWTOPLAY_HPP_
#define HOWTOPLAY_HPP_

#include "../StatesManagement/State.hpp"

class HowToPlay : public State
{
    public:
        HowToPlay();
        ~HowToPlay();

        void Draw();
        void Update();
        void Clear();
        void HandleInput();
        void Reset();

    private:
        Raylib::Texture2D _bg;
        
};

#endif /* !HOWTOPLAY_HPP_ */
