/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** init raylib
*/

#ifndef INITRAYLIB_HPP_
#define INITRAYLIB_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class InitRaylib {
        public:
            InitRaylib() {}
            ~InitRaylib()                                                                                        //Destructor - unload
            {
                CloseAudioDevice();
            }

            void Init()
            {
                InitMusic();
                InitWindow();
            }
            void InitMusic()
            {
                InitAudioDevice();
            }

            void InitWindow()
            {
                SetConfigFlags(FLAG_WINDOW_RESIZABLE);
                SetTargetFPS(60);
            }

        protected:
        private:
    };
}

#endif /* !INITRAYLIB_HPP_ */
