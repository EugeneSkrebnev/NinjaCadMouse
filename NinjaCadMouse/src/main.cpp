#include <Arduino.h>
#include <AnalogKeypad.h>


const int KeypadMap[] = {
  1770, 1860, 1970, 
  2100, 2225, 2375,
  2550, 2750, 2980,
  3308, 3790, 4095
  };


const uint16_t KeypadHoldTimeMs = 300;
const uint8_t KeypadAnalogPin = 34;

AnalogKeypad keypad(KeypadAnalogPin, KeypadMap, countof(KeypadMap), KeypadHoldTimeMs);

void ButtonHandler(const ButtonParam& param) {
  Serial.print(param.button);
  Serial.print(" ");
  
  switch (param.state) {
    case ButtonState_Up:
    Serial.print("Up");
    break;
    
    case ButtonState_Down:
    Serial.print("Down");
    break;
    
    case ButtonState_Click:
    Serial.print("Click");
    break;
    
    case ButtonState_DoubleClick:
    Serial.print("Double Click");
    break;
    
    case ButtonState_Hold:
    Serial.print("Hold");
    break;
  }
  
  Serial.println();
}

void setup() {
  Serial.begin(115200);

  while (!Serial); // wait for serial attach

    Serial.println();
    Serial.println("Initialized");
}

void loop() {
  keypad.loop(ButtonHandler);
  delay(10);
}