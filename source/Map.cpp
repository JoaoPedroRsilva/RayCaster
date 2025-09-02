#include "Map.h"
#include <fstream> 
#include <iostream>
#include "olcPixelGameEngine.h"

Map::Map( const std::string& filename ){
    mapLoader( filename );
}

void Map::mapLoader( const std::string& filename ){
    std::ifstream file( filename );

    if( !file.is_open() ){
        std::cerr << "Error: could not open the map file." << filename << std::endl;

        mapHeight = 0;
        mapWidth = 0;
        
        return;
    }

    file >> mapHeight;
    file >> mapWidth;
    grid.resize( mapHeight, std::vector<int>( mapWidth ) );

    for( int i = 0; i < mapHeight; i++ ){
        for( int j = 0; j < mapWidth; j++ ){
            file >> grid[i][j];
        }
    }
}

void Map::draw( olc::PixelGameEngine* pge ){
    for( int y = 0; y < mapHeight; y++ ){
        for( int x = 0; x < mapWidth; x++ ){
            if( grid[y][x] == 1 ){
                pge->FillRect(x * 64, y * 60, 64, 60, olc::GREY );
            }
        }
    }
}

int Map::getCell( int y, int x ) const {
    if(  x < 0 || y < 0 || y >= mapHeight || x >= mapWidth )  return -1;
    
    return grid[y][x];
}


