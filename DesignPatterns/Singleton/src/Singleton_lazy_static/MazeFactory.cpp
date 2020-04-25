#include "MazeFactory.h"

MazeFactory* MazeFactory::Instance() {
    static MazeFactory* instance;
    return instance;
}