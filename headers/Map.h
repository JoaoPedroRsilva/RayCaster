#include <vector>
#include <string>

class Map{
    public:

    Map( const std::string& filename );

    int getCell( int y, int x ) const;

    private:

    std::vector<std::vector<int>> grid;
    int mapWidth;
    int mapHeight;
    

    void mapLoader( const std::string& filename );

}