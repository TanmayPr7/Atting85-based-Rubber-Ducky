#include "DigiKeyboard.h"                     //Library Required

int digits[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38};     // an array of key codes for digits 0-9
int code[] = {0, 0, 0, 0, 0, 0};                             // an array to hold the 6-digit code
int count = 0;                                               // a counter for the number of attempts

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);                             //this is generally not necessary but with some older systems it seems to prevent missing the first character after a delay
  delay(3000);                                               // wait for the device to be ready

  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);                            //Defining PinMode
  pinMode(4, INPUT);
}

void loop() {
  if (digitalRead(0) == HIGH) {
    DigiKeyboard.print("passwordavenger123$");
    DigiKeyboard.delay(200);                        //Personal Password
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
  }

  if (digitalRead(1) == HIGH) {
    DigiKeyboard.print("password290524");
    DigiKeyboard.delay(200);                        //Personal Pin
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
  }

  if (digitalRead(4) == HIGH) {
    int a = 1;
    while (a = 1) {
      DigiKeyboard.sendKeyStroke(0);
      DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
      DigiKeyboard.delay(2000);
      DigiKeyboard.print("notepad");                              //Prank
      DigiKeyboard.delay(1000);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(200);
      DigiKeyboard.println("You Are Hacked!!");
    }
  }
  //if (digitalRead(2) == LOW) {
  //    if (count == 5) {
  //      digitalWrite(1, HIGH);                        //Change this to 0 if using DigiSpark model B
  //      DigiKeyboard.sendKeyStroke(40);               //we hit enter to make the popup go away
  //      delay(1000);
  //      count = 0;
  //      digitalWrite(1, LOW);
  //    }
  //
  //    //send the keystrokes for the 6-digit code
  //    for (int i = 0; i < 6; i++) {
  //      DigiKeyboard.sendKeyStroke(digits[code[i]]);
  //      delay(50);
  //    }
  //
  //    //hit enter to try the code                      //6-digit Rubber Ducky
  //    DigiKeyboard.sendKeyStroke(40);
  //
  //    //increment the code array
  //    for (int i = 5; i >= 0; i--) {
  //      code[i]++;
  //      if (code[i] == 10) {
  //        code[i] = 0;
  //      } else {
  //        break;
  //      }
  //    }
  //
  //    count++;
  //    delay(0); // wait 0 second before trying the next code
  //  }
  //
  //if (digitalRead(3) == HIGH) {
  //    if (count == 5) {
  //      digitalWrite(1, HIGH);                        //Change this to 0 if using DigiSpark model B
  //      DigiKeyboard.sendKeyStroke(40);               //we hit enter to make the popup go away
  //      delay(1000);
  //      count = 0;
  //      digitalWrite(1, LOW);
  //    }
  //
  //    //send the keystrokes for the 4-digit code
  //    for (int i = 0; i < 4; i++) {
  //      DigiKeyboard.sendKeyStroke(digits[code[i]]);
  //      delay(50);
  //    }
  //
  //    //hit enter to try the code                      //4-digit Rubber Ducky
  //    DigiKeyboard.sendKeyStroke(40);
  //
  //    //increment the code array
  //    for (int i = 3; i >= 0; i--) {
  //      code[i]++;
  //      if (code[i] == 10) {
  //        code[i] = 0;
  //      } else {
  //        break;
  //      }
  //    }
  //
  //    count++;
  //    delay(0); // wait 0 second before trying the next code
  //  }

  DigiKeyboard.delay(100);
}
