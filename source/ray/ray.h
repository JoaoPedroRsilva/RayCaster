#ifndef RAY_H
#define RAY_H
#include "../map/map.h"

typedef struct{
    float x;
    float y;
    float rayDistance;
}wallCheck;

class Ray{
private:
    Map* map;

public:
    Ray( Map* map );
    wallCheck rayCollisionCheck( float playerX, float playerY, float angle, float tileWidth, float tileHeight );
};


#endif