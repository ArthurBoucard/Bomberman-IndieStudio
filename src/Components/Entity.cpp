/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Entity
*/

#include "../../include/Components/Entity.hpp"

int idValue = 0;

Entity::Entity()
{
    _id = idValue;
    idValue++;
}

Entity::~Entity()
{
}

int Entity::getId() const
{
    return _id;
}
