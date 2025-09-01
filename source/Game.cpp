#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Game.h"
#include "Map.h"

Game::Game() : stage("assets/Map.txt") {
    sAppName = "RayCaster";
}

bool Game::OnUserCreate(){
    return true;
}

bool Game::OnUserUpdate( float fElapsedTime ){
    Clear( olc::DARK_BLUE );
    stage.draw( this );
    return true;
}

int main(int argc, char* argv[])
{
    Game game;
    if (game.Construct(640, 480, 4, 4))
        game.Start();
    return 0;
}
