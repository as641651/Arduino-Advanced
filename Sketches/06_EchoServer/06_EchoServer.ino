
#include <UIPEthernet.h>
// The connection_data struct needs to be defined in an external file.
#include <UIPServer.h>
#include <UIPClient.h>
//#include "DHT.h"
//DHT dht(8, DHT22);

//#include <SPI.h>
//#include <Ethernet.h>


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.
// gateway and subnet are optional:
//byte mac[] = { 
//  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x03 };

byte mac[] = {0x74,0x69,0x69,0x2D,0x30,0x31};
IPAddress ip(192,168,1, 123);
IPAddress gateway(192,168,1, 1);
IPAddress subnet(255, 255,255, 0);

// telnet defaults to port 23
EthernetServer server(23);
boolean gotAMessage = false; // whether or not you got a message from the client yet

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  // start the Ethernet connection:
  Serial.println("Trying to get an IP address using DHCP");
//  if (Ethernet.begin(mac,ip) == 0) {
//    Serial.println("Failed to configure Ethernet using DHCP");
//    // initialize the ethernet device not using DHCP:
//    Ethernet.begin(mac, ip);     // If you want to manually assign an available IP address
//                                                  // to your Arduino, you can use this constructor outside the 
//                                                  // "if" statement.
//  }
  Ethernet.begin(mac,ip);
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
 
}

void loop() {
  // wait for a new client:
  EthernetClient client = server.available();

  // when the client sends the first byte, say hello:
  if (client) {
    if (!gotAMessage) {
      Serial.println("We have a new client");
      client.println("Hello, client!"); 
      gotAMessage = true;
    }

    // read the bytes incoming from the client:
    char thisChar = client.read();
    // echo the bytes back to the client:
    server.write(thisChar);
    // echo the bytes to the server as well:
    Serial.print(thisChar);
  }
}
