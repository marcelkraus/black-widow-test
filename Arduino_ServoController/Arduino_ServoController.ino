#include <Servo.h>
#include <SoftwareSerial.h>

int LED = 13;
Servo myservo;
SoftwareSerial BLE_Shield(4,5);

void setup() { 
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  myservo.attach(9);
  myservo.write(0);
  BLE_Shield.begin(9600);
}

void loop() {
  if (BLE_Shield.available()) {
    myservo.write(BLE_Shield.read());
  }
}
