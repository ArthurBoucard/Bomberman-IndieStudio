/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <iostream>

class ICharacter {
    public:
        ICharacter();
        ~ICharacter();

        //skin
        virtual void SetSkin() = 0;

        virtual std::string GetSkin() const = 0;

        //stats
        virtual void SetBombQuantity() = 0;
        virtual void SetSpeed() = 0;
        virtual void SetRange() = 0;

        virtual unsigned int GetBombQuantity() const = 0;
        virtual unsigned int GetSpeed() const = 0;
        virtual unsigned int GetRange() const = 0;

    private:
        //skin
        std::string _skin;

        //stats
        unsigned int _bombQuantity;
        unsigned int _speed;
        unsigned int _range;
};

#endif /* !ICHARACTER_HPP_ */
