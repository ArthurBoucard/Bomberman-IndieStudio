/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Texture2DComp
*/

#include "../../include/Components/Texture2DComp.hpp"

Texture2DComp::Texture2DComp(Texture2D texture)
{
    _texture = texture;
}

Texture2DComp::~Texture2DComp()
{
}

void Texture2DComp::link(int id)
{
    _link = id;
}

int Texture2DComp::getLink() const
{
    return _link;
}

Texture2D Texture2DComp::getTexture() const
{
    return _texture;
}
