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
        void UpdateScale();

    private:
        Raylib::Texture2D _bg;
        float _screenWidth;
        float _screenHeight;
<<<<<<< HEAD
        float _scale;
=======
        float _scale = 1;
        float _temp;
>>>>>>> 81da35adc7dca01ec50754e29b801b5d2ef5a685

};

#endif /* !HOWTOPLAY_HPP_ */
