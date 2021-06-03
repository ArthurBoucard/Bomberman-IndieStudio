/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>

#include "Raylib.hpp"

namespace Raylib {
    class Window {
        public:
            Window() {}
            Window(int width, int height, const std::string &title)               //Constructor - Creates window
            {
                InitWindow(width, height, title.c_str());
            }
            ~Window()                                                             //Destructor - Cloases window
            {
                CloseWindow();
            }

            inline bool ShouldClose()                                             //Check if KEY_ESCAPE pressed or Close icon pressed
            {
                return WindowShouldClose();
            }

        protected:
        private:
    };
}

#endif /* !WINDOW_HPP_ */
