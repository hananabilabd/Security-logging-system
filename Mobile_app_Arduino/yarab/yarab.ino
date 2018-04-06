//#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
//#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>
//#include <SPI.h>
//#include <Ethernet.h>



//const char* ssid     = "LINKDSL-josephhalim";
//const char* password = "23121973janet";
const char* ssid     = "BME Students Lab 1 (2.4)";
//const char* ssid     = "BME Students (2.4)";
const char* password = "mybmewifi";
//const char ser[] = "192.168.1.2";

int lControl =  13; //Digital pin that LED is connected to on the MKR1000
//char ssid[] = "YourNetwork";      // your network SSID (name)
//char pass[] = "YourPassword";   // your network password
int keyIndex = 0;                 // your network key Index number (needed only for WEP)



WiFiServer server(80);
//WiFiClient client;

void setup() {
 Serial.begin(115200); 
 delay(10);
pinMode(13, OUTPUT);
 
  

  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\rWorking to connect");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.begin();

}


void loop() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
   // Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
       // Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            //client.print("Value at A0 is ");
            //client.print(analogRead(A0));
            client.print("<br>");
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(13, HIGH);               // GET /H turns the LED on
          Serial.println("HIGH");
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(13, LOW);                // GET /L turns the LED off
          Serial.println("LOW");
        }
      }
    }
    // close the connection:
    client.stop();
   // Serial.println("client disconnected");
  }
}



