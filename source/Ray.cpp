#include "cmath"
#include "Ray.h"

Ray::Ray( Map* map ){
    this->map = map;
}

wallCheck Ray::rayCollisionCheck( float playerX, float playerY, float angle, float tileWidth, float tileHeight ){
    float cosAngle = cos( angle );
    float sinAngle = sin( angle );
    wallCheck rayStart;
    rayStart.x = playerX;
    rayStart.y = playerY;
    wallCheck DistanceToGrid;
    DistanceToGrid.x = 0;
    DistanceToGrid.y = 0;
    float hipX = 0;
    float hipY = 0;

    while( map->getCell( ( int )( rayStart.x / tileWidth ), ( int )( rayStart.y / tileHeight ) ) != 1 ){
        if( cosAngle > 0 ){
            DistanceToGrid.x = tileWidth - ( fmodf( rayStart.x, tileWidth ) );
        } else if( cosAngle < 0 ){
            DistanceToGrid.x = fmodf( rayStart.x, tileWidth );
        } else if( cosAngle == 0  && sinAngle > 0 ){
            rayStart.y += tileHeight - ( fmodf( rayStart.y, tileHeight ) );
            continue;
        } else {
            rayStart.y -= fmodf( rayStart.y, tileHeight );
            continue;
        }
        if( sinAngle > 0 ){
            DistanceToGrid.y = tileHeight - ( fmodf( rayStart.y, tileHeight ) );
        } else if( sinAngle < 0 ){
            DistanceToGrid.y = fmodf( rayStart.y, tileHeight );
        } else if( sinAngle == 0 && cosAngle > 0 ){
            rayStart.x += tileWidth - ( fmodf( rayStart.x, tileWidth ) );
            continue;
        } else {
            rayStart.x -= fmodf( rayStart.x, tileWidth );
            continue;
        }

        hipX = fabs( DistanceToGrid.x / cosAngle );
        hipY = fabs( DistanceToGrid.y / sinAngle );
        if( hipX < hipY ){ 
            rayStart.x += hipX * cosAngle;
            rayStart.y += hipX * sinAngle;
        } else {
            rayStart.y += hipY * sinAngle;
            rayStart.x += hipY * cosAngle;
        }
    }

    return rayStart;
}


