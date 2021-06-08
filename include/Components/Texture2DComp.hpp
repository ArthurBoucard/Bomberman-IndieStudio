/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Texture2DComp
*/

#ifndef TEXTURE2DCOMP_HPP_
#define TEXTURE2DCOMP_HPP_

#include "Components.hpp"
#include "../Raylib/Raylib.hpp"

class Texture2DComp {
    public:
        Texture2DComp(Texture2D texture);
        ~Texture2DComp();

        void link(int id);
        int getLink();
        Texture2D getTexture();
    protected:
        int _link;
        Texture2D _texture;
    private:
};

#endif /* !TEXTURE2DCOMP_HPP_ */
