

#include "room.hpp"



Room::Room(int x, int y){

    if(x < 0 || y < 0){
        throw std::invalid_argument("Please provide positive integer values");
    }
    this->walls[0] = x;
    this->walls[1] = y;
}


int Room::getRoomDim(int dim) const{

    if(dim < 0 || dim > 1){
        throw std::invalid_argument("room has only 2 dimensions");
    }

    return this->walls[dim];
}