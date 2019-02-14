#include <Servo.h> 
 
Servo myservo; 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object 
} 
 
 
void loop() 
{ 
// If you are using a normal 180-degree servo, try the following. 
// The code below sweeps the servo from 0 degrees to 180 degrees
// If you notice that your servo is "trashing" when it reaches the ends of its travel
// path, increase the low end by a little (say, make it 10 degrees) and decrease the 
// top end by a little (say, make it 170 degrees).
//for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo1.write(pos);              // tell servo 1 to go to position in variable 'pos'
////    myservo2.write(pos);              // tell servo 2 to go to position in variable 'pos'
//    delay(5);                       // waits 5ms for the servo to reach the position
//  }
//for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo1.write(pos);              // tell servo 1 to go to position in variable 'pos'
////    myservo2.write(pos);              // tell servo 2 to go to position in variable 'pos'
//    delay(5);                       // waits 5ms for the servo to reach the position
//  }

// Uncoment the following lines to test your servo's ability to hold a position.
// You can set the position of a servo , and hold it.
  myservo.write(85);  //Servo 1 go to position 85
  delay(500);
  myservo.write(20); //Servo 1 go to position 20
  delay(500);
  myservo.write(170); //Servo 1 go to position 170
  delay(500);
} 
