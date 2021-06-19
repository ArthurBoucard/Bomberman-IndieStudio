/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Sound : public ::Sound {
        public:
            Sound() {}
            Sound(const std::string &fileName)                                                              //Constructor with file
            {
                Load(fileName);
            }
            ~Sound()                                                                                        //Destructor - unload sound
            {
                ::UnloadSound(*this);
            }

            void Load(const std::string &fileName)                                                     //Load sound
            {
                set(::LoadSound(fileName.c_str()));
            }
            inline Sound& Play()                                                                            //Play sound
            {
                ::PlaySound(*this);
                return *this;
            }

        protected:
            inline void set(::Sound sound)                                                                 //Set sound value
            {
                sampleCount = sound.sampleCount;
                stream = sound.stream;
            }
        private:
    };
}

#endif /* !SOUND_HPP_ */
