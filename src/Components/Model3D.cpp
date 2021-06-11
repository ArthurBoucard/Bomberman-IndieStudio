/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Model3D
*/

#include "../../include/Components/Model3D.hpp"

Model3D::Model3D()
{
}

Model3D::~Model3D()
{
}

void Model3D::link(int id)
{
    _link = id;
}

int Model3D::getLink()
{
    return _link;
}

Model Model3D::getModel()
{
    return _model;
}
void Model3D::setModel(Model model)
{
    _model = model;
}
