/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Win
*/

#ifndef WIN_HPP_
#define WIN_HPP_

#include "../StatesManagement/State.hpp"
#include "../States/Menu.hpp"
#include "../Raylib/Raylib.hpp"

class Win : public State
{
public:
    Win(int nbPlayer, int nbIA, int skin1, int skin2, std::string);
    ~Win();

    void Draw();
    void Update();
    void Clear();
    void HandleInput();
    void Reset();

    bool CheckMouse(Vector2, Raylib::Rectangle, Raylib::Text, int state);

private:
    Raylib::Texture2D _bgWin;

    Raylib::Rectangle _rectBack;
    Raylib::Rectangle _rectAgain;

    std::string _stringWin;
    Image _imageWin;
    Texture2D _textureWin;
    Vector2 _vectorImage;

    int _screenWidth;
    int _screenHeight;

    Vector2 _mouse;

    std::string _win;
    Raylib::Text _back;
    Raylib::Text _again;

    int _nbPlayer;
    int _nbIA;
    int _skin1;
    int _skin2;

    Raylib::Sound _winMusic;
};

#endif /* !WIN_HPP_ */
