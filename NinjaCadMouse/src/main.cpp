#include <Arduino.h>
#include <AnalogKeypad.h>

const int KeypadMap[] = {
  4095, 3780, 3303, 
  2980, 2750, 2550,
  2370, 2220, 2100,
  1970, 1860, 1770};

const uint16_t KeypadHoldTimeMs = 5000;
const uint8_t KeypadAnalogPin = 34;

AnalogKeypad keypad(KeypadAnalogPin, KeypadMap, countof(KeypadMap), KeypadHoldTimeMs);

void ButtonHandler(const ButtonParam& param)
{
  Serial.print(param.button);
  Serial.print(" ");
  
  switch (param.state)
  {
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
  // Serial.println(analogRead(34));
  delay(20);
}