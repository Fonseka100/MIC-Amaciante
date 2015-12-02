#include <Stepper.h>

#define STEPS 48

//Stepper stepper(STEPS, 8, 9, 10, 11);
//Stepper stepper(STEPS, 8, 9, 11, 10);
Stepper stepper(STEPS, 8, 11, 9, 10);
int ledPin=4;
int relayPin = 5;
int previous = 0;
int val = 0;
int lastValue = 800;

void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(5);
  pinMode(ledPin,OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(ledPin,HIGH);
  Serial.begin(9600);
  digitalWrite(relayPin, HIGH);

}

void loop() {
  int sensorValue = analogRead(3);
  Serial.println(sensorValue);
  stepper.step(1);
  if((lastValue - sensorValue) > 20){
    digitalWrite(relayPin, LOW);
    delay(1000);
  } else 
      digitalWrite(relayPin, HIGH);
      
  lastValue = sensorValue;

    
  delay(10);
}


