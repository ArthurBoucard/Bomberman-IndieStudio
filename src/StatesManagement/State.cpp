/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** IStates
*/

#include "../../include/StatesManagement/State.hpp"

State::~State(){}

void State::SetContext(Context *context)
{
    _context = context;
}