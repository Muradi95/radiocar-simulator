

#include "controller.hpp"




Controller::Controller(std::ostream& ostream, std::istream& istream){
   
    this->car = Car();
    parseRoomDim();
    //std::cout << room.getRoomDim(1) << std::endl;
    parseInitialPos();

    Command commandbuffer[COMMAND_BUFFER_SIZE];
    int n = parseCommands(commandbuffer, COMMAND_BUFFER_SIZE);
    
    //  iterate over the commands and update the car pos 
    this->carCrash = false;
    for(int i = 0; i < n; i++){
        this->car.update(commandbuffer[i]);

          printCarPos();

        this->checkRoomBounds();
        if (this->carCrash){
            break;
        }

      
    }
}

void Controller::parseRoomDim(){

    std::cout << "Please, provide room dimensions ";
    int posX, posY; 
    std::cin >> posX >> posY;
    this->room = Room(posX, posY);

}

void Controller::parseInitialPos(){

    std::cout << "Provide initial position and direction of the car: ";

    int pos[DIM];
    char dir;

    std::cin >> pos[X] >> pos[Y] >> dir;
    int numericDir = this->parseDir(dir);

    if (numericDir == -1){
        throw std::invalid_argument("Direction must be specified with the \
            following characters, 'S', 'W', 'E', 'N'");
    }

    // check that the provided position is inside the room
    if (pos[X] > this->room.getRoomDim(0) ||
            pos[Y] > this->room.getRoomDim(1)){
        throw std::invalid_argument("The provided position is invalid");
    }

    this->car.setPos(pos);
    this->car.setDir(numericDir);

}

int Controller::parseCommands(Command* buffer, int bufferSize){
    std::cout << "Provide commands: ";
   
    std::string cmds; 
    std::cin >> cmds;
    int n = cmds.length();
    
    if (n > bufferSize){
        throw std::length_error("Command sequence greater than buffer size, please insert fewer commands");
    }
    // traverse the string and convert it to an array of commands 
    for(int i=0; i < n; i++){
        Command c = strToCommand(cmds[i]);
        buffer[i] = c;
    }
   
    return n;

}

void Controller::checkRoomBounds(){ 

    if(this->car.getPos(X) < 0 || this->car.getPos(Y) < 0){
        this->carCrash = true; 
    }else if(this->car.getPos(X) > this->room.getRoomDim(X)){
        this->carCrash = true; 
    }else if(this->car.getPos(Y) > this->room.getRoomDim(Y)){
        this->carCrash = true; 
    }

}

void Controller::printCarPos(){
    std::cout << "Pos: " << "(" \
    << this->car.getPos(X) << "," \
    << this->car.getPos(Y) << "), dir= " 
    << this->car.getDir() << std::endl;
}

Command Controller::strToCommand(const char c){

    Command cmd;
    switch (toupper(c))
    {
    case 'F':
        cmd = FWD;
        break;
    case 'B':
        cmd = BWD; 
        break; 
    case 'L':
        cmd = LEFT; 
        break; 
    case 'R':
        cmd = RIGHT;
        break;
    default:
        throw std::invalid_argument("invalid command");
        break;
    }

    return cmd;
}

int Controller::parseDir(const char dir){
    int numericDir = -1;
    
    switch (toupper(dir))
    {
    case 'E':
        numericDir = 0;
        break; 
    case 'N':
        numericDir = 90;
        break;
    case 'W':
        numericDir = 180;
        break; 

    case 'S':
        numericDir = 270;
        break;
    default:
        break;
    }

    return numericDir;
}