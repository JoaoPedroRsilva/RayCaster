#include "cmath"
#include "Player.h"
#include "olcPixelGameEngine.h"
#define PI 3,1415926535

Player::Player( float positionX, float positionY, Map* map ): ray( map ){
    this->positionX = positionX;
    this->positionY = positionY;
    this->angle = 0.0f;
    this->map = map;
}

void Player::handleMovement( float fElapsedTime, olc::PixelGameEngine* pge, float tileWidth, float tileHeight ){
    float distance = 60;
    float movingDistanceX = 0.0f;
    float movingDistanceY = 0.0f;

    if (pge->GetKey(olc::Key::W).bHeld) {
        movingDistanceX += ( distance * cos( angle ) ) * fElapsedTime;
        movingDistanceY += ( distance * sin( angle ) ) * fElapsedTime;
    }

    if( ( map->getCell( ( int )(( positionX + movingDistanceX ) / tileWidth), ( int )( ( positionY + movingDistanceY ) / tileHeight ) ) ) != 1 ){
        positionX += movingDistanceX;
        positionY += movingDistanceY;
    }
    /*
    if (pge->GetKey(olc::Key::S).bHeld) {
        positionX -= ( distance * cos( angle ) ) * fElapsedTime;
        positionY -= ( distance * sin( angle ) ) * fElapsedTime;
    }
    */
    if (pge->GetKey(olc::Key::A).bHeld) {
        angle -= 1.5f * fElapsedTime;
    }
    
    if (pge->GetKey(olc::Key::D).bHeld) {
        angle += 1.5f * fElapsedTime;
    }
}

float Player::getPositionX() const{
    return positionX;
}

float Player::getPositionY() const{
    return positionY;
}

float Player::getAngle() const{
    return angle;
}

wallCheck Player::castRay( float tileWidth, float tileHeight, float loopAngle ){
    return ray.rayCollisionCheck( positionX, positionY, loopAngle, tileWidth, tileHeight );
}