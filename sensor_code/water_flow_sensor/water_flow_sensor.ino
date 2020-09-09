/*
 * Water Flow Sensor
 * Output processed to read in litres/hour
*/

volatile int pulseCount;                        // Measures flow sensor pulses/Variable to count number of pulses
/*
 * The volatile integer “pulseCount” is important 
 * as it will be where we store the number of pulses during each second we test. 
 * The volatile term is used to ensure the variable updates correctly during the Interrupt Service Routine. 
 * Aside from that, it acts just like any other integer.
 */
 
                
unsigned int litresPerHour;                        // Calculated litres/hour
unsigned char flowSensorPin = 2;                   // Flow Sensor Input Pin on Arduino


unsigned int q_value = 5.5;
/* Pulse frequency (Hz) for FS300A G3/4" Water flow Sensor in Horizontal Test is 5.5Q, 
 *  where Q is flow rate in L/min. 
 * (Results in ± 3% range)
*/

//Interrupt Service Routine
void pulseCounter()
{
  // Increment the pulse counter/Increment the variable pulseCount on every pulse
  pulseCount++;
}

void setup() {
  // put your setup code here, to run once:
  
  
  pinMode(flowSensorPin, INPUT_PULLUP);

  // Initialize a serial connection for reporting values to the host
  Serial.begin(9600);
  
  /* The Hall-effect sensor is connected to pin 2 which uses interrupt 0. 
   * Configured to trigger on a FALLING state change.
   * (Interrupt is activated on HIGH to LOW transition )
   */
  digitalWrite(flowSensorPin, HIGH);
  attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING); //you can use Rising or Falling
}

void loop() {
  // put your main code here, to run repeatedly:
  pulseCount = 0;
  interrupts();             //Enables interrupts on the Arduino
  delay(1000);
  noInterrupts();
  //Now to calculate flow rate
  litresPerHour = pulseCount * 60 / q_value;
  Serial.print("Flow rate == ");
  Serial.println(litresPerHour);
}
