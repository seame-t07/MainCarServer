#include "JetSnailsCar.hpp"
#include <pigpio.h>
#include <thread>


int main() {

    CANBus canBus("can0", 500000);
    JetSnailsCar delorean;

    ISensor* speedSensor = new SpeedSensor(canBus, 0x100);
    ISensor* parkSensor = new ParkSensor(canBus, 0x200);

    delorean.setSpeedSensor((SpeedSensor*)speedSensor);
    delorean.setParkSensor((ParkSensor*)parkSensor);

    while(1)
    {
        delorean.getSpeed();
        delorean.getDistance();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
    return 0;
}
