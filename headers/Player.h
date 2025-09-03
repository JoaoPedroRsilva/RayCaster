#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"

namespace olc {
    class PixelGameEngine;
}

class Player{
private:
    float positionX;
    float positionY;
    float angle;
    Map* map;


public:
    Player( float positionX, float positionY, Map* map );
    void handleMovement( float fElapsedTime, olc::PixelGameEngine* pge, float tileWidth, float tileHeight );
    float getPositionX() const;
    float getPositionY() const;
};

#endif