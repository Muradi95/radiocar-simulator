
#ifndef CAR_H 
#define CAR_H

#include "constants.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>




enum Command{
    FWD = 1,
    BWD = -1,
    LEFT = 2,
    RIGHT = 3
};



class Car{
    public:
        void update(Command cmd);
        Car(const int *initialPos){
            this->setPos(initialPos);
            this->setDir(0);
        }
        Car() {
            const int initialPos[DIM] = {0,0};
            this->setPos(initialPos);
            this->setDir(0);
        };
    
        void setPos(const int *initialPos);
        void setDir(const int dir);

        int getDir() const;
        int getPos(int index) const;

    private: 
        int pos[DIM];
        int dir;
        int numMoves = 0;
    
        void move(const Command cmd);
        void turn(const Command cmd);
        
};




#endif