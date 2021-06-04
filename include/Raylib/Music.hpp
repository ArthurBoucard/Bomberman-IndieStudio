/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Music : public ::Music {
        public:
            Music() {}
            Music(const std::string &fileName)                                                              //Constructor with file
            {
                LoadMusic(fileName);
            }
            ~Music()                                                                                        //Destructor - unload music
            {
                ::UnloadMusicStream(*this);
            }

            void LoadMusic(const std::string &fileName)                                                     //Load music
            {
                set(::LoadMusicStream(fileName.c_str()));
            }
            inline Music& Play()                                                                            //Play music
            {
                ::PlayMusicStream(*this);
                return *this;
            }
            inline Music& Update()                                                                          //Update music
            {
                ::UpdateMusicStream(*this);
                return *this;
            }

        protected:
            inline void set(::Music music)                                                                 //Set music value
            {
                ctxType = music.ctxType;
                ctxData = music.ctxData;
                looping = music.looping;
                sampleCount = music.sampleCount;
                stream = music.stream;
            }
        private:
    };
}

#endif /* !MUSIC_HPP_ */
