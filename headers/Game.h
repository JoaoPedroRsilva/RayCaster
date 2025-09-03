#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Player.h"

class Game : public olc::PixelGameEngine {
private:
    Map stage;
    Player myPlayer;
    const float TILE_WIDTH = 64.0f;
    const float TILE_HEIGHT = 60.0f;
public:
    Game(); 

    bool OnUserCreate();
    bool OnUserUpdate( float fElapsedTime );
};

#endif 