#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"

Game::Game() : 
stage("../assets/Map.txt"), 
myPlayer( 100.0f, 100.0f, &stage ), 
TILE_WIDTH(64.0f),
TILE_HEIGHT(60.0f)
{
    sAppName = "RayCaster";

}

bool Game::OnUserCreate(){
    return true;
}

bool Game::OnUserUpdate( float fElapsedTime ){
    Clear( olc::DARK_BLUE );
    stage.draw( this, TILE_WIDTH, TILE_HEIGHT );
    myPlayer.handleMovement( fElapsedTime, this, TILE_WIDTH, TILE_HEIGHT );
    // DEBUG POSITION
    std::string debug = "X: " + std::to_string((int)myPlayer.getPositionX()) + 
                       " Y: " + std::to_string((int)myPlayer.getPositionY());
    DrawString(10, 10, debug, olc::WHITE);


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
