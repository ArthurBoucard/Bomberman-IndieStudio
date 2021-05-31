/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "ICharacter.hpp"

class AI : public ICharacter
{
    public:
        AI();
        ~AI();

        //skin
        void SetSkin();

        std::string GetSkin() const;

        //Stats
        void SetBombQuantity();
        void SetSpeed();
        void SetRange();

        unsigned int GetBombQuantity() const;
        unsigned int GetSpeed() const;
        unsigned int GetRange() const;

    private:
        //skin
        std::string _skin;

        //stats
        unsigned int _bombQuantity;
        unsigned int _speed;
        unsigned int _range;
};

#endif /* !AI_HPP_ */
