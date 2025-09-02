#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Player.h"

class Game : public olc::PixelGameEngine {
private:
    Map stage;
    Player dummy;
public:
    Game(); 

    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};

#endif 