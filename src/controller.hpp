#ifndef _CAR_CONTROLLER_H
#define _CAR_CONTROLLER_H


#include "car.hpp"
#include <iostream>
#include <string>
#include "room.hpp"


class Controller{

    private: 
        Car car;
        Room room;
        bool carCrash;
      

        int parseDir(const char dir);
        void parseInitialPos();

        int parseCommands(Command* buffer, int bufferSize);
        Command strToCommand(const char c);
        void parseRoomDim();
        void checkRoomBounds();
    
    public:
        Controller(std::ostream& ostream, std::istream& istream);

        bool getCarStatus(){return carCrash;}
        void printCarPos();
    

};




#endif