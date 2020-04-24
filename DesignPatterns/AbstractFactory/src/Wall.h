#include "MapSite.h"

class Wall : public MapSite {
    public:
        Wall();

        virtual void Enter();
};