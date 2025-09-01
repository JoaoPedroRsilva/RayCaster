#include "olcPixelGameEngine.h"
#include "Map.h"

class Game : public olc::PixelGameEngine {
private:
    Map stage;

public:
    Game(); 

    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};

