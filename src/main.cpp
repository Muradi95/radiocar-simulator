

#include "car.hpp"
#include "controller.hpp"


int main(){


    try{
        Controller carCntrl = Controller(std::cout, std::cin);

        if (carCntrl.getCarStatus()){
            // car crashed
            std::cout << "Simulation failure: car crashed into wall" << std::endl;
        }else{
            std::cout << "final car position: \n";
            std::cout <<"-------------------------------\n";
            carCntrl.printCarPos();
        }
    }catch(const std::exception& ex){
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}