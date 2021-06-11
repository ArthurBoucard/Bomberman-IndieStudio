/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Jump
*/

#ifndef JUMP_HPP_
#define JUMP_HPP_

#include "Components.hpp"
#include "../Raylib/Raylib.hpp"

class Jump {
    public:
        Jump();
        ~Jump();

        void link(int id);
        int getLink();
        bool getJump();
        int getAnimCount();
        ModelAnimation getAnim();
        int getFrameCount();

        void setJump(bool jump);
        void setAnimCount(int count);
        void setFrameCount(int frame);
    protected:
        int _link;
        ModelAnimation *_anim;
        bool _isJump;
        int _animCount;
        int _animFrameCounter;
    private:
};

#endif /* !JUMP_HPP_ */
