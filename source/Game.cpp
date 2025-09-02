#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"

Game::Game() : stage("assets/Map.txt"), dummy( 10, 10 ) {
    sAppName = "RayCaster";
}

bool Game::OnUserCreate(){
    return true;
}

bool Game::OnUserUpdate( float fElapsedTime ){
    Clear( olc::DARK_BLUE );
    stage.draw( this );
    if (GetKey(olc::Key::W).bHeld) {

    }

    if (GetKey(olc::Key::S).bHeld) {
    }

    if (GetKey(olc::Key::A).bHeld) {
        
    }
    
    if (GetKey(olc::Key::D).bHeld) {
    }
    return true;
}

int main(int argc, char* argv[])
{
    Game game;
    if (game.Construct(640, 480, 4, 4))
        game.Start();
    return 0;
}
