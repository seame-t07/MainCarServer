#include "JetSnailsCar.hpp"

#include <thread>

int main() {

    CANBus canBus("vcan0", 500000);
    Controller controller;
    JetSnailsCar delorean;

    delorean.setController(&controller);


    while(1) {
        std::thread drive(&JetSnailsCar::drive, &delorean);
        drive.join();
    }

    return 0;
}