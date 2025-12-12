#include "USB.h"
#include "USBHIDKeyboard.h"

#define BUTTON_SPACE A0
#define BUTTON_ENTER A1

USBHIDKeyboard Keyboard;

void setup() {
  pinMode(BUTTON_SPACE, INPUT_PULLUP);
  pinMode(BUTTON_ENTER, INPUT_PULLUP);

  Keyboard.begin();       
  USB.begin();
                                      
}

void loop() {
  if (!digitalRead(BUTTON_SPACE)){
    Keyboard.press(' ');
    delay(10);
        
    Keyboard.release(' ');
    delay(250);
  }

  if (!digitalRead(BUTTON_ENTER)){
    Keyboard.press(KEY_KP_ENTER);
    delay(10);

    Keyboard.release(KEY_KP_ENTER);
    delay(250);
  }
}
