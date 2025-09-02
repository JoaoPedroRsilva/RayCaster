#ifndef PLAYER_H
#define PLAYER_H

class Player{
private:
    float positionX;
    float positionY;
    float angle;

public:
    Player( float positionX, float positionY );
    void move( float moving );
    void turn( float turning );
};

#endif