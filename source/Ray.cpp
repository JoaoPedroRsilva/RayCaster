#include "cmath"
#include "Ray.h"
#include <limits>

Ray::Ray( Map* map ){
    this->map = map;
}

wallCheck Ray::rayCollisionCheck( float playerX, float playerY, float angle, float tileWidth, float tileHeight ){
    float cosAngle = cos( angle );
    float sinAngle = sin( angle );

    int mapX = ( int )(playerX / tileWidth);
    int mapY = ( int )(playerY / tileHeight);

    wallCheck hipTile;
    hipTile.x = ( cosAngle == 0 ) ? std::numeric_limits<float>::max() : fabs( tileWidth / cosAngle );
    hipTile.y = ( sinAngle == 0 ) ? std::numeric_limits<float>::max() : fabs( tileHeight / sinAngle );

    float DistanceToGridX;
    float DistanceToGridY;

    float stepX;
    float stepY;

    if( cosAngle > 0 ){
        stepX = 1;
        DistanceToGridX = ( ( ( mapX + 1.0f ) * tileWidth ) - playerX ) * fabs( 1 / cosAngle );
    } else {
        stepX = -1;
        DistanceToGridX = fmodf( playerX, tileWidth ) * fabs( 1 / cosAngle );
    }

    if( sinAngle > 0 ){
        stepY = 1;
        DistanceToGridY = ( ( ( mapY + 1.0f ) * tileHeight ) - playerY ) * fabs( 1 / sinAngle );
    } else {
        stepY = -1;
        DistanceToGridY = fmodf( playerY, tileHeight ) * fabs( 1 / sinAngle );    
    }

    bool wallhit = false;
    int side;
    while( !wallhit ){
        if( DistanceToGridX < DistanceToGridY ){
            mapX += stepX;
            DistanceToGridX += hipTile.x; 
            side = 0;
        } else {
            mapY += stepY;
            DistanceToGridY += hipTile.y;
            side = 1;
        }

        if( map->getCell( mapX, mapY ) == 1 ){
            wallhit = true;
        }
    }

    float finalRayDistance;
    if( side == 0){
        finalRayDistance = DistanceToGridX - hipTile.x;
    } else {
        finalRayDistance = DistanceToGridY - hipTile.y;
    }
    wallCheck collision;
    collision.x = playerX + cosAngle * finalRayDistance;
    collision.y = playerY + sinAngle * finalRayDistance;
    collision.rayDistance = finalRayDistance;
    
    return collision;
}


