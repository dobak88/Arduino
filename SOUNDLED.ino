
const int  sensorAnalogPin = A2;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
const int  sensorDigitalPin = 7;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;               // Define variable to store the analog value coming from the Sound Sensor
int  digitalValue;                  // Define variable to store the digital value coming from the Sound Sensor
const int  Led13 = 13;              // Define LED port; this is the LED built in to the Arduino (labled L)
                                    // When D0 from the Sound Sensor (connnected to pin 7 on the
                                    // Arduino) sends High (voltage present), L will light. In practice, you
                                    // should see LED13 on the Arduino blink when LED2 on the Sensor is 100% lit.
const double maxL = 539;            //the level where LEDs turn on- edit it here
const int delayT = 5;               //delay time



void setup() {
  
  Serial.begin(9600);               // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  pinMode(sensorDigitalPin,INPUT);  // Define pin 7 as an input port, to accept digital input
  pinMode(Led13,OUTPUT);            // Define LED13 as an output port, to indicate digital trigger reached

}

void loop() {

  analogValue = analogRead(sensorAnalogPin);          // Read the value of the analog interface A0 assigned to digitalValue 
  digitalValue=digitalRead(sensorDigitalPin);         // Read the value of the digital interface 7 assigned to digitalValue 
  
  Serial.println(analogValue);                        // Send the analog value to the serial transmit interface
  if(analogValue > maxL)                              // When the Sound Sensor sends signla, via voltage present, light LED13 (L)
  {
    digitalWrite(Led13,HIGH);
  }
  else
  {
    digitalWrite(Led13,LOW);
  }
  
  delay(delayT);               // Slight pause so that we don't overwhelm the serial interface

}
