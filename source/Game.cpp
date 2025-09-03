#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"

Game::Game() : 
stage("assets/Map.txt"), 
myPlayer( 100.0f, 100.0f, &stage ) {
    sAppName = "RayCaster";
}

bool Game::OnUserCreate(){
    return true;
}

bool Game::OnUserUpdate( float fElapsedTime ){
    Clear( olc::DARK_BLUE );
    stage.draw( this );
    myPlayer.handleMovement( fElapsedTime, this, TILE_WIDTH, TILE_HEIGHT );

    FillCircle( myPlayer.getPositionX(), myPlayer.getPositionY(), 7, olc::RED );

    
    return true;
}


int main(int argc, char* argv[])
{
    Game game;
    if (game.Construct(640, 480, 4, 4))
        game.Start();
    return 0;
}
