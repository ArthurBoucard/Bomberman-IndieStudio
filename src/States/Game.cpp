/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Game
*/

#include "../../include/States/Game.hpp"

Game::Game(int nbPlayer, int nbIA, int skin1, int skin2)
{
    Map map = Map();

    _music.LoadMusic("../assets/music/game.xm");
    _music.Play();

    _poseBomb.Load("../assets/sound/poseBomb.wav");
    _explosionBomb.Load("../assets/sound/explosion.wav");
    _deathPlayer.Load("../assets/sound/uh.wav");
    _powerUp.Load("../assets/sound/powerUp.wav");

    _nbPlayer = nbPlayer;
    _nbIA = nbIA;
    _skinChoicePl1 = skin1;
    _skinChoicePl2 = skin2;
    if (skin1 < skin2)
        skin2--;

    map.createMap();
    map.proceduralGenClassical();
    map.placePlayers(_nbPlayer, _nbIA);
    _map = map.getMap();

    Texture2D brickT = LoadTexture("../assets/pictures/block.png");
    Texture2D wallT = LoadTexture("../assets/pictures/wall.png");
    Texture2D grassT = LoadTexture("../assets/pictures/grass.png");

    _camera.position = {0.0f, 12.0f, 10.0f};
    _camera.target = {0.0f, 0.0f, 0.0f};
    _camera.up = {0.0f, 2.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;

    Model model1 = LoadModel("../assets/skin/guy.iqm");
    if (skin1 >= 0)
        model1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin(skin1);
    else
        model1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin();

    Model model2 = LoadModel("../assets/skin/guy.iqm");
    if (skin2 >= 0)
        model2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin(skin2);
    else
        model2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin();

    Model model3 = LoadModel("../assets/skin/guy.iqm");
    model3.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin();

    Model model4 = LoadModel("../assets/skin/guy.iqm");
    model4.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getSkin();

    int whichAI = 0;

    for (float x = 0; x < _map.size(); x++)
    {
        for (float z = 0; z < _map[x].size(); z++)
        {
            if (_map[x][z] == 'o')
            {
                Entity *bomb = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(bomb->getId());
                _positionList.push_back(pos);
                Bomb *b = new Bomb(2);
                b->link(bomb->getId());
                _bombList.push_back(b);
            }
            if (_map[x][z] != 'X')
            {
                Entity *ground = new Entity;
                Position *pos = new Position(x, z, -1);
                pos->link(ground->getId());
                _positionList.push_back(pos);
                Texture2DComp *tex = new Texture2DComp(grassT);
                tex->link(ground->getId());
                _texture2DList.push_back(tex);
            }
            if (_map[x][z] == 'X')
            {
                Entity *wall = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(wall->getId());
                _positionList.push_back(pos);
                Texture2DComp *tex = new Texture2DComp(wallT);
                tex->link(wall->getId());
                _texture2DList.push_back(tex);
                Solid *solid = new Solid(false);
                solid->link(wall->getId());
                _solidList.push_back(solid);
            }
            if (_map[x][z] == '#')
            {
                Entity *brick = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(brick->getId());
                _positionList.push_back(pos);
                Breakable *br = new Breakable;
                br->link(brick->getId());
                _breakableList.push_back(br);
                Texture2DComp *tex = new Texture2DComp(brickT);
                tex->link(brick->getId());
                _texture2DList.push_back(tex);
                Solid *solid = new Solid(true);
                solid->link(brick->getId());
                _solidList.push_back(solid);
            }
            if (_map[x][z] == '@')
            {
                Entity *ai = new Entity;               //Entity
                Position *pos = new Position(x, z, 0); //Position
                pos->link(ai->getId());
                _positionList.push_back(pos);
                Player *pl = new Player("AI", 2 + whichAI); //Player
                pl->link(ai->getId());
                _playerList.push_back(pl);
                Model3D *mod = new Model3D(); //Model3D
                if (whichAI == 0)
                    mod->setModel(model3);
                else if (whichAI == 1)
                    mod->setModel(model4);
                else if (whichAI == 2)
                    mod->setModel(model2);
                else
                    mod->setModel(model1);
                mod->link(ai->getId());
                _model3DList.push_back(mod);
                Jump *jp = new Jump(); //Jump
                jp->link(ai->getId());
                _jumpList.push_back(jp);
                whichAI++;
            }
            if (_map[x][z] == '0' || _map[x][z] == '1')
            {
                Entity *player = new Entity;           //Entity
                Position *pos = new Position(x, z, 0); //Position
                pos->link(player->getId());
                _positionList.push_back(pos);
                Player *pl = new Player("player", _map[x][z] - 48); //Player
                pl->link(player->getId());
                _playerList.push_back(pl);
                Model3D *mod = new Model3D(); //Model3D
                if (_map[x][z] == '0')
                    mod->setModel(model1);
                else
                    mod->setModel(model2);
                mod->link(player->getId());
                _model3DList.push_back(mod);
                Jump *jp = new Jump(); //Jump
                jp->link(player->getId());
                _jumpList.push_back(jp);
            }
        }
    }
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();

    for (int i = 4; i > 0; i--)
    {
        Entity *card = new Entity;
        Card *c = new Card(i);
        c->link(card->getId());
        if (nbPlayer >= 1 && i == 1)
        {
            c->setHead(getHead(skin1));
            for (std::size_t i = 0; i < _playerList.size(); i++)
                if (_playerList[i]->getPlayerID() == 0)
                    c->setName(_playerList[i]->getPlayerName());
        }
        else if (nbPlayer >= 2 && i == 4)
        {
            c->setHead(getHead(skin2));
            for (std::size_t i = 0; i < _playerList.size(); i++)
                if (_playerList[i]->getPlayerID() == 1)
                    c->setName(_playerList[i]->getPlayerName());
        }
        else
        {
            c->setHead(getHead(i));
            for (std::size_t i = 0; i < _playerList.size(); i++)
                if (_playerList[i]->getPlayerID() >= 2)
                    c->setName(_playerList[i]->getPlayerName());
        }
        _cardList.push_back(c);
    }
}

Game::Game(int nbPlayer, int nbIA, const std::vector<std::string> &map, const std::vector<std::string> &skin)
{
    _map = map;

    _music.LoadMusic("../assets/music/game.xm");
    _music.Play();

    _poseBomb.Load("../assets/sound/poseBomb.wav");
    _explosionBomb.Load("../assets/sound/explosion.wav");
    _deathPlayer.Load("../assets/sound/uh.wav");
    _powerUp.Load("../assets/sound/powerUp.wav");

    _nbPlayer = nbPlayer;
    _nbIA = nbIA;
    _saveSkin = skin;

    Texture2D brickT = LoadTexture("../assets/pictures/block.png");
    Texture2D wallT = LoadTexture("../assets/pictures/wall.png");
    Texture2D grassT = LoadTexture("../assets/pictures/grass.png");

    _camera.position = {0.0f, 12.0f, 10.0f};
    _camera.target = {0.0f, 0.0f, 0.0f};
    _camera.up = {0.0f, 2.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;

    Model model1 = LoadModel("../assets/skin/guy.iqm");
    model1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(skin[0].c_str());

    Model model2 = LoadModel("../assets/skin/guy.iqm");
    model2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(skin[1].c_str());

    Model model3 = LoadModel("../assets/skin/guy.iqm");
    model3.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(skin[2].c_str());

    Model model4 = LoadModel("../assets/skin/guy.iqm");
    model4.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(skin[3].c_str());

    int whichAI = 0;

    for (float x = 0; x < _map.size(); x++)
    {
        for (float z = 0; z < _map[x].size(); z++)
        {
            if (_map[x][z] == 'o')
            {
                Entity *bomb = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(bomb->getId());
                _positionList.push_back(pos);
                Bomb *b = new Bomb(2);
                b->link(bomb->getId());
                _bombList.push_back(b);
            }
            if (_map[x][z] != 'X')
            {
                Entity *ground = new Entity;
                Position *pos = new Position(x, z, -1);
                pos->link(ground->getId());
                _positionList.push_back(pos);
                Texture2DComp *tex = new Texture2DComp(grassT);
                tex->link(ground->getId());
                _texture2DList.push_back(tex);
            }
            if (_map[x][z] == 'X')
            {
                Entity *wall = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(wall->getId());
                _positionList.push_back(pos);
                Texture2DComp *tex = new Texture2DComp(wallT);
                tex->link(wall->getId());
                _texture2DList.push_back(tex);
                Solid *solid = new Solid(false);
                solid->link(wall->getId());
                _solidList.push_back(solid);
            }
            if (_map[x][z] == '#')
            {
                Entity *brick = new Entity;
                Position *pos = new Position(x, z, 0);
                pos->link(brick->getId());
                _positionList.push_back(pos);
                Breakable *br = new Breakable;
                br->link(brick->getId());
                _breakableList.push_back(br);
                Texture2DComp *tex = new Texture2DComp(brickT);
                tex->link(brick->getId());
                _texture2DList.push_back(tex);
                Solid *solid = new Solid(true);
                solid->link(brick->getId());
                _solidList.push_back(solid);
            }
            if (_map[x][z] == '@')
            {
                Entity *ai = new Entity;               //Entity
                Position *pos = new Position(x, z, 0); //Position
                pos->link(ai->getId());
                _positionList.push_back(pos);
                Player *pl = new Player("AI", 2 + whichAI); //Player
                pl->link(ai->getId());
                _playerList.push_back(pl);
                Model3D *mod = new Model3D(); //Model3D
                if (whichAI == 0)
                    mod->setModel(model3);
                else if (whichAI == 1)
                    mod->setModel(model4);
                else if (whichAI == 2)
                    mod->setModel(model2);
                else
                    mod->setModel(model1);
                mod->link(ai->getId());
                _model3DList.push_back(mod);
                Jump *jp = new Jump(); //Jump
                jp->link(ai->getId());
                _jumpList.push_back(jp);
                whichAI++;
            }
            if (_map[x][z] == '0' || _map[x][z] == '1')
            {
                Entity *player = new Entity;           //Entity
                Position *pos = new Position(x, z, 0); //Position
                pos->link(player->getId());
                _positionList.push_back(pos);
                Player *pl = new Player("player", _map[x][z] - 48); //Player
                pl->link(player->getId());
                _playerList.push_back(pl);
                Model3D *mod = new Model3D(); //Model3D
                if (_map[x][z] == '0')
                    mod->setModel(model1);
                else
                    mod->setModel(model2);
                mod->link(player->getId());
                _model3DList.push_back(mod);
                Jump *jp = new Jump(); //Jump
                jp->link(player->getId());
                _jumpList.push_back(jp);
            }
        }
    }
}

Game::~Game()
{
    for (std::size_t i = 0; i < _positionList.size(); i++)
        delete _positionList[i];
    for (std::size_t i = 0; i < _breakableList.size(); i++)
        delete _breakableList[i];
    for (std::size_t i = 0; i < _texture2DList.size(); i++)
    {
        UnloadTexture(_texture2DList[i]->getTexture());
        delete _texture2DList[i];
    }
    for (std::size_t i = 0; i < _playerList.size(); i++)
        delete _playerList[i];
    for (std::size_t i = 0; i < _model3DList.size(); i++)
    {
        UnloadModel(_model3DList[i]->getModel());
        delete _model3DList[i];
    }
    for (std::size_t i = 0; i < _jumpList.size(); i++)
        delete _jumpList[i];
    for (std::size_t i = 0; i < _bombList.size(); i++)
        delete _bombList[i];
    for (std::size_t i = 0; i < _solidList.size(); i++)
        delete _solidList[i];
    for (std::size_t i = 0; i < _flameList.size(); i++)
        delete _flameList[i];
    for (std::size_t i = 0; i < _powerUpList.size(); i++)
        delete _powerUpList[i];
    for (std::size_t i = 0; i < _cardList.size(); i++)
        delete _cardList[i];
}

void Game::Draw()
{
    // Animation of bomb placement
    for (std::size_t i = 0, j = 0; i < _jumpList.size(); i++, j = 0)
    {
        for (j = 0; _jumpList[i]->getLink() != _model3DList[j]->getLink(); j++)
        {
        }
        if (_jumpList[i]->getJump())
        {
            _jumpList[i]->setFrameCount(_jumpList[i]->getFrameCount() + 1);
            UpdateModelAnimation(_model3DList[j]->getModel(), _jumpList[i]->getAnim(), _jumpList[i]->getFrameCount());
            if (_jumpList[i]->getFrameCount() >= _jumpList[i]->getAnim().frameCount)
            {
                _jumpList[i]->setFrameCount(0);
                _jumpList[i]->setJump(false);
            }
        }
    }
    BeginMode3D(_camera);
    for (std::size_t i = 0, j = 0, p = 0; i < _positionList.size(); i++, j = 0)
    {
        // Draw Texture
        for (j = 0; j < _texture2DList.size(); j++)
        {
            int test = 0;
            for (int n = 0; n < _powerUpList.size(); n++)
                if (_texture2DList[j]->getLink() == _positionList[i]->getLink() && _texture2DList[j]->getLink() == _powerUpList[n]->getLink())
                    test = 1;
            if (_texture2DList[j]->getLink() == _positionList[i]->getLink() && test == 0)
                DrawCubeTexture(_texture2DList[j]->getTexture(),
                                {_positionList[i]->getX() - 6,
                                 _positionList[i]->getZ(),
                                 _positionList[i]->getY() - 9},
                                1, 1, 1, WHITE);
            if (_texture2DList[j]->getLink() == _positionList[i]->getLink() && test == 1)
                DrawCubeTexture(_texture2DList[j]->getTexture(),
                                {_positionList[i]->getX() - 6,
                                 _positionList[i]->getZ(),
                                 _positionList[i]->getY() - 9},
                                0.5, 0.5, 0.5, WHITE);
        }
        // Draw Model3D
        for (j = 0; j < _model3DList.size(); j++)
        {
            for (p = 0; _playerList[p]->getLink() != _model3DList[j]->getLink(); p++)
            {
            }
            if (_model3DList[j]->getLink() == _positionList[i]->getLink() && _playerList[p]->getIsAlive())
                DrawModelEx(_model3DList[j]->getModel(),
                            {_positionList[i]->getX() - 6,
                             _positionList[i]->getZ() - 0.5f,
                             _positionList[i]->getY() - 9},
                            {1.0f, 0.0f, 0.0f}, -90.0f,
                            {0.15f, 0.15f, 0.15f}, WHITE);
        }
        // Draw Bomb
        for (j = 0; j < _bombList.size(); j++)
        {
            if (_bombList[j]->getLink() == _positionList[i]->getLink())
            {
                DrawSphere({_positionList[i]->getX() - 6,
                            _positionList[i]->getZ() - 0.1f,
                            _positionList[i]->getY() - 9},
                           0.4f, DARKGRAY);
                DrawSphereWires({_positionList[i]->getX() - 6,
                                 _positionList[i]->getZ() - 0.1f,
                                 _positionList[i]->getY() - 9},
                                0.4f, 16, 16, BLACK);
            }
        }
        // Draw Flame
        for (j = 0; j < _flameList.size(); j++)
        {
            if (_flameList[j]->getLink() == _positionList[i]->getLink())
            {
                DrawSphere({_positionList[i]->getX() - 6,
                            _positionList[i]->getZ() - 0.1f,
                            _positionList[i]->getY() - 9},
                           0.35f, RED);
                DrawSphereWires({_positionList[i]->getX() - 6,
                                 _positionList[i]->getZ() - 0.1f,
                                 _positionList[i]->getY() - 9},
                                0.35f, 16, 16, ORANGE);
            }
        }
    }
    EndMode3D();
    drawPlayerUI();
}

void Game::Update()
{
    _screenWidth = GetScreenWidth();
    _screenHeight = GetScreenHeight();
    _music.Update();

    // Check if power up is picked up
    usePower();

    for (std::size_t i = 0; i < _bombList.size(); i++)
    {
        clock_t end = clock();
        if (end - _bombList[i]->getClock() >= 900000)
            _bombList[i]->setIsExplode(true);
    }
    // Make bomb explode
    for (std::size_t i = 0, p = 0; i < _bombList.size(); i++)
    {
        if (_bombList[i]->getIsExplode())
        {
            for (p = 0; _bombList[i]->getLink() != _positionList[p]->getLink(); p++)
            {
            }
            for (int dir = 1; dir <= 4; dir++)
            {
                Entity *flame = new Entity;
                Flame *fl = new Flame(_bombList[i]->getRadius(), dir, *_positionList[p]);
                fl->link(flame->getId());
                _flameList.push_back(fl);
                Position *pos = new Position(_positionList[p]->getX(), _positionList[p]->getY(), _positionList[p]->getZ());
                pos->link(flame->getId());
                _positionList.push_back(pos);
            }
            deleteEntity(_bombList[i]->getLink());
        }
    }
    // Move flames of exploded bomb
    for (std::size_t i = 0, p = 0, p2 = 0, k = 0, m = 0; i < _flameList.size(); i++)
    {
        clock_t end = clock();
        if (end - _flameList[i]->getClock() >= 30000)
        {
            _explosionBomb.Play();
            _flameList[i]->resetClock();
            if (_flameList[i]->getDist() == 0)
            {
                deleteEntity(_flameList[i]->getLink());
                break;
            }
            for (p = 0; _flameList[i]->getLink() != _positionList[p]->getLink(); p++)
            {
            }
            _flameList[i]->move();
            if (_flameList[i]->getDirection() == 1)
                _positionList[p]->setX(_positionList[p]->getX() - 1);
            else if (_flameList[i]->getDirection() == 2)
                _positionList[p]->setY(_positionList[p]->getY() + 1);
            else if (_flameList[i]->getDirection() == 3)
                _positionList[p]->setX(_positionList[p]->getX() + 1);
            else if (_flameList[i]->getDirection() == 4)
                _positionList[p]->setY(_positionList[p]->getY() - 1);
            // Test if flame goes in wall or brick
            for (k = 0; k < _solidList.size(); k++)
            {
                for (p2 = 0; p2 < _positionList.size(); p2++)
                {
                    if (_positionList[p]->getX() == _positionList[p2]->getX() &&
                        _positionList[p]->getY() == _positionList[p2]->getY() &&
                        _positionList[p]->getZ() == _positionList[p2]->getZ())
                    {
                        if (_solidList[k]->getLink() == _positionList[p2]->getLink())
                        {
                            for (m = 0; m < _breakableList.size(); m++)
                                if (_breakableList[m]->getLink() == _positionList[p2]->getLink())
                                {
                                    if (GetRandomValue(0, 2) == 2)
                                    {
                                        Entity *powerUp = new Entity;
                                        PowerUp *pu = new PowerUp;
                                        pu->setPower();
                                        pu->link(powerUp->getId());
                                        _powerUpList.push_back(pu);
                                        _positionList[p2]->link(powerUp->getId());
                                        Texture2DComp *tex = new Texture2DComp(pu->getTexture());
                                        tex->link(powerUp->getId());
                                        _texture2DList.push_back(tex);
                                    }
                                    _breakableList[m]->breakBrick();
                                    deleteEntity(_breakableList[m]->getLink());
                                    break;
                                }
                            deleteEntity(_flameList[i]->getLink());
                            break;
                        }
                    }
                }
            }
            // Test if flame goes in player
            for (k = 0; k < _playerList.size(); k++)
            {
                for (p2 = 0; p2 < _positionList.size(); p2++)
                {
                    if (_positionList[p]->getX() == round(_positionList[p2]->getX()) &&
                        _positionList[p]->getY() == round(_positionList[p2]->getY()) &&
                        _positionList[p]->getZ() == round(_positionList[p2]->getZ()) && p != p2)
                    {
                        if (_playerList[k]->getLink() == _positionList[p2]->getLink())
                        {
                            _playerList[k]->setIsAlive(false); // make player dead
                            deleteEntity(_flameList[i]->getLink());
                            _deathPlayer.Play();
                            break;
                        }
                    }
                }
            }
        }
    }
    // AI movement
    for (int i = 0; i < _playerList.size(); i++)
    {
        if (_playerList[i]->getPlayerID() >= 2)
        {
            if (clock() - _playerList[i]->getClock() > 90000)
            {
                _playerList[i]->setClock(clock());
                for (int n = 0; n < _positionList.size(); n++)
                    if (_positionList[n]->getLink() == _playerList[i]->getLink())
                        moveAi(n, i);
            }
        }
    }
    if (testWin())
    {
        if (_nbPlayer == 1)
        {
            std::size_t i;
            for (i = 0; _playerList[i]->getPlayerID() != 0; i++)
                ;
            if (_playerList[i]->getIsAlive() == true)
                _context->TransitionTo(new Win(_nbPlayer, _nbIA, _skinChoicePl1, _skinChoicePl2, _skinChoicePl1));
            else
                _context->TransitionTo(new GameOver(_nbPlayer, _nbIA, _skinChoicePl1, _skinChoicePl2));
        }
        else
            _context->TransitionTo(new Win(_nbPlayer, _nbIA, _skinChoicePl1, _skinChoicePl2, _skinChoicePl1));
    }
}

void Game::Clear()
{
    ClearBackground(RAYWHITE);
}

void Game::HandleInput()
{
    Vector2 mouse = GetMousePosition();

    // PLayer control
    if (_nbPlayer > 0)
    {
        for (std::size_t i = 0, j = 0; i < _playerList.size(); i++)
        {
            if (_playerList[i]->getPlayerID() == 0 && _playerList[i]->getIsAlive())
            {
                for (j = 0; _playerList[i]->getLink() != _positionList[j]->getLink(); j++)
                {
                }
                if (IsKeyDown(KEY_A))
                    if (testCollision(_positionList[j], _playerList[i]->getSpeed() * (-1), 0))
                        _positionList[j]->setX(_positionList[j]->getX() - _playerList[i]->getSpeed());
                if (IsKeyDown(KEY_D))
                    if (testCollision(_positionList[j], _playerList[i]->getSpeed(), 0))
                        _positionList[j]->setX(_positionList[j]->getX() + _playerList[i]->getSpeed());
                if (IsKeyDown(KEY_W))
                    if (testCollision(_positionList[j], 0, _playerList[i]->getSpeed() * (-1)))
                        _positionList[j]->setY(_positionList[j]->getY() - _playerList[i]->getSpeed());
                if (IsKeyDown(KEY_S))
                    if (testCollision(_positionList[j], 0, _playerList[i]->getSpeed()))
                        _positionList[j]->setY(_positionList[j]->getY() + _playerList[i]->getSpeed());
                break;
            }
        }
    }
    if (_nbPlayer == 2)
    {
        for (std::size_t i = 0, j = 0; i < _playerList.size(); i++)
        {
            if (_playerList[i]->getPlayerID() == 1 && _playerList[i]->getIsAlive())
            {
                for (j = 0; _playerList[i]->getLink() != _positionList[j]->getLink(); j++)
                {
                }
                if (IsKeyDown(KEY_LEFT))
                    if (testCollision(_positionList[j], _playerList[i]->getSpeed() * (-1), 0))
                        _positionList[j]->setX(_positionList[j]->getX() - _playerList[i]->getSpeed());
                if (IsKeyDown(KEY_RIGHT))
                    if (testCollision(_positionList[j], _playerList[i]->getSpeed(), 0))
                        _positionList[j]->setX(_positionList[j]->getX() + _playerList[i]->getSpeed());
                if (IsKeyDown(KEY_UP))
                    if (testCollision(_positionList[j], 0, _playerList[i]->getSpeed() * (-1)))
                        _positionList[j]->setY(_positionList[j]->getY() - _playerList[i]->getSpeed());
                if (IsKeyDown(KEY_DOWN))
                    if (testCollision(_positionList[j], 0, _playerList[i]->getSpeed()))
                        _positionList[j]->setY(_positionList[j]->getY() + _playerList[i]->getSpeed());
                break;
            }
        }
    }
    // Bombs
    if (IsKeyPressed(KEY_Q) && _nbPlayer > 0)
        spawnBomb(0);
    if (IsKeyPressed(KEY_RIGHT_SHIFT) && _nbPlayer == 2)
        spawnBomb(1);

    if (IsKeyPressed(KEY_P))
    {
        saveMap();
        _context->TransitionTo(new Pause(_nbPlayer, _nbIA, _saveMap, _skinChoicePl1, _skinChoicePl2, _saveSkin));
    }
}

void Game::Reset()
{
}

void Game::drawPlayerUI()
{
    float x;
    float y;

    for (std::size_t i = 0; i < _cardList.size(); i++)
    {
        if (_cardList[i]->getId() == 1)
        {
            x = 50;
            y = 50;
        }
        else if (_cardList[i]->getId() == 2)
        {
            x = 1.2;
            y = 50;
        }
        else if (_cardList[i]->getId() == 3)
        {
            x = 50;
            y = 1.8;
        }
        else if (_cardList[i]->getId() == 4)
        {
            x = 1.2;
            y = 1.8;
        }
        DrawTextureEx(_cardList[i]->getHead(), {(_screenWidth / static_cast<float>(x)) + 2, (_screenHeight / static_cast<float>(y)) + 2},
                      0, _screenHeight / static_cast<float>(1000), WHITE);
        DrawText(_cardList[i]->getName().c_str(), (_cardList[i]->getHead().width + (_screenWidth / x)), _screenHeight / y,
                 (_screenWidth / 25) - (_screenHeight / 28), BLACK);
        DrawTextureEx(_cardList[i]->getPowerUpSpeed(), {(_screenWidth / static_cast<float>(x)) + (_cardList[i]->getPowerUpSpeed().width), (_screenHeight / static_cast<float>(y)) + (_cardList[i]->getHead().height * (_screenHeight / static_cast<float>(1000))) + 3 * (_cardList[i]->getPowerUpSpeed().width / 2)},
                      180, _screenHeight / static_cast<float>(800), WHITE);
        DrawText(std::to_string(_cardList[i]->getNbPowerUpSpeed()).c_str(), (_screenWidth / static_cast<float>(x)) + 2.5 * (_cardList[i]->getPowerUpSpeed().width / 2),
                 (_screenHeight / static_cast<float>(y)) + (_cardList[i]->getHead().height * (_screenHeight / static_cast<float>(1000))) + 2 * (_cardList[i]->getPowerUpSpeed().width / 2),
                 (_screenWidth / 35) - (_screenHeight / 38), BLACK);
        DrawTextureEx(_cardList[i]->getPowerUpFlameUp(), {(_screenWidth / static_cast<float>(x)) + (_cardList[i]->getPowerUpSpeed().width), (_screenHeight / static_cast<float>(y)) + (_cardList[i]->getHead().height * (_screenHeight / static_cast<float>(1000))) + 5 * (_cardList[i]->getPowerUpSpeed().width / 2)},
                      180, _screenHeight / static_cast<float>(800), WHITE);
        DrawText(std::to_string(_cardList[i]->getNbPowerUpFlameUp()).c_str(), (_screenWidth / static_cast<float>(x)) + 2.5 * (_cardList[i]->getPowerUpSpeed().width / 2),
                 (_screenHeight / static_cast<float>(y)) + (_cardList[i]->getHead().height * (_screenHeight / static_cast<float>(1000))) + 4 * (_cardList[i]->getPowerUpSpeed().width / 2),
                 (_screenWidth / 35) - (_screenHeight / 38), BLACK);
        DrawTextureEx(_cardList[i]->getPowerUpBombUp(), {(_screenWidth / static_cast<float>(x)) + 4 * (_cardList[i]->getPowerUpSpeed().width), (_screenHeight / static_cast<float>(y)) + (_cardList[i]->getHead().height * (_screenHeight / static_cast<float>(1000))) + 3 * (_cardList[i]->getPowerUpSpeed().width / 2)},
                      180, _screenHeight / static_cast<float>(800), WHITE);
        DrawText(std::to_string(_cardList[i]->getNbPowerUpSBombUp()).c_str(), (_screenWidth / static_cast<float>(x)) + 8.5 * (_cardList[i]->getPowerUpSpeed().width / 2),
                 (_screenHeight / static_cast<float>(y)) + (_cardList[i]->getHead().height * (_screenHeight / static_cast<float>(1000))) + 2 * (_cardList[i]->getPowerUpSpeed().width / 2),
                 (_screenWidth / 35) - (_screenHeight / 38), BLACK);
        DrawTextureEx(_cardList[i]->getPowerUpWallPass(), {(_screenWidth / static_cast<float>(x)) + 4 * (_cardList[i]->getPowerUpSpeed().width), (_screenHeight / static_cast<float>(y)) + (_cardList[i]->getHead().height * (_screenHeight / static_cast<float>(1000))) + 5 * (_cardList[i]->getPowerUpSpeed().width / 2)},
                      180, _screenHeight / static_cast<float>(800), WHITE);
        DrawText(std::to_string(_cardList[i]->getNbPowerUpWallPass()).c_str(), (_screenWidth / static_cast<float>(x)) + 8.5 * (_cardList[i]->getPowerUpSpeed().width / 2),
                 (_screenHeight / static_cast<float>(y)) + (_cardList[i]->getHead().height * (_screenHeight / static_cast<float>(1000))) + 4 * (_cardList[i]->getPowerUpSpeed().width / 2),
                 (_screenWidth / 35) - (_screenHeight / 38), BLACK);
    }
}

Texture2D Game::getSkin(int skin)
{
    std::string str = "../assets/skin/texture/guytex" + std::to_string(_skin[skin]) + ".png";
    _skin.erase(_skin.begin() + skin);

    _saveSkin.push_back(str);

    return LoadTexture(str.c_str());
}

Texture2D Game::getSkin()
{
    int index = GetRandomValue(0, (_skin.size() - 1));

    std::string str = "../assets/skin/texture/guytex" + std::to_string(_skin[index]) + ".png";
    _skin.erase(_skin.begin() + index);

    _saveSkin.push_back(str);

    return LoadTexture(str.c_str());
}

std::string Game::getHead(int head)
{
    std::string str = "../assets/skin/head/head" + std::to_string(_skin[head]) + ".png";

    return str;
}

void Game::moveAi(std::size_t positionIndex, std::size_t playerIndex)
{
    int rand = GetRandomValue(0, 4);

    if (rand == 0)
        if (testCollision(_positionList[positionIndex], _playerList[playerIndex]->getSpeed() * (-1), 0))
            _positionList[positionIndex]->setX(_positionList[positionIndex]->getX() - _playerList[playerIndex]->getSpeed() * 5);
    if (rand == 1)
        if (testCollision(_positionList[positionIndex], _playerList[playerIndex]->getSpeed(), 0))
            _positionList[positionIndex]->setX(_positionList[positionIndex]->getX() + _playerList[playerIndex]->getSpeed() * 5);
    if (rand == 2)
        if (testCollision(_positionList[positionIndex], 0, _playerList[playerIndex]->getSpeed() * (-1)))
            _positionList[positionIndex]->setY(_positionList[positionIndex]->getY() - _playerList[playerIndex]->getSpeed() * 5);
    if (rand == 3)
        if (testCollision(_positionList[positionIndex], 0, _playerList[playerIndex]->getSpeed()))
            _positionList[positionIndex]->setY(_positionList[positionIndex]->getY() + _playerList[playerIndex]->getSpeed() * 5);
    if (rand == 4)
        spawnBomb(_playerList[playerIndex]->getPlayerID());
}

void Game::spawnBomb(int nbPlayer)
{
    for (std::size_t i = 0, j = 0, k = 0; i < _playerList.size(); i++)
    {
        if (_playerList[i]->getPlayerID() == nbPlayer && _playerList[i]->getIsAlive())
        {
            for (j = 0; _playerList[i]->getLink() != _positionList[j]->getLink(); j++)
            {
            }
            for (std::size_t p = 0; p < _positionList.size(); p++)
                if (round(_positionList[j]->getX()) == _positionList[p]->getX() &&
                    round(_positionList[j]->getY()) == _positionList[p]->getY() &&
                    round(_positionList[j]->getZ()) == _positionList[p]->getZ() && j != p)
                    return;
            int nbBomb = 0;                                                     //
            for (std::size_t k = 0; k < _bombList.size(); k++)                  //
                if (_bombList[k]->getPlayerLink() == _playerList[i]->getLink()) // Verify that a bomb already exist
                    nbBomb++;                                                   // = only one bomb per player for
            if (nbBomb < _playerList[i]->getNbBomb())
            { // the moment
                Entity *bomb = new Entity;
                Position *pos = new Position(round(_positionList[j]->getX()), round(_positionList[j]->getY()), round(_positionList[j]->getZ()));
                pos->link(bomb->getId());
                _positionList.push_back(pos);
                Bomb *b = new Bomb(_playerList[i]->getFlameSize());
                b->link(bomb->getId());
                b->linkPlayer(_playerList[i]->getLink());
                _bombList.push_back(b);
                for (k = 0; _playerList[i]->getLink() != _jumpList[k]->getLink(); k++)
                {
                }
                _jumpList[k]->setJump(true);
                _jumpList[k]->setFrameCount(0);
            }
        }
    }
}

void Game::usePower()
{
    for (std::size_t i = 0; i < _playerList.size(); i++)
        for (std::size_t j = 0; j < _positionList.size(); j++)
            if (_playerList[i]->getLink() == _positionList[j]->getLink())
                for (std::size_t n = 0; n < _powerUpList.size(); n++)
                    for (std::size_t k = 0; k < _positionList.size(); k++)
                        if (_powerUpList[n]->getLink() == _positionList[k]->getLink())
                            if (_positionList[k]->getX() == round(_positionList[j]->getX()) && _positionList[k]->getY() == round(_positionList[j]->getY()))
                            {
                                _powerUpList[n]->usePower(_playerList[i]);
                                _powerUp.Play();
                                deleteEntity(_powerUpList[n]->getLink());
                            }
}

bool Game::testCollision(Position *pos, float x, float y) // UP = 1 | LEFT = 2 | DOWN = 3 | RIGHT = 4
{
    bool collision = true;
    Player *player = nullptr;

    for (std::size_t i = 0; i < _playerList.size(); i++)
        if (pos->getLink() == _playerList[i]->getLink())
            player = _playerList[i];

    for (std::size_t p = 0, e = 0; p < _solidList.size(); p++)
    {
        for (e = 0; _solidList[p]->getLink() != _positionList[e]->getLink(); e++)
            ;
        if (CheckCollisionBoxes(
                {{static_cast<float>(pos->getX() - 6 - 0.5 / 2 + x),
                  static_cast<float>(pos->getZ() - 1 / 2),
                  static_cast<float>(pos->getY() - 9 - 0.5 / 2 + y)},
                 {static_cast<float>(pos->getX() - 6 + 0.5 / 2 + x),
                  static_cast<float>(pos->getZ() + 1 / 2),
                  static_cast<float>(pos->getY() - 9 + 0.5 / 2 + y)}},
                {{static_cast<float>(_positionList[e]->getX() - 6 - 0.5),
                  static_cast<float>(_positionList[e]->getZ() - 0.5),
                  static_cast<float>(_positionList[e]->getY() - 9 - 0.5)},
                 {static_cast<float>(_positionList[e]->getX() - 6 + 0.5),
                  static_cast<float>(_positionList[e]->getZ() + 0.5),
                  static_cast<float>(_positionList[e]->getY() - 9 + 0.5)}}))
        {
            if (player->getWallPass() == true)
                if (_solidList[p]->getPassable() == false)
                    collision = false;
            if (player->getWallPass() == false)
                collision = false;
            break;
        }
    }
    return collision;
}

void Game::deleteEntity(int id)
{
    int i;

    for (i = 0; i < _positionList.size(); i++)
        if (_positionList[i]->getLink() == id)
            _positionList.erase(_positionList.begin() + i);
    for (i = 0; i < _breakableList.size(); i++)
        if (_breakableList[i]->getLink() == id)
            _breakableList.erase(_breakableList.begin() + i);
    for (i = 0; i < _texture2DList.size(); i++)
        if (_texture2DList[i]->getLink() == id)
            _texture2DList.erase(_texture2DList.begin() + i);
    for (i = 0; i < _playerList.size(); i++)
        if (_playerList[i]->getLink() == id)
            _playerList.erase(_playerList.begin() + i);
    for (i = 0; i < _model3DList.size(); i++)
        if (_model3DList[i]->getLink() == id)
            _model3DList.erase(_model3DList.begin() + i);
    for (i = 0; i < _jumpList.size(); i++)
        if (_jumpList[i]->getLink() == id)
            _jumpList.erase(_jumpList.begin() + i);
    for (i = 0; i < _bombList.size(); i++)
        if (_bombList[i]->getLink() == id)
            _bombList.erase(_bombList.begin() + i);
    for (i = 0; i < _solidList.size(); i++)
        if (_solidList[i]->getLink() == id)
            _solidList.erase(_solidList.begin() + i);
    for (i = 0; i < _flameList.size(); i++)
        if (_flameList[i]->getLink() == id)
            _flameList.erase(_flameList.begin() + i);
    for (i = 0; i < _powerUpList.size(); i++)
        if (_powerUpList[i]->getLink() == id)
            _powerUpList.erase(_powerUpList.begin() + i);
}

void Game::saveMap()
{
    int id;
    std::vector<std::string> map;

    for (int i = 0; i < _map.size(); i++)
        map.push_back("               ");

    for (int i = 0; i < _positionList.size(); i++)
    {
        id = _positionList[i]->getLink();
        int x = round(_positionList[i]->getX());
        int y = round(_positionList[i]->getY());

        for (int j = 0; j < _solidList.size(); j++)
            if (id == _solidList[j]->getLink())
                map[x][y] = 'X';

        for (int j = 0; j < _breakableList.size(); j++)
            if (id == _breakableList[j]->getLink())
                map[x][y] = '#';

        for (int j = 0; j < _playerList.size(); j++)
            if (id == _playerList[j]->getLink() && _playerList[j]->getIsAlive())
            {
                if (_playerList[j]->getPlayerID() == 0)
                    map[x][y] = '0';
                if (_playerList[j]->getPlayerID() == 1)
                    map[x][y] = '1';
                if (_playerList[j]->getPlayerID() >= 2)
                    map[x][y] = '@';
            }

        for (int j = 0; j < _bombList.size(); j++)
            if (id == _bombList[j]->getLink())
                if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] != '@')
                    map[x][y] = 'o';
    }

    _saveMap = map;
}

bool Game::testWin() const
{
    int nbPl = 0;

    for (std::size_t i = 0; i < _playerList.size(); i++)
        if (_playerList[i]->getIsAlive())
            nbPl++;
    if (nbPl == 1)
        return true;
    return false;
}
