/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Texture : public ::Texture {
        public:
            Texture() {}
            Texture(const Image &image)                                            //Constructor with image
            {
                LoadImage(image);
            }
            Texture(const std::string &fileName)                                   //Constructor with file
            {
                LoadFile(fileName);
            }
            ~Texture()                                                             //Destructor - Unload texture
            {
                UnloadTexture(*this);
            }

            void LoadImage(const Image &image)                                     //Load from image
            {
                set(::LoadTextureFromImage(image));
            }
            void LoadFile(const std::string &fileName)                             //Load from file
            {
                set(::LoadTexture(fileName.c_str()));
            }

            int getId()                                                            //Get ID 
            {
                return this->id;
            }
            int getWidth()                                                         //Get Width
            {
                return this->width;
            }
            int getHeight()                                                        //Get Height
            {
                return this->height;
            }
            int getMipmaps()                                                       //Get Mipmaps
            {
                return this->mipmaps;
            }
            int getFormat()                                                        //Get Format
            {
                return this->format;
            }

            inline Texture &Draw(int posX, int posY, Color tint)                                 //Draw texture
            {
                DrawTexture(*this, posX, posY, tint);
                return *this;
            }
            inline Texture &DrawEx(Vector2 position, float rotation, float scale, Color tint)    //Draw texture with scale
            {
                DrawTextureEx(*this, position, rotation, scale, tint);
                return *this;
            }

        protected:
            inline void set(::Texture texture)                                       //Set texture values
            {
                id = texture.id;
                width = texture.width;
                height = texture.height;
                mipmaps = texture.mipmaps;
                format = texture.format;
            }
        private:
    };
    typedef Texture Texture2D;
}

#endif /* !TEXTURE_HPP_ */
