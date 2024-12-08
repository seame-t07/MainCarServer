#include "JetSnailsCar.hpp"

#include <thread>

int main() {

    CANBus canBus("/dev/vcan0", 500000);
    
    JetSnailsCar delorean;

    Controller controller;
    delorean.setController(&controller);

    while(1) {
        std::thread drive(&JetSnailsCar::drive, &delorean);
        drive.join();
    }

    return 0;
}