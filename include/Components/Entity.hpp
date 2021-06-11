/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>
#include <vector>

extern int idValue;

#include "Components.hpp"
#include "Position.hpp"
#include "Breakable.hpp"
#include "Texture2DComp.hpp"
#include "Player.hpp"
#include "Model3D.hpp"
#include "Bomb.hpp"
#include "Jump.hpp"

class Entity {
    public:
        Entity();
        ~Entity();

        int getId() const;
    protected:
    private:
        int _id;
};

#endif /* !ENTITY_HPP_ */
