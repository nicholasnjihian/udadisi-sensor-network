#include "mbed.h"

//Pi mbed USB Slave function
// connect mbed to Pi USB
RawSerial pi(USBTX, USBRX);

//mbed LED
DigitalOut led1(LED1);

AnalogIn sensorMQ4(p17);

const int numReadings = 500;

//MQ4
const float airRatioMQ4 = 4.4;
const float slopeMQ4 = -0.3485;
const float interceptMQ4 = 1.0544;

float mq4sensorPPM = 0;

float r0MQ4 = 1.826011;

float alarmMQ4 = 1000;

float calculateR0(AnalogIn s, float ratio) {
        float sensor_volt;
        float rs;
        float sensorValue = 0.0;
        float r0;

        //take 500 sensor readings and add them together
        for(int i = 0; i < numReadings; i++) {
            sensorValue = sensorValue + s.read();
        }

        sensorValue = sensorValue/numReadings;//average sensor value
        sensor_volt = sensorValue * 3.3;
        rs = ((3.3-sensor_volt)/sensor_volt);
        r0 = rs/ratio;
        pi.printf("RO VALUE: %f \n\n", r0);
        return r0;
}


//Calculate the value of gas concentration in ppm
float determinePPM(AnalogIn sensor, float R0, float m, float b) {
        //Slope and y-intercept of ppm graph line, and R0 from previous calculations
        float voltage = sensor.read() * 3.3;
        float RS_gas = ((3.3-voltage)/voltage);
        float ppmRatio = RS_gas/R0;
        float ppm_log = (log10(ppmRatio)-b)/m;
        float ppm = pow(10, ppm_log);
        if(ppm<0){
            ppm = 0.0;
        }
        if(ppm>10000){
            ppm = 10000;
        }
        return ppm;
}

void sendData {

}
