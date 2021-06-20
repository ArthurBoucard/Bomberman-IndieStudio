/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Model3D
*/

#ifndef MODEL3D_HPP_
#define MODEL3D_HPP_

#include "Components.hpp"
#include "../Raylib/Raylib.hpp"

class Model3D {
    public:
        Model3D();
        ~Model3D();

        void link(int id);
        int getLink() const;
        Model getModel() const;
        void setModel(Model model);
    protected:
        int _link;
        Model _model;
    private:
};

#endif /* !MODEL3D_HPP_ */
