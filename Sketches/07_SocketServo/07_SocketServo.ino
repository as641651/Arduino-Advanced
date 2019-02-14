
#include <UIPEthernet.h>
// The connection_data struct needs to be defined in an external file.
#include <UIPServer.h>
#include <UIPClient.h>
#include <Servo.h>

Servo myservo;
// servo position is calibrated between 21-180 for my servo
int pos = 21;
float t_speed = 5; 

byte mac[] = {0x74,0x69,0x69,0x2D,0x30,0x31};
IPAddress ip(192,168,1, 123);
IPAddress gateway(192,168,1, 1);
IPAddress subnet(255, 255,255, 0);

// telnet defaults to port 23
EthernetServer server(23);
//EthernetClient ethClient;
boolean gotAMessage = false; // whether or not you got a message from the client yet

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  // start the Ethernet connection:
  Serial.println("Trying to get an IP address using DHCP");
  Ethernet.begin(mac, ip);    
  
  // print your local IP address:
  Serial.print("My IP address: ");
  ip = Ethernet.localIP();
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(ip[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println();
  // start listening for clients
  server.begin();

  // attach servo
  myservo.attach(3);
  delay(100);
  myservo.write(pos);
  
}

String currentVal = "";

void loop() {
  // wait for a new client:
  EthernetClient client = server.available();

  // when the client sends the first byte, say hello:
  float tilt;
  if (client) {
    if (!gotAMessage) {
      Serial.println("We have a new client");
      //client.println("Hello, client!"); 
      gotAMessage = true;
    }

    // read the bytes incoming from the client:
    char thisChar = client.read();
    //Serial.print(thisChar);
    if(thisChar == 'P' || thisChar == 'E'){
      // check if end of value is reached
      Serial.println();
      if(currentVal[0] == '-'){ 
        if(currentVal[1]>='3'){
          // update position if sensor value is greater than a threshold
          pos+=1*t_speed;
          // position is calibrated between 21-180 for my servo
          if(pos>180)
            pos=180;
          if(pos <21)
            pos=21;
          myservo.write(pos);
          Serial.println("Left");
        }
      }else{
        if(currentVal[0]>='3'){
          // update position if sensor value is greater than a threshold
          pos-=1*t_speed;
          // position is calibrated between 21-180 for my servo
          if(pos>180)
            pos=180;
          if(pos<21)
            pos = 21;
          myservo.write(pos);
          Serial.println("Right");
        }
      }
      Serial.println(pos);
      Serial.println(currentVal);
      //reset current value
      currentVal = "";
    }else{
      // if end of value is not rached, keep reading
      currentVal+=thisChar;
    }
  } 
}
