#include "MapSite.h"
#include "Room.h"
class Door : public MapSite {
    public:
        Door(Room* room1 = 0, Room* room2 = 0);

        virtual void Enter();

        Room* OtherSideFrom(Room* room);
    
    private:
        Room* _room1;
        Room* _room2;
        bool _isOpen;

};