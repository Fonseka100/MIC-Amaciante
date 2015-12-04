#include <Stepper.h>
#include <Wire.h>
#include "rgb_lcd.h" // usar proprio pc, bilioteca no face

#define STEPS 48

//Stepper stepper(STEPS, 8, 9, 10, 11);
//Stepper stepper(STEPS, 8, 9, 11, 10);
Stepper stepper(STEPS, 8, 11, 9, 10);
int ledPin=4;
int relayPin = 5;
int sensorLuz = 3;
int lastValue = 800;
int button = 2;
int buzzerPin = 6;


rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(5);
  pinMode(ledPin,OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(ledPin,HIGH);
  digitalWrite(relayPin, HIGH);
  
  pinMode(button, INPUT_PULLUP); // interrupção
  attachInterrupt(0, interrupcao, FALLING);
  
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  Serial.begin(9600);

}

void loop() {
  int sensorValue = analogRead(sensorLuz);
  Serial.println(sensorValue);
  stepper.step(1);
  if((lastValue - sensorValue) > 20)
    putAmaciante();
  
  lastValue = sensorValue;
 
  delay(10);
}


void  putAmaciante(){
  lastvalue = 800;
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, HIGH);  
  lcd.print("Coloque amaciante");
  delay(500);
  digitalWrite(buzzerPin, LOW);  
  while(1){
    
  }
}

void interrupcao() {
  lcd.clear();
  digitalWrite(relayPin, HIGH);
}
