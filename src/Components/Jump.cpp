/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Jump
*/

#include "../../include/Components/Jump.hpp"

Jump::Jump()
{
    _animCount = 0;
    _animFrameCounter = 0;
    _anim = LoadModelAnimations("../assets/skin/guyanim.iqm", &_animCount);
    _isJump = false;
}

Jump::~Jump()
{
    UnloadModelAnimation(*_anim);
    //RL_FREE(_anim);
}

void Jump::link(int id)
{
    _link = id;
}

int Jump::getLink() const
{
    return _link;
}

bool Jump::getJump() const
{
    return _isJump;
}

int Jump::getAnimCount() const
{
    return _animCount;
}

ModelAnimation Jump::getAnim() const
{
    return *_anim;
}
int Jump::getFrameCount() const
{
    return _animFrameCounter;
}

void Jump::setJump( bool jump)
{
    _isJump = jump;
}

void Jump::setAnimCount(int count)
{
    _animCount = count;
}

void Jump::setFrameCount(int frame)
{
    _animFrameCounter = frame;
}
