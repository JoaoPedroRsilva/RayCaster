#include "olcPixelGameEngine.h"
#define OLC_PGE_APPLICATION
#include "Game.h"
#include "Map.h"


Game::Game() : stage("Map.txt") {
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

