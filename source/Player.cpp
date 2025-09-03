#include "cmath"
#include "Player.h"
#include "olcPixelGameEngine.h"
#define PI 3,1415926535

Player::Player( float positionX, float positionY ){
    this->positionX = positionX;
    this->positionY = positionY;
    this->angle = 0.0f;
}

void Player::handleMovement( float fElapsedTime, olc::PixelGameEngine* pge ){
    float distance = 25;

    if (pge->GetKey(olc::Key::W).bHeld) {
        positionX += ( distance * cos( angle ) ) * fElapsedTime;
        positionY += ( distance * sin( angle ) ) * fElapsedTime;
    }

    if (pge->GetKey(olc::Key::S).bHeld) {
        positionX -= ( distance * cos( angle ) ) * fElapsedTime;
        positionY -= ( distance * sin( angle ) ) * fElapsedTime;
    }

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