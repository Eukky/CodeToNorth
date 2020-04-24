#include "MazeFactory.h"

class MazeGame {
    public:
        MazeGame();

        Maze* CreateMaze(MazeFactory& factory) {
            Maze* aMaze = factory.MakeMaze();
            Room* r1 = factory.MakeRoom(1);
            Room* r2 = factory.MakeRoom(2);
            Door* d1 = factory.MakeDoor(r1, r2);

            aMaze->AddRoom(r1);
            aMaze->AddRoom(r2);

            r1->SetSide(Direction::North, factory.Makewall());
            r1->SetSide(Direction::East, d1);
            r1->SetSide(Direction::Sorth, factory.Makewall());
            r1->SetSide(Direction::West, factory.Makewall());

            r2->SetSide(Direction::North, factory.Makewall());
            r2->SetSide(Direction::East, factory.Makewall());
            r2->SetSide(Direction::Sorth, factory.Makewall());
            r2->SetSide(Direction::West, d1);
                
            return aMaze;
        }
};