/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Rectangle : public ::Rectangle {
        public:
            Rectangle() {}
            Rectangle(float x, float y, float width, float height) : ::Rectangle{x, y, width, height} {}
            ~Rectangle()
            {}

            inline Rectangle &Draw(float roundness, int segments, Color color)
            {
                DrawRectangleRounded(*this, roundness, segments, color);
                return *this;
            }
    };
}

#endif /* !RECTANGLE_HPP_ */
