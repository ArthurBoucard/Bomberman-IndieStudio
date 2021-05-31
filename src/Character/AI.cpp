/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** AI
*/

#include "../../include/Character/AI.hpp"

AI::AI()
{
}

AI::~AI()
{
}

void AI::SetBombQuantity()
{}

void AI::SetSpeed()
{}

void AI::SetRange()
{}

unsigned int AI::GetBombQuantity() const
{
    return _bombQuantity;
}

unsigned int AI::GetSpeed() const
{
    return _speed;
}

unsigned int AI::GetRange() const
{
    return _range;
}

void AI::SetSkin()
{}

std::string AI::GetSkin() const
{
    return _skin;
}