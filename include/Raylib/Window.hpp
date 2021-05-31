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
        public:Window(int width, int height, const std::string &title) {        //Constructor
            Init(width, height, title);
        }
        ~Window() {                                                             //Destructor
            Close();
        }

        void Init(int width, int height, const std::string &title) {            //Create Window
            ::InitWindow(width, height, title.c_str());
        }
        inline bool ShouldClose() {                                             //Check if KEY_ESCAPE pressed or Close icon pressed
            return ::WindowShouldClose();
        }
        inline void Close() {                                                   //Close window and unload OpenGL context
            ::CloseWindow();
        }
        protected:
        private:
    };
}

#endif /* !WINDOW_HPP_ */
