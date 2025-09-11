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
TILE_HEIGHT( 60.0f ),
FOV( 1.570796f ),
visionSwitch( false )
{
    sAppName = "RayCaster";
}

bool Game::OnUserCreate(){
    float numberOfRays = FOV / 0.001f;
    return true;
}

bool Game::OnUserUpdate( float fElapsedTime ){
    Clear( olc::DARK_BLUE );
    
    myPlayer.handleMovement( fElapsedTime, this, TILE_WIDTH, TILE_HEIGHT );
    wallCheck collision;
   
    if( visionSwitch == false ){
        // 3D Vision
        for( int x = 0; x < ScreenWidth(); x++ ){
            float rayAngle = myPlayer.getAngle() - ( FOV / 2 ) + ( float )x / ( float )ScreenWidth() * FOV;
            collision = myPlayer.castRay( TILE_WIDTH, TILE_HEIGHT, rayAngle );
            float distanceCorrected = collision.rayDistance * cos( rayAngle - myPlayer.getAngle() );

            float lineHeight = ScreenHeight() / distanceCorrected * TILE_WIDTH;
            float yFloor = ( ScreenHeight() / 2 ) - ( lineHeight / 2 );
            float yCeiling = ScreenHeight() - yFloor;
            
            DrawLine( x, yFloor, x, yCeiling, olc::VERY_DARK_CYAN );

        }
    } else {
        // 2D Vision
        stage.draw( this, TILE_WIDTH, TILE_HEIGHT );
        for( float loopAngle = myPlayer.getAngle() - 0.7854; loopAngle < myPlayer.getAngle() + 0.7854; loopAngle += 0.001f ){
            collision = myPlayer.castRay( TILE_WIDTH, TILE_HEIGHT, loopAngle );
            DrawLine( myPlayer.getPositionX(), myPlayer.getPositionY(), collision.x, collision.y, olc::YELLOW );
        }
        FillCircle( myPlayer.getPositionX(), myPlayer.getPositionY(), 7, olc::YELLOW );
        // DEBUG 
        std::string debug = "X: " + std::to_string( ( int )myPlayer.getPositionX() ) + 
                        " Y: " + std::to_string( ( int )myPlayer.getPositionY() );
        DrawString(10, 10, debug, olc::WHITE);
        std::string collisionInfo = "Hit: (" + std::to_string((int)collision.x) + ", " + std::to_string((int)collision.y) + ")";
        DrawString(10, 50, collisionInfo, olc::WHITE);
        std::string cosInfo = "cos: " + std::to_string( cos(myPlayer.getAngle()) );
        DrawString(10, 30, cosInfo, olc::WHITE);
        std::string sinInfo = "sin: " + std::to_string( sin(myPlayer.getAngle()) );
        DrawString(10, 40, sinInfo, olc::WHITE);
    }
    std::string switchVision = "Press P to switch vision";
    DrawString( 400, 50, switchVision, olc::WHITE );
    if( GetKey(olc::Key::P).bPressed ){
        visionSwitch = !visionSwitch;
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
