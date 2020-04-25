#include "MazeFactory.h"

MazeFactory* MazeFactory::_instance = new MazeFactory();

MazeFactory* MazeFactory::Instance() {
    return _instance;
}

void MazeFactory::DeleteInstance() {
    if(_instance != 0) {
        delete _instance;
        _instance = 0;
    }
}