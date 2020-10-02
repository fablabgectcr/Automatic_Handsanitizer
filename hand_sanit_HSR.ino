int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;

void setup()
{
	pinMode(trigPin, OUTPUT); // trig pin will have pulses output
	pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
	pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}

void loop()
{
	// Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
	int duration, distance;
	// Output pulse with 1ms width on trigPin
	digitalWrite(trigPin, HIGH); 
	delay(1);
	digitalWrite(trigPin, LOW);
	// Measure the pulse input in echo pin
	duration = pulseIn(echoPin, HIGH);
	// Distance is half the duration devided by 29.1 (from datasheet)
	distance = (duration/2) / 29.1;
	// if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance <= 50 && distance >= 0) {
    	// Buzz
    	digitalWrite(buzzPin, HIGH);
    } else {
    	// Don't buzz
    	digitalWrite(buzzPin, LOW);
    }
    // Waiting 60 ms won't hurt any one
    delay(60);
}

void loop() {
   int statusSensor=digitalRead(IRSensor);
    //Servo
    if(statusSensor== HIGH)
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
       delay(3000);   //Delay the next time someone can get soap
    }                 
}
