/*
Homeyduino 2.1 universeel 433Mhz RF script
Codes you can learn from the 433Mhz_sniffer script.
The Script is made with a Arduino Uno and a Ethernet Shield.
YOu can send a trigger from Homey (Athom) to the Homeyduino (Arduino)

In Het Homey the is the next flow in use : If - This flow is started / Then - Homeydruino action [number] card.
With the nubers you can trigger the RF codes.
*/

#include <SPI.h>
#include <Ethernet.h>
#include <Homey.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
};

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

unsigned long previousMillis = 0;
const unsigned long interval = 1000; //Interval in milliseconds

void setup() {
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  
  //Enable serial port
  Serial.begin(115200);
 
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  
Serial.println("Starting ethernet...");
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for (;;)
      ;
  }
  
 Homey.begin("Homeyduino 2");
  /* Note:
   * The name of each Arduino on the network needs to be unique
   * since it will be used as the unique identifier for your device.
   * The name is stored as a String and can thus be as long as you
   * desire it to be.
   */
  
  //Register an example action
  Homey.addAction("Prikkabel", onExampleAction);

  Serial.println("Homeyduino Started...");
}

void loop() {
 
  Homey.loop();
  /* Note:
   *  The Homey.loop(); function needs to be called as often as possible.
   *  Failing to do so will cause connection problems and instability.
   *  Avoid using the delay function at all times. Instead please use the
   *  method explaind on the following page on the Arduino website:
   *  https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
   */
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;    
  }
}

//example action
void onExampleAction() {
  //Read the argument sent from the homey flow
  String value = Homey.value;


  //And print it to the serial terminal

  Serial.print("Example action: Trigger! : ");

  /* Buitenverlichting */
  
  if (value == "1"){
  Serial.print("nummer 1 :");
  Serial.println("Aan");
  mySwitch.send("111001000001011100000001");
  delay(200);
  }
  else {  }

  if (value == "2"){
  Serial.print("nummer 2 :");
  mySwitch.send("111001000001011100000011");
  Serial.println("Uit");
  delay(200);
  }
  else {  }

  if (value == "3"){
  Serial.print("nummer 3 :");
  Serial.println("0.5 H");
  mySwitch.send("111001000001011100000001");
  delay(200);
  }
  else {  }

  if (value == "4"){
  Serial.print("nummer 4 :");
  mySwitch.send("111001000001011100000011");
  Serial.println("1 H");
  delay(200);
  }
  else {  }

  if (value == "5"){
  Serial.print("nummer 5 :");
  Serial.println("2 H");
  mySwitch.send("111001000001011100000001");
  delay(200);
  }
  else {  }

  if (value == "6"){
  Serial.print("nummer 6 :");
  mySwitch.send("111001000001011100000011");
  Serial.println("4 H");
  delay(200);
  }
  else {  }

  if (value == "7"){
  Serial.print("nummer 7 :");
  Serial.println("25%");
  mySwitch.send("111001000001011100000001");
  delay(200);
  }
  else {  }

  if (value == "8"){
  Serial.print("nummer 8 :");
  mySwitch.send("111001000001011100000011");
  Serial.println("50%");
  delay(200);
  }
  else {  }

  if (value == "9"){
  Serial.print("nummer 9 :");
  Serial.println("75%");
  mySwitch.send("111001000001011100000001");
  delay(200);
  }
  else {  }

  if (value == "10"){
  Serial.print("nummer 10 :");
  mySwitch.send("111001000001011100000011");
  Serial.println("100%");
  delay(200);
  }
  else {  }

  if (value == "11"){
  Serial.print("nummer 11 :");
  Serial.println("Dimmen -");
  mySwitch.send("111001000001011100000001");
  delay(200);
  }
  else {  }

  if (value == "12"){
  Serial.print("nummer 12 :");
  mySwitch.send("111001000001011100000011");
  Serial.println("Dimmen +");
  delay(200);
  }
  else {  }
}
