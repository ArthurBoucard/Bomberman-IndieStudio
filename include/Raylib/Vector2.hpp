/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Vector2
*/

#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Vector2 : public ::Vector2 {
        public:
            Vector2(::Vector2 vec)                                                              //Create Vector2 from anoter one
            {
                set(vec);
            }
            Vector2(float x, float y)                                                           //Create Vector2 from x and y
            {
                set(::Vector2{x, y});
            }
            ~Vector2();                                                                         //Destructor
        protected:
            inline void set(::Vector2 vec)                                                      //Set vector2 values
            {
                x = vec.x;
                y = vec.y;
            }
        private:
    };
}

#endif /* !VECTOR2_HPP_ */
