/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Context
*/

#include "../../include/StatesManagement/Context.hpp"

Context::Context(State *state) : _state(nullptr)
{
    TransitionTo(state);
}

Context::~Context()
{
    delete _state;
}

void Context::TransitionTo(State *state)
{
    if (_state != nullptr)
        delete _state;

    _state = state;
    _state->SetContext(this);
}

void Context::Draw()
{
    _state->Draw();
}

void Context::Update()
{
    _state->Update();
}

void Context::Clear()
{
    _state->Clear();
}

void Context::HandleInput()
{
    _state->HandleInput();
}

void Context::Reset()
{
    _state->Reset();
}