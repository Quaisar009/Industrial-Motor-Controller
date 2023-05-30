#include "SequenceTimes.h"

//  unsigned long sequenceTimes[5] = {
//    120,   // On Sequence 1 (in minutes)
//    1,    // Off Sequence 2 (in minutes)
  
//    2,  // On Sequence 3 (in minutes)
//    8    // Off Sequence 4 (in minutes)
//  };


const int MOTOR = 3;  //connect motor to pin 3 
const int START_BUTTON_PIN_2 = 2;  //connect start push button to pin 2.
const int STOP_BUTTON_PIN_9 = 9;  //connect stop push button to pin 9.
const int P_R_BUTTON_PIN_4 = 4;  //connect pause push button to pin 4.

const int START_LED_PIN_5 = 5;  //connect start led button to pin 5.
const int STOP_LED_PIN_6 = 6;  //connect stop led button to pin 6.
const int P_R_LED_PIN_8 = 8;   //connect pause/resume led button to pin 8.
const int STATUS_LED_PIN_7 = 7;  //connect status led button to pin 7




// define variables for MOTOR state and sequence interval
bool motorOn = false;
bool paused = false;
int lastButton = 0;
bool shouldRunLoop = false;
bool motorstatus1 = false;
bool motorstatus2 = false;
bool start = false;

unsigned long lastSequenceTime = 0;
int sequenceIndex = 0; // index to keep track of which blink time to use
// unsigned long elapsedTime = 0;
    unsigned long elapsedTimeOn = 0;
    unsigned long elapsedTimeOff = 0;
    unsigned long Time;





void setup() {

  pinMode(MOTOR, OUTPUT);
  digitalWrite(MOTOR, HIGH);
  // initialize button pins as inputs with pull-up resistors
  pinMode(START_BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(STOP_BUTTON_PIN_9, INPUT_PULLUP);
  pinMode(P_R_BUTTON_PIN_4, INPUT_PULLUP);

  pinMode(START_LED_PIN_5, OUTPUT);
  pinMode(STOP_LED_PIN_6, OUTPUT);
  pinMode(P_R_LED_PIN_8, OUTPUT);
  pinMode(STATUS_LED_PIN_7, OUTPUT);

  Serial.begin(9600);
}

void loop() {
 
    // check if button 21 is pressed
    if (digitalRead(START_BUTTON_PIN_2) == LOW && !shouldRunLoop){
        shouldRunLoop = true;
        lastButton = 21;
        motorOn = true;
        paused = false; // resume blinking if previously paused
        sequenceIndex = 0; // reset blink index to start from beginning of array
        digitalWrite(MOTOR, LOW); // turn on LED
        digitalWrite(STATUS_LED_PIN_7, HIGH); // turn on LED19
        Serial.println("Button 21 pressed"); // output message to serial monitor
        delay(1000); // debounce delay
        lastSequenceTime = millis(); // initialize last blink time to current time
        start = true;
        
    }

  while (start) {

    Time = millis(); // initialize last sequence time to current time
    shouldRunLoop = false;

    
   


    // check if button 22 is pressed
    if (digitalRead(STOP_BUTTON_PIN_9) == LOW) {
        lastButton = 22;
        motorOn = false; // turn off LED
        paused = true; // pause blinking
        digitalWrite(MOTOR, HIGH); // turn off LED
        digitalWrite(STATUS_LED_PIN_7, LOW); // turn off status led
        Serial.println("Button 22 pressed"); // output message to serial monitor
        Serial.println("MOTOR Stopped"); // output message to serial monitor
        delay(1000); // debounce delay
        start= false;
    }

// check if pause resume button is pressed
if (digitalRead(P_R_BUTTON_PIN_4) == LOW) {
  

      if (digitalRead(MOTOR)==LOW){
      motorstatus1 = true;
      }
      else if (digitalRead(MOTOR)==HIGH){
      motorstatus2 = true;
      }


  lastButton = 23;
  digitalWrite(STATUS_LED_PIN_7, HIGH); // turn on LED19
  paused = !paused; // toggle pause state
  
  if (paused) {

    if(motorstatus1) {
      digitalWrite(MOTOR, HIGH); // turn off the motor if it was previously on
      Serial.println("MOTOR paused--on state"); // output message to serial monitor
      elapsedTimeOn += millis() - lastSequenceTime;
        }
    else if(motorstatus2){
      elapsedTimeOff += millis() - lastSequenceTime;
      Serial.println("MOTOR paused--off state"); // output message to serial monitor
      }
  } 
  else {    
    lastButton = 21;
                if (motorstatus1==true){
                  digitalWrite(MOTOR, LOW);
                  Serial.println("MOTOR resumed--on state"); // output message to serial monitor
                  lastSequenceTime = Time - elapsedTimeOn;
                  elapsedTimeOn = 0; // Reset elapsed time for the on state
                  motorstatus1 = false;

                  }
                else if (motorstatus2==true && motorstatus1==false){
                  Serial.println("MOTOR resumed--off state"); // output message to serial monitor
                  lastSequenceTime  = Time - elapsedTimeOff;
                  elapsedTimeOff = 0; // Reset elapsed time for the off state
                  motorstatus2 = false;
                  }
  }
  
  delay(1000); // debounce delay
}


    switch (lastButton) {
  case 21:
    digitalWrite(START_LED_PIN_5, HIGH);
    digitalWrite(STOP_LED_PIN_6, LOW);
    digitalWrite(P_R_LED_PIN_8, LOW);
    break;
  case 22:
    digitalWrite(START_LED_PIN_5, LOW);
    digitalWrite(STOP_LED_PIN_6, HIGH); // turn on STOP_LED_PIN_6
    digitalWrite(P_R_LED_PIN_8, LOW);
    break;
  case 23:
    digitalWrite(START_LED_PIN_5, LOW);
    digitalWrite(STOP_LED_PIN_6, LOW);
    digitalWrite(P_R_LED_PIN_8, HIGH);
    
    break;
  case 233:
    digitalWrite(START_LED_PIN_5, LOW);
    digitalWrite(STOP_LED_PIN_6, LOW); // turn on STOP_LED_PIN_6
    digitalWrite(P_R_LED_PIN_8, LOW);
      digitalWrite(STATUS_LED_PIN_7, LOW); // turn off status led

    break;

  default:
    digitalWrite(START_LED_PIN_5, LOW);
    digitalWrite(STOP_LED_PIN_6, LOW);
    digitalWrite(P_R_LED_PIN_8, LOW);
    break;
}

    // switch motor state according to on/off times if not paused
    if (!paused && (Time - lastSequenceTime) >= (sequenceTimes[sequenceIndex] * 1000)) {
      lastSequenceTime = Time;
      if (motorOn) {
        digitalWrite(MOTOR, !digitalRead(MOTOR)); // toggle MOTOR
        Serial.println(digitalRead(MOTOR) ? "MOTOR off" : "MOTOR on"); // output MOTOR state to serial monitor
      }
      Serial.print("Time (sec):-----------------------"); // output sequence time to serial monitor
      Serial.println(sequenceTimes[sequenceIndex]);
      sequenceIndex++; // increment sequence index to move to next sequence time

      if (sequenceIndex >= 30) {
        sequenceIndex = 0; // reset sequence index to start from beginning of array   
                       
      }
           
    } 
    // Turn off status and start led once loop completed
    if (sequenceIndex >= 24 ) {
        lastButton = 233;
    }  
  } 
}  
