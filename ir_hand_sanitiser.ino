
const int servo = 9;
const int IRSensor=8; 

// defines variables

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(IRSensor, INPUT);
  myservo.attach(servo);  // attaches the servo on pin 9 to the servo object  
  myservo.write(0);   // Sets Servo to initially 0 degrees 
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
   int statusSensor=digitalRead(IRSensor);
    //Servo
    if(statusSensor== 0)
    { //Check distance is less than 10cm 
       myservo.write(45); // Sets Servo in stages from 0 to 180 degrees so soap does not pitch out. 
       delay(100);
       myservo.write(90);
       delay(100);
       myservo.write(135);
       delay(100);
       myservo.write(180); //Ajust how far you want the servo to go.
       delay(1000);
       myservo.write(0); // Reset the servo to 0 Degrees
       delay(3500);   //Delay the next time someone can get soap
    }
                    
}
