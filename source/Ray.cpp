#include "cmath"
#include "Ray.h"

Ray::Ray( Map* map ){
    this->map = map;
}

wallCheck Ray::rayCollisionCheck( float playerX, float playerY, float angle, float tileWidth, float tileHeight ){
    float cosAngle = cos( angle );
    float sinAngle = sin( angle );
    float firstDistanceToGridX = 0;
    float firstDistanceToGridY = 0;

    if( cosAngle > 0 ){
        firstDistanceToGridX = tileWidth - ( fmodf( playerX, tileWidth ) );
    }else{
        firstDistanceToGridX = fmodf( playerX, tileWidth );
    }

    if( sinAngle > 0 ){
       firstDistanceToGridY = tileHeight - ( fmodf( playerY, tileHeight ) );
    }else{
        firstDistanceToGridY = fmodf( playerY, tileHeight );
    }
    
    typedef struct{
        float x;
        float y;
    }firstCoordinate;

    firstCoordinate horizontal;
    firstCoordinate vertical;
    float firstHipVert = 0;
    float firstHipHoriz = 0;

    firstHipVert = firstDistanceToGridX / cosAngle;
    horizontal.x = fabs( firstHipVert ) * cosAngle;
    horizontal.y = fabs( firstHipVert ) * sinAngle;

    firstHipHoriz = firstDistanceToGridY / sinAngle;
    vertical.x = fabs( firstHipHoriz ) * cosAngle;
    vertical.y = fabs( firstHipHoriz ) * sinAngle;

    wallCheck currentRayPosHorizontal;
    wallCheck currentRayPosVertical;
    wallCheck wallHit;

    currentRayPosHorizontal.x = playerX + horizontal.x;
    currentRayPosHorizontal.y = playerY + horizontal.y;
    
    currentRayPosVertical.x = playerX + vertical.x;
    currentRayPosVertical.y = playerY + vertical.y;

    int tileIncrementIndex = 1;

    float hipX = tileWidth / cosAngle;
    float hipY = tileHeight / sinAngle;

    if( firstDistanceToGridX < firstDistanceToGridY ){
        if( map->getCell( ( int )( currentRayPosHorizontal.x / tileWidth ),( int )( currentRayPosHorizontal.y / tileHeight ) ) == 1 ){
            return currentRayPosHorizontal;
        }else if( map->getCell( ( int )( currentRayPosVertical.x / tileWidth ), ( int )( currentRayPosVertical.y/ tileHeight ) ) == 1 ){
            return currentRayPosVertical;
        }
        while( true ){
            wallHit.x = currentRayPosHorizontal.x + ( fabs( hipX ) * tileIncrementIndex ) * cosAngle;
            wallHit.y = currentRayPosHorizontal.y + ( fabs( hipX ) * tileIncrementIndex ) * sinAngle;
            if( map->getCell( ( int )( wallHit.x / tileWidth ), ( int )( wallHit.y / tileHeight ) ) == 1 ) break;
            wallHit.x = currentRayPosVertical.x + ( fabs( hipY ) * tileIncrementIndex ) * cosAngle;
            wallHit.y = currentRayPosVertical.y + ( fabs( hipY ) * tileIncrementIndex ) * sinAngle;
            if( map->getCell( ( int )( wallHit.x / tileWidth ), ( int )( wallHit.y / tileHeight ) ) == 1 ) break;
            tileIncrementIndex++;
        }
    }else{
        if( map->getCell( ( int )( currentRayPosVertical.x / tileWidth ), ( int )( currentRayPosVertical.y/ tileHeight ) ) == 1 ){
            return currentRayPosVertical;
        }else if( map->getCell( ( int )( currentRayPosHorizontal.x / tileWidth ),( int )( currentRayPosHorizontal.y / tileHeight ) ) == 1 ){
            return currentRayPosHorizontal;
        }
        while( true ){
            wallHit.x = currentRayPosVertical.x + ( fabs( hipY ) * tileIncrementIndex ) * cosAngle;
            wallHit.y = currentRayPosVertical.y + ( fabs( hipY ) * tileIncrementIndex ) * sinAngle;
            if( map->getCell( ( int )( wallHit.x / tileWidth ), ( int )( wallHit.y / tileHeight ) ) == 1 ) break;
            wallHit.x = currentRayPosHorizontal.x + ( fabs( hipX ) * tileIncrementIndex ) * cosAngle;
            wallHit.y = currentRayPosHorizontal.y + ( fabs( hipX ) * tileIncrementIndex ) * sinAngle;
            if( map->getCell( ( int )( wallHit.x / tileWidth ), ( int )( wallHit.y / tileHeight ) ) == 1 ) break;
            tileIncrementIndex++;
        }
    }

    return wallHit;
}


