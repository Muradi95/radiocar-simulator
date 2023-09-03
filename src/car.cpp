

#include "car.hpp"

void Car::setPos(const int* initialPos){

    int arraySize = sizeof(initialPos)/sizeof(int);
    
    if(arraySize != DIM){
        throw std::length_error("initial position array must be 2");
    }

    // Negative positions are not valid
    if(initialPos[X] < 0 || initialPos[Y] < 0){
        throw std::range_error("invalid position");
    }
 
    this->pos[X] = initialPos[X];
    this->pos[Y] = initialPos[Y];
}


void Car::setDir(const int dir){

    int remainder = dir % 90;

    if(remainder != 0){
        throw std::invalid_argument("direction must be a multiple of 90");
    }

    this->dir = dir;
}


int Car::getDir() const{
    return this->dir;
}

int Car::getPos(int index) const{

    if(index < 0 || index > DIM){
        throw std::out_of_range("index out of range");
    }
    return this->pos[index];
}

void Car::update(Command command){

    this->turn(command);
    if(command == FWD || command == BWD){
        this->move(command);
    }

    this->numMoves += 1;

}


void Car::move(const Command cmd){
    
    float dirRad = this->dir*PI/180;
    this->pos[X] = this->pos[X] + (cmd)*std::cos(dirRad);       
    this->pos[Y] = this->pos[Y] + (cmd)*std::sin(dirRad); 
}

void Car::turn(const Command cmd){
    if(cmd == LEFT){
        this->dir += 90;
    }else if(cmd == RIGHT){
        this->dir -= 90;
    }
}

