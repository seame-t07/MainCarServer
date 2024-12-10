#include "JetSnailsCar.hpp"
#include <pigpio.h>
#include <thread>

int main() {

    // CANBus canBus("vcan0", 500000);
    Controller controller;
    JetSnailsCar delorean;

    Actions buzzer;
    buzzer.onpress = activated_buzzer;
    buzzer.onRelease = activated_buzzer;
    controller.setButtonAction(SDL_CONTROLLER_BUTTON_A, buzzer);

    delorean.setController(&controller);
    
    if (gpioInitialise() < 0) {
        throw std::runtime_error("Failed to initialize pigpio library");
    }

    std::thread drive(&JetSnailsCar::drive, &delorean);
    drive.join();
    
    return 0;
}
