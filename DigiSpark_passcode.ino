# made for the DigiSpark board by digispark
# https://www.tindie.com/products/digistump/digispark-the-tiny-arduino-enabled-usb-dev-board/

#include "DigiKeyboard.h"
const int btn=2;
const int pwr=0;
bool test=0;

void setup() {
  //set up the button pins. 
  pinMode(btn,INPUT);
  pinMode(pwr,OUTPUT);
  digitalWrite(pwr,HIGH);
}


void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  // DigiKeyboard.sendKeyStroke(0);
  // Type out this string letter by letter on the computer (assumes US-style
  // keyboard)

  test=digitalRead(btn);
  DigiKeyboard.delay(1);
  DigiKeyboard.sendKeyStroke(0);
  if(test==1)
  {
    //print the password, and press enter/return.
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.println("DetSuperHemmeligePassordet123");
    //reset variable, just in case.
    test=0;
    //Debounce delay:
    DigiKeyboard.delay(200);
  }
  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
}
