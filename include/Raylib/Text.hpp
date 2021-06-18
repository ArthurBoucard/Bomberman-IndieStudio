/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Text {
        public:
            Text()
            {}
            Text(const char *text) {
                TEXT = text;
            }
            ~Text()                                                             //Destructor - Unload texture
            {}

            const char *getChar()
            {
                return TEXT;
            }
            inline Text &Draw(int posX, int posY, int fontSize, Color color)
            {
                DrawText(TEXT, posX, posY, fontSize, color);
                return *this;
            }

        protected:
        private:
            const char *TEXT;
    };
}

#endif /* !TEXT_HPP_ */
