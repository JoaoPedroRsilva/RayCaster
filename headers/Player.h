#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include "Ray.h"

namespace olc {
    class PixelGameEngine;
}

class Player{
private:
    float positionX;
    float positionY;
    float angle;
    Ray ray;
    Map* map;


public:
    Player( float positionX, float positionY, Map* map );
    void handleMovement( float fElapsedTime, olc::PixelGameEngine* pge, float tileWidth, float tileHeight );
    float getPositionX() const;
    float getPositionY() const;
    float getAngle() const;
    wallCheck castRay( float tileWidth, float tileHeight );
};

#endif