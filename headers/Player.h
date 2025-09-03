#ifndef PLAYER_H
#define PLAYER_H

namespace olc {
    class PixelGameEngine;
}

class Player{
private:
    float positionX;
    float positionY;
    float angle;

public:
    Player( float positionX, float positionY );
    void handleMovement( float fElapsedTime, olc::PixelGameEngine* pge );
    float getPositionX() const;
    float getPositionY() const;
};

#endif