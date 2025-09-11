#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Player.h"

class Game : public olc::PixelGameEngine {
private:
    Map stage;
    Player myPlayer;
    const float TILE_WIDTH;
    const float TILE_HEIGHT;
    const float FOV;
    bool visionSwitch;
public:
    Game(); 

    bool OnUserCreate();
    bool OnUserUpdate( float fElapsedTime );
};

#endif 