#include "map.h"
#include <fstream> 
#include <iostream>

Map::Map( const std::string& filename ){
    mapLoader( filename );
}

Map::mapLoader( const std::string& filename ){
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

int Map::getCell( int y, int x ) const {
    if(  x < 0 || y < 0 || y >= mapHeight || x >= mapWidth )  return -1;
    
    return grid[y][x];
}


