#include "Keyboard.h"
  
  /*      Explanation:
  1. check if the button pressed corresponds to the value in the array.
      here's the problem. i'm not sure how i want to do this...
      i would like to use just one if statement. but idk.
  2. increment a counter to so the next placement in the array will be checked.
  3. wait for the button to be released .
  4. if any button is incorrectly pressed, blink long and reset counter. 
  repete util the counter is larger than the size of the array indicating that the sequence is complete. 
  5. blink to indicate that the passcode is correct. 
  6. enter a loop waiting for the buttons to indicate what password is desired.
  */
  

const int btn1 = 2;
const int btn2 = 3;
const int btn3 = 4;          // input pin for pushbutton
int previousButtonState = 1;   // for checking the state of a pushButton
int counter = 0;                  // button push counter
int i=0;
int PIN_CODE[]={1,2,3};
int btnVal=0;



void setup() {
  // cycle and make the Button pins an input:
  for(int i = 2; i<=4; i++){pinMode(i, INPUT);}
  // initialize control over the keyboard:
  Keyboard.begin();
}




void loop() {
  //Polling to avoid the program from looping all the time. 
  while(digitalRead(btn1) == HIGH && digitalRead(btn2) == HIGH && digitalRead(btn3) == HIGH){ delay(100);} // wait for the button to be pressed. 
  btnVal = btn_number();
    
  if (btnVal==PIN_CODE[counter])
  {counter++;}
  else 
  {counter=0;}

  while(digitalRead(btn1) == LOW || digitalRead(btn2) == LOW || digitalRead(btn3) == LOW){ delay(100); } //wait until the button is no longer pressed. 
  
    while (counter >= (sizeof(PIN_CODE)/sizeof(int))) //denne er visst sann hele tiden. skipper rett forbi pinkoden og looper her. 
           {
             while(digitalRead(btn1) == HIGH && digitalRead(btn2) == HIGH && digitalRead(btn3) == HIGH){ delay(100);} // wait for the button to be pressed. 

	     switch(btn_number())
	     {
		case 1:
		Keyboard.println("UserName");
		Keyboard.press(KEY_TAB);
		Keyboard.release(KEY_TAB);
		Keyboard.println("Password1");
		Keyboard.press(KEY_RETURN);
		Keyboard.release(KEY_RETURN);
		break;
		case 2:
		Keyboard.println("PAssword2");
		break;
		case 3:
		Keyboard.println("Password3");
		Keyboard.press(KEY_RETURN);
		Keyboard.release(KEY_RETURN);
		break;
		default:
		Keyboard.println("nope");
		break;
	     }
	     while(digitalRead(btn1) == LOW || digitalRead(btn2) == LOW || digitalRead(btn3) == LOW){ delay(100); } //wait until the button is no longer pressed. 
           }
}

int btn_number()
{
  if (digitalRead(btn1)==0){return 1;}
  if (digitalRead(btn2)==0){return 2;}
  if (digitalRead(btn3)==0){return 3;}
  else{return 0;}
}
