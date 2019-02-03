#include <Servo.h> 
 
Servo myservo1, myservo2;  // create servo object to control a servo 
                           // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(10);
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
  myservo1.write(85);  //Servo 1 go to position 85
  myservo2.write(110); //Servo 2 go to position 85
  delay(500);
  myservo1.write(20); //Servo 1 go to position 20
  myservo2.write(10); //Servo 2 go to position 10
  delay(500);
  myservo1.write(170); //Servo 1 go to position 170
  myservo2.write(160); //Servo 2 go to position 20
  delay(500);
} 
