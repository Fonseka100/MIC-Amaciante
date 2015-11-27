#include <Stepper.h>

#define STEPS 48

//Stepper stepper(STEPS, 8, 9, 10, 11);
//Stepper stepper(STEPS, 8, 9, 11, 10);
Stepper stepper(STEPS, 8, 11, 9, 10);

int previous = 0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(60);
}

void loop() {
  stepper.step(48);
  delay(1000);
}
