#include "MazeGame.h"
#include "IceMazeFactory.h"
#include "FireMazeFactory.h"

int main() {

    MazeGame iceMaze;
    IceMazeFactory iceFactory;
    iceMaze.CreateMaze(iceFactory);

    MazeGame fireMaze;
    FireMazeFactory fireFactory;
    fireMaze.CreateMaze(fireFactory);
    
    return 0;
}