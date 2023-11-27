// Bluetooth controlled RC car steering
// by Bala Venkataraman

#include <Servo.h> // include library for servo
 
Servo str_servo; // define steering rack servo
#define RECEIVER_PIN 7 // define pin for infrared receiver


IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class

const int straight_angle = 95; // angle to point the rack straight

void setup() {
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  receiver.enableIRIn(); // enable the receiver
  str_servo.attach(9); // attach servo to pin 9
  str_servo.write(straight_angle); // set steering angle to the default angle
  pinMode(9, OUTPUT);
  Serial.println("Send a command");
} 

void loop() {
  if (Serial.available()) { // if there is data comming
    String command = Serial.readStringUntil('\n'); // read string until meet newline character
    int rack_angle = command.toInt();
    str_servo.write(straight_angle + rack_angle)
  }
    
  }

