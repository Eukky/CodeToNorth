#include "MazeFactory.h"
int main() {
    MazeFactory* mf = MazeFactory::Instance(MazeCategory::FIRE);
    return 0;
}