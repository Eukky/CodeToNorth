#include "Room.h"
#include "Wall.h"
#include "Door.h"
class Maze {
    public:
        Maze();

        void AddRoom(Room* room);
        Room* GetRoom(int roomNumber) const;
};