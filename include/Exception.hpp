/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-arcade-lucas.arroyo
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <ostream>

class Exception
{
    public:
        Exception(std::string const &str = "") throw(): _str(str){}

        virtual const char *what() const throw()
        {
            return _str.c_str();
        }

        virtual ~Exception() throw() {}

    private:
        std::string _str;
};

#endif /* !EXCEPTION_HPP_ */
