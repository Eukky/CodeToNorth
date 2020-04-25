#include "MapSite.h"

class Room : public MapSite {
    public:
        Room(int roomNumber);

        MapSite* GetSide(Direction direction) const;
        void SetSide(Direction direction, MapSite* mapsite);

        virtual void Enter();

    private:
        MapSite* _side[4];
        int _roomNumber;
};