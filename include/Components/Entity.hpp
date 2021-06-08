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

#include "Components.hpp"
#include "Position.hpp"
#include "Breakable.hpp"

class Entity {
    public:
        Entity();
        ~Entity();

        int getId() const;
        void addComponents(Components components);
        Components getComponent(int i) const;
        std::vector<Components> getVectorCompononent() const;
    protected:
    private:
        int _id;
        std::vector<Components> _components;
};

#endif /* !ENTITY_HPP_ */
