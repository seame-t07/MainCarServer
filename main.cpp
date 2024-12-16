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
	speedSensor->readData();
	parkSensor->readData();
	std::cout << "Speed: " << speedSensor->getValue() << std::endl;
	std::cout << "Distance: " << parkSensor->getValue() << std::endl;
    }
    
    return 0;
}
