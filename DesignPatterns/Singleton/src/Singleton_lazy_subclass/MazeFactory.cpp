#include "MazeFactory.h"
#include "FireMazeFactory.h"
#include "IceMazeFactory.h"
MazeFactory* MazeFactory::_instance = 0;

MazeFactory* MazeFactory::Instance() {
    if(_instance == 0) {
        _instance = new MazeFactory();
    }
    return _instance;
}

MazeFactory* MazeFactory::Instance(MazeCategory mazeCategory) {
    if(_instance == 0) {
        if(mazeCategory == MazeCategory::FIRE) {
            _instance = new FireMazeFactory();
        } else if(mazeCategory == MazeCategory::ICE) {
            _instance = new IceMazeFactory();
        } else {
            _instance = new MazeFactory();
        }
    }
    return _instance;
}

void MazeFactory::DeleteInstance() {
    if(_instance != 0) {
        delete _instance;
        _instance = 0;
    }
}