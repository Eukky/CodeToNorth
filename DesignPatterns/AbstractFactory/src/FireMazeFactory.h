#include "MazeFactory.h"
#include "FireRoom.h"
#include "FireDoor.h"
class FireMazeFactory : public MazeFactory {
    public:
        FireMazeFactory();

        virtual Room* MakeRoom(int n) const {
            return new FireRoom(n, Power::FirePower);
        }

        virtual Door* MakeDoor(Room* r1, Room* r2) const {
            return new FireDoor(r1, r2);
        }
        
};