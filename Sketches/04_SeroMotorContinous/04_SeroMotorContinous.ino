#include <Servo.h> 

Servo myservo;             // create servo object to control a servo 
                           // a maximum of eight servo objects can be created 

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 

void loop() 
{ 
// Uncomment the following lines, one at a time, to see the effect that each one
// has on the speed and direction of a continuous rotation servo.

//  myservo.write(90);    // At this position, the servo does not move. 90 degrees is the resting value
 myservo.write(100);   // At this position, the servo will move slowly clockwise
//  myservo.write(145);   // At this position, the servo will move faster clockwise
//  myservo.write(180);   // At this position, the servo will move at max speed clockwise
//  myservo.write(80);    // At this position, the servo will move at slowly anti-clockwise
//  myservo.write(70);    // At this position, the servo will move at faster anti-clockwise
//  myservo.write(0);     // At this position, the servo will move at max speed anti-clockwise
}
