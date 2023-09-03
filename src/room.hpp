
#ifndef ROOM_H

#include "car.hpp"

class Room{

    private:
        int walls[2];

    public:
        Room(int x, int y);
        Room(){walls[0] = 10; walls[1] = 5;};
        int getRoomDim(int dim) const;

};

#endif