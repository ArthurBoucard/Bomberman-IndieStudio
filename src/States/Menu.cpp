/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Menu
*/

#include "../../include/States/Menu.hpp"

Menu::Menu()
{
    _music.LoadMusic("../assets/music/music_menu.mp3");
    _music.Play();
    _bg.LoadFile("../assets/pictures/bg.png");

    _button.Load("../assets/sound/button.wav");

    _playGame = Raylib::Text("NEW GAME");
    _title = Raylib::Text("BOMBERMAN");
    _settings = Raylib::Text("SETTINGS");
    _howToPlay = Raylib::Text("HOW TO PLAY");
    _stat = Raylib::Text("STATS");
    _load = Raylib::Text("LOAD GAME");
}

Menu::~Menu()
{
}

bool Menu::CheckMouse(Vector2 mouse, Raylib::Rectangle rect, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        rect.Draw(50, 50, RED);
        if (state == 1)
            _playGame.Draw(_rectPlayGame.x + _screenWidth / 26, _rectPlayGame.y + _screenHeight / 30, (_screenWidth / 17) - (_screenHeight / 20), BLACK);
        if (state == 2)
            _settings.Draw(rect.x + _screenWidth / 40, rect.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
        if (state == 3)
            _howToPlay.Draw(rect.x + _screenWidth / 90, rect.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
        if (state == 4)
            _stat.Draw(rect.x + _screenWidth / 20, rect.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
        if (state == 5)
            _load.Draw(rect.x + _screenWidth / 26, rect.y + _screenHeight / 28, (_screenWidth / 18) - (_screenHeight / 20), BLACK);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return true;
    }
    return false;
}

void Menu::Draw()
{
    _bg.Draw(0, 0, RAYWHITE);
    _rectPlayGame.Draw(50, 50, RAYWHITE);
    _rectSettings.Draw(50, 50, RAYWHITE);
    _rectHowToPlay.Draw(50, 50, RAYWHITE);
    _rectStats.Draw(50, 50, RAYWHITE);
    _rectLoad.Draw(50, 50, RAYWHITE);
}

void Menu::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
    _mouse = GetMousePosition();

    _rectPlayGame = Raylib::Rectangle(_screenWidth / static_cast<float>(2.7), _screenHeight / static_cast<float>(2.5), _screenWidth / 4, _screenHeight / 8);
    _rectLoad = Raylib::Rectangle(_screenWidth / static_cast<float>(2.7), _screenHeight / static_cast<float>(1.7), _screenWidth / 4, _screenHeight / 8);
    _rectSettings = Raylib::Rectangle(_screenWidth / 6, _screenHeight / static_cast<float>(1.3), _screenWidth / 6, _screenHeight / 10);
    _rectHowToPlay = Raylib::Rectangle(_screenWidth / static_cast<float>(2.4), _screenHeight / static_cast<float>(1.3), _screenWidth / static_cast<float>(5.5), _screenHeight / 10);
    _rectStats = Raylib::Rectangle(_screenWidth / static_cast<float>(1.45), _screenHeight / static_cast<float>(1.3), _screenWidth / static_cast<float>(5.5), _screenHeight / 10);

    _title.Draw(_screenWidth / static_cast<float>(4.5), _screenHeight / 6, (_screenWidth / 8) - (_screenHeight / 15), WHITE);
    _playGame.Draw(_rectPlayGame.x + _screenWidth / 26, _rectPlayGame.y + _screenHeight / 30, (_screenWidth / 17) - (_screenHeight / 20), BLACK);
    _load.Draw(_rectLoad.x + _screenWidth / 26, _rectLoad.y + _screenHeight / 28, (_screenWidth / 18) - (_screenHeight / 20), BLACK);
    _settings.Draw(_rectSettings.x + _screenWidth / 40, _rectSettings.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
    _howToPlay.Draw(_rectHowToPlay.x + _screenWidth / 90, _rectHowToPlay.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);
    _stat.Draw(_rectStats.x + _screenWidth / 20, _rectHowToPlay.y + _screenHeight / 30, (_screenWidth / 23) - (_screenHeight / 26), BLACK);

    _music.Update();
}

void Menu::Clear()
{
    ClearBackground(RAYWHITE);
}

void Menu::HandleInput()
{
    if (CheckMouse(_mouse, _rectPlayGame, 1) == true)
    {
        _button.Play();
        _context->TransitionTo(new GameSettings);
    }
    if (CheckMouse(_mouse, _rectSettings, 2) == true)
    {
        _button.Play();
        printf("Settings\n");
    }
    if (CheckMouse(_mouse, _rectHowToPlay, 3) == true)
    {
        _button.Play();
        printf("Tuto\n");
    }
    if (CheckMouse(_mouse, _rectStats, 4) == true)
    {
        _button.Play();
        printf("Stat\n");
    }
    if (CheckMouse(_mouse, _rectLoad, 5) == true)
    {
        _button.Play();
        LoadSave();

        std::cout << _nbPlayer << std::endl;
        std::cout << _nbIA << std::endl;
        for(int i = 0; i < _map.size(); i++)
            std::cout << _map[i] << std::endl;
        for(int i = 0; i < _skin.size(); i++)
            std::cout << _skin[i] << std::endl;

        _context->TransitionTo(new Game(_nbPlayer, _nbIA, _map, _skin));
    }
}

void Menu::Reset()
{
}

void Menu::LoadSave()
{
    std::ifstream mapFile("../assets/saveFile.txt");
	std::string line;
    std::string lastFlag;

    getline(mapFile, lastFlag);
    try {
        if (mapFile) {
            while (getline(mapFile, line))
            {
                if (lastFlag == ">NB_PLAYER")
                {
                    lastFlag = "";
                    _nbPlayer = std::stoi(line);
                }
                else if (lastFlag == ">NB_IA")
                {
                    lastFlag = "";
                    _nbIA = std::stoi(line);
                }
                else if (lastFlag == ">MAP" && line[0] != '>')
                    _map.push_back(line);
                else if (lastFlag == ">SKIN" && line[0] != '>')
                    _skin.push_back(line);

                if (line[0] == '>')
                        lastFlag = line;
            }
        }
    }
    catch(Exception const& e) {
        std::cerr << "Error: could not open \"./map\"" << e.what() << std::endl;
        exit(84);
    }
}