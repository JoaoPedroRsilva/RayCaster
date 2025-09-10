#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Ray.h"

Game::Game() : 
stage("../assets/Map.txt"), 
myPlayer( 100.0f, 100.0f, &stage ), 
TILE_WIDTH( 64.0f ),
TILE_HEIGHT( 60.0f )
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
    wallCheck collision;
    for( float loopAngle = myPlayer.getAngle() - 0.7854; loopAngle < myPlayer.getAngle() + 0.7854; loopAngle += 0.01f ){
        collision = myPlayer.castRay( TILE_WIDTH, TILE_HEIGHT, loopAngle );
        DrawLine( myPlayer.getPositionX(), myPlayer.getPositionY(), collision.x, collision.y, olc::YELLOW );
    }


    // DEBUG 
    std::string playerAngle = "Angle: " + std::to_string( myPlayer.getAngle() );
    DrawString( 10, 20, playerAngle, olc::WHITE ); 

    std::string debug = "X: " + std::to_string( ( int )myPlayer.getPositionX() ) + 
                       " Y: " + std::to_string( ( int )myPlayer.getPositionY() );
    DrawString(10, 10, debug, olc::WHITE);

    std::string collisionInfo = "Hit: (" + std::to_string((int)collision.x) + ", " + std::to_string((int)collision.y) + ")";
    DrawString(10, 50, collisionInfo, olc::WHITE);

    std::string cosInfo = "cos: " + std::to_string( cos(myPlayer.getAngle()) );
    DrawString(10, 30, cosInfo, olc::WHITE);
    std::string sinInfo = "sin: " + std::to_string( sin(myPlayer.getAngle()) );
    DrawString(10, 40, sinInfo, olc::WHITE);



    FillCircle( myPlayer.getPositionX(), myPlayer.getPositionY(), 7, olc::YELLOW );

    return true;
}


int main(int argc, char* argv[])
{
    Game game;
    if (game.Construct(640, 480, 4, 4))
        game.Start();
    return 0;
}
