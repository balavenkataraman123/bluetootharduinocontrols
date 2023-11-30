// Bluetooth controlled RC car steering
// by Bala Venkataraman

#include <Servo.h> // include library for servo
 
Servo str_servo; // define steering rack servo

const int straight_angle = 95; // angle to point the rack straight
const int relay_directional_pin = 11; // This controlls the relay which makes the car go forward if coil is high and backward if coil is low
const int relay_cutoff_pin = 10; // this makes the car stop when the coil is low and go when it is high. (if it is other way

void setup() {
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  str_servo.attach(9); // attach servo to pin 9
  str_servo.write(straight_angle); // set steering angle to the default angle
  pinMode(9, OUTPUT); // configures all the pins to output
  pinMode(relay_directional_pin, OUTPUT);
  pinMode(relay_cutoff_pin, OUTPUT);
  digitalWrite(relay_directional_pin, LOW);
  digitalWrite(relay_cutoff_pin, LOW);
  Serial.println("Send a command");
} 

void loop() {
  if (Serial.available()) { // if there is data comming
    String command = Serial.readStringUntil('\n'); // read string until meet newline character
    int rack_angle = command.toInt();
    if(rack_angle > 900){
      str_servo.write(straight_angle + (rack_angle - 1000)); // makes the car go forward
      digitalWrite(relay_directional_pin, LOW);
      digitalWrite(relay_cutoff_pin,HIGH);
    }
    else if (rack_angle < -900){
      str_servo.write(straight_angle + (1000 + rack_angle)); // makes the car go backward
      digitalWrite(relay_directional_pin, HIGH);
      digitalWrite(relay_cutoff_pin,HIGH);
    }
    else{
      str_servo.write(straight_angle + rack_angle); // makes the car stop
      digitalWrite(relay_directional_pin, LOW);
      digitalWrite(relay_cutoff_pin, LOW);    
    }    
  }
    
}

