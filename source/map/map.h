#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>

namespace olc {
    class PixelGameEngine;
}

class Map{
public:
    Map( const std::string& filename );
    int getCell( int x, int y ) const;
    void mapLoader( const std::string& filename );
    void draw( olc::PixelGameEngine* pge, float tileWidth, float tileHeight );

private:
    std::vector<std::vector<int>> grid;
    int mapWidth;
    int mapHeight;
};

#endif