/*
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10 (for MKRZero SD: SDCARD_SS_PIN)
 */
#include <SPI.h>
#include <SD.h>
File myFile;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //pinMode(8, INPUT);
  //pinMode(9, INPUT);
  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {Serial.println("initialization failed!");return;}
  Serial.println("initialization done.");

}


void loop() {
//if ((digitalRead(9) == HIGH)&& !(digitalRead(8)==HIGH)){writememory();}
//if ((digitalRead(8) == HIGH)&& !(digitalRead(9)==HIGH)){readmemory();}
readmemory();
  //writememory();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readmemory(){
    // re-open the file for reading:
  myFile = SD.open("test2.txt");
  if (myFile) {
    //Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());}
   
    myFile.close();} 
    else {Serial.println("error opening test.txt");}
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void writememory(){
  delay(1000);
  String dataString = "";

  float r1 = analogRead(A2);float v1 = r1 * (3.3 / 1023.0);
  float r2 = analogRead(A3);float v2 = r1 * (3.3 / 1023.0);
  float r3 = analogRead(A4);float v3 = r1 * (3.3 / 1023.0);


dataString= "Temperature:" + String(v1)+ "V ," + "Pressure :" + String(v2)+"V ," + "Humidity:"+999+"V" ;
  

   File myFile = SD.open("test2.txt", FILE_WRITE);

  if (myFile) {
    //Serial.print("Writing to test.txt...");
    myFile.println(dataString);
    myFile.close();
    Serial.println(dataString);
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");}
    }

