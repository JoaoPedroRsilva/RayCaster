#ifndef RAY_H
#define RAY_H
#include "Map.h"

class Ray{
private:
    Map* map;

public:
    Ray( Map* map );
    void wallCheck( float playerX, float playerY, float angle, float tileWidth, float tileHeight );
};


#endif