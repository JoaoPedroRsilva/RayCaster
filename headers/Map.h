#include <vector>
#include <string>

class Map{
    public:

    Map( const std::string& filename );

    int getCell( int x, int y ) const;

    private:

    std::vector<std::vector<int>> mapStorage;

    void mapLoader( const std::string& filename );

}