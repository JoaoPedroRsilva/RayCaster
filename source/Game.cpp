#include "olcPixelGameEngine.h"
#define OLC_PGE_APPLICATION
#include "Game.h"


Game::Game(){
    appName = "RayCaster";
}

bool Game::OnUserCreate() override{
    stage = Map("Map.txt");
    return true;
}

bool Game::OnUserUpdate( float fElapsedTime ) override{
    
    Clear( olc::DARK_BLUE );
    stage.Draw( this );
    return true;
}

