// ********************--- Working Button Code ---***************************
#include <Arduino.h>

int btns_row[] = {4, 5, 6};
int btns_col[] = {7, 8};
// 2x2 array of floats, each element is a button last action time

byte btns_state = 0b00000000; // 8 bits, each bit is a button state
                              // 0b00000000 means all buttons are not pressed
                              // 0b00000001 means button 0 is pressed
                              // 0b00000010 means button 1 is pressed
                              // 0b00000100 means button 2 is pressed
                              // 0b00001000 means button 3 is pressed
                              // 0b00001111 means button 0, 1, 2, 3 are  pressed
// scheme of button matrix as hardware
//
// pin 6 7 is output, LOW -> rows
// pin 4 5 is input, HIGH -> cols
//
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++) {
    pinMode(btns_row[i], OUTPUT); // meaning of OUTPUT is LOW
    digitalWrite(btns_row[i], HIGH);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(btns_col[i], INPUT_PULLUP); // meaning of INPUT_PULLUP is HIGH
  }
  Serial.begin(9600);
}

void loop() {
  btns_state = 0b00000000; // reset btns_state
  for (int i = 0; i < 3; i++) {
    digitalWrite(btns_row[i], LOW);
    for (int j = 0; j < 2; j++) {
      if (digitalRead(btns_col[j]) == LOW) {
        btns_state |= (1 << (i * 2 + j));
      }
    }
    digitalWrite(btns_row[i], HIGH);
  }
  if (btns_state != 0b00000000) {
    Serial.print("btns_state: ");
    Serial.print("0b");
    Serial.println(btns_state, BIN);
    // send reset code to Serial Monitor
    Serial.print("/r");
  }
}
