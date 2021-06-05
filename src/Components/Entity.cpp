/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Entity
*/

#include "../../include/Components/Entity.hpp"

Entity::Entity()
{
    _id = 42;
}

Entity::~Entity()
{
}

int Entity::getId() const
{
    return _id;
}

void Entity::addComponents(Components components)
{
    _components.push_back(components);
}
