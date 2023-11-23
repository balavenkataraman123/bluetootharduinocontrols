#define LED_PIN 13

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); // set the digital pin as output:
  Serial.println("Send a command");
}

void loop() {
  if (Serial.available()) { // if there is data comming
    String command = Serial.readStringUntil('\n'); // read string until meet newline character

    if (command == "OFF") {
      digitalWrite(LED_PIN, LOW);  // turn off LED
      Serial.println("LED is turned OFF"); // reports action to smartphone app
    } else if (command == "ON") {
      digitalWrite(LED_PIN, HIGH); // turn on LED
      Serial.println("LED is turned ON"); // reports action to smartphone app
    }
  }
}
