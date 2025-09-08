#ifndef RAY_H
#define RAY_H
#include "Map.h"

typedef struct{
    float x;
    float y;
}wallCheck;

class Ray{
private:
    Map* map;

public:
    Ray( Map* map );
    wallCheck rayCollisionCheck( float playerX, float playerY, float angle, float tileWidth, float tileHeight );
};


#endif