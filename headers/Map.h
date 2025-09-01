#include <vector>
#include <string>

namespace olc {
    class PixelGameEngine;
}

class Map{
    public:

    Map( const std::string& filename );
    int getCell( int y, int x ) const;
    void mapLoader( const std::string& filename );
    void draw(olc::PixelGameEngine* pge );

    private:

    std::vector<std::vector<int>> grid;
    int mapWidth;
    int mapHeight;
};