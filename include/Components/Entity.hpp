/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>

#include "../Main.hpp"
#include "Components.hpp"

class Entity {
    public:
        Entity();
        ~Entity();

        int getId() const;
        void addComponents(Components components);
    protected:
    private:
        int _id;
        std::vector<Components> _components;
};

#endif /* !ENTITY_HPP_ */
