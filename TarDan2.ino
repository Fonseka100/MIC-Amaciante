#include <Stepper.h>
#include <Wire.h>
#include "rgb_lcd.h" // usar proprio pc, bilioteca no face

#define STEPS 48
#define LUZ   45

//Stepper stepper(STEPS, 8, 9, 10, 11);
//Stepper stepper(STEPS, 8, 9, 11, 10);
Stepper stepper(STEPS, 8, 11, 9, 10);
int ledPin=4;       // atualmente usando lanterna
int relayPin = 5;
int sensorLuz = 3;
int lastValue;      // para comparar variações de luz
int button = 2;
int buzzerPin = 6;

int nada = 1;   // nenhum botao pressionado


rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

void setup() {
  stepper.setSpeed(5);            // velocidade do motor de passo
  pinMode(button,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
 
  

  
  /* configuração inicial dos acessórios do groove */
  digitalWrite(ledPin,HIGH);          // LED ou lanterna acesa
  digitalWrite(relayPin, HIGH);       // relay ligado para alimentar o motor
  digitalWrite(buzzerPin, LOW);       // buzina desligada
  lastValue = analogRead(sensorLuz);  // valor base será o lido aqui
  
  pinMode(button, INPUT_PULLUP);      // interrupção porta 2 do Arduino Mega quando botão é perssionado
  attachInterrupt(0, interrupcao, RISING);
  
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  
  lcd.print("Aguarde");
  Serial.begin(9600);
}

void loop() {
  digitalWrite(relayPin, HIGH);   // motor volta a funcionar
  nada = 1;
  int sensorValue = analogRead(sensorLuz);    // lê o valor no sensor de luz
  Serial.println(lastValue - sensorValue);
  stepper.step(1);                            // anda um passo com o motor para simular botão da máquina
  if((abs(lastValue - sensorValue)) > LUZ)    // botao chegou ou saiu da posição crítica
      putAmaciante();                         // procedimento amaciante é então chamado  
                                              // será chamado o procedimento amaciante
  lastValue = sensorValue;                    // atualiza ultimo valor lido
  delay(10);
}


void  putAmaciante(){
  stepper.step(1);
  digitalWrite(relayPin, LOW);        // desliga o motor com o relê
  lcd.clear();
  lcd.print("Put amaciante");   // escreve ação a ser tomada no display LCD
  
  while(nada){                        // enquanto o botão não for pressionado
    digitalWrite(buzzerPin, HIGH);    // buzine um pouco  
    delay(400);                           
    digitalWrite(buzzerPin, LOW);     // desliga a buzina
    delay(600);
  }
  lcd.clear();
  lcd.print("Centrifugando");
  nada = 1;                           // botão já foi pressionado logo volte a indicar que "nada" está acontecendo  
}

void interrupcao() {              // quanto botão é pressionado
  

  nada = 0;                       // flag indica que botão foi pressionado (muda para 0)
}

