#include "cmath"
#include "Ray.h"

void Ray::wallCheck( float playerX, float playerY, float angle, float tileWidth, float tileHeight ){
    float cosAngle = cos( angle );
    float sinAngle = sin( angle );
    float firstDistanceToGridX = 0;
    float firstDistanceToGridY = 0;

    if( cosAngle > 0 ){
        firstDistanceToGridX = tileWidth - ( playerX % tileWidth );
    }else{
        firstDistanceToGridX = playerX % tileWidth;
    }

    if( sinAngle > 0 ){
       firstDistanceToGridY = tileHeight - ( playerY % tileHeight );
    }else{
        firstDistanceToGridY = playerY % tileHeight;
    }
    
    typedef struct{
        float x;
        float y;
    }firstCoordinate;

    firstCoordinate horizontal;
    firstCoordinate vertical;
    float hip = 0;

    hip = firstDistanceToGridX / cosAngle;
    horizontal.x = fabs( hip ) * cosAngle;
    horizontal.y = fabs( hip ) * sinAngle;

    hip = firstDistanceToGridY / sinAngle;
    vertical.x = fabs( hip ) * cosAngle;
    vertical.y = fabs( hip ) * sinAngle;

    if( firstDistanceToGridX < firstDistanceToGridY ){
        // CHECK IF HORIZONTAL IS WALL
        // CHECK IF VERTICAL IS WALL
    }else{
        // CHECK IF VERTICAL IS WALL
        // CHECK IF HORIZONTAL IS WALL
    }

}