#include "MazeFactory.h"
#include "IceRoom.h"
#include "IceDoor.h"
class IceMazeFactory : public MazeFactory {
    public:
        IceMazeFactory();

        virtual Room* MakeRoom(int n) const {
            return new IceRoom(n, Power::IcePower);
        }

        virtual Door* MakeDoor(Room* r1, Room* r2) const {
            return new IceDoor(r1, r2);
        }
        
};