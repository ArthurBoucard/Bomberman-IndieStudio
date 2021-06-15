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
    // for (int i = 0; i < animsCount; i++) UnloadModelAnimation(anims[i]);
    // RL_FREE(anims);
}

void Jump::link(int id)
{
    _link = id;
}

int Jump::getLink()
{
    return _link;
}

bool Jump::getJump()
{
    return _isJump;
}

int Jump::getAnimCount()
{
    return _animCount;
}

ModelAnimation Jump::getAnim()
{
    return *_anim;
}
int Jump::getFrameCount()
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
