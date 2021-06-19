/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** WindowTools
*/

#ifndef WINDOWTOOLS_HPP_
#define WINDOWTOOLS_HPP_

#include <string>

#include "Raylib.hpp"

namespace Raylib
{
    class WindowTools
    {
        public:
            WindowTools() {}
            ~WindowTools()
            {
            }

            inline WindowTools &ClearBackground(const ::Color &color = BLACK)
            {
                ::ClearBackground(color);
                return *this;
            }

            inline int GetScreenWidth() const
            {
                return ::GetScreenWidth();
            }

            inline int GetScreenHeight() const
            {
                return ::GetScreenHeight();
            }

        protected:
        private:
    };
}


#endif /* !WINDOWTOOLS_HPP_ */