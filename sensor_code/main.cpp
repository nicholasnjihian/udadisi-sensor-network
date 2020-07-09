#include "mbed.h"

int main() {
     //To reset R0 from default to your enviroment's desired value uncomment
//    r0MQ4 = calculateR0(sensorMQ4, airRatioMQ4);

    while true {
        mq4sensorPPM = determinePPM(sensorMQ4, r0MQ4, slopeMQ4, interceptMQ4);
        mq135sensorPPM = determinePPM(sensorMQ135, r0MQ135, slopeMQ135, interceptMQ135);
        if(mq4sensorPPM>alarmMQ4) {
            speaker.period(1.0/500.0); //frequency of sound
            speaker = 1.0; //volume
            red = 1.0f;
        } else {
            speaker = 0.0;
            red = 0.0f;
        }
    }
}
