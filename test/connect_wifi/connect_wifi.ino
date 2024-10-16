/*
  Arduino Nano 33 IoT WiFi Test
  nano-33-iot-wifi-test.ino
  Demonstrates use of WiFiNINA library for WiFi Connectivity
  Results on serial monitor
 
  DroneBot Workshop 2021
  https://dronebotworkshop.com
*/
 
// Include SPI and WiFi Libraries
#include <SPI.h>
#include <WiFiNINA.h>

#include "arduino_secrets.h" 
// WiFi Credentials (edit as required)
char ssid[] = SECRET_SSID;        // Wifi SSID
char pass[] = SECRET_PASS;        // Wifi password
 
int status = WL_IDLE_STATUS;
 
// Initialize the Wifi client
WiFiSSLClient client;
 
void connectToAP() {
  // Connect to Wifi Access Point
  
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
 
    // wait 1 second for connection:
    delay(1000);
    Serial.println("Connected...");
  }
}
 
void printWifiStatus() {
  // Print results to serial monitor  
 
 // Network SSID  
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  
  // Device IP address
  IPAddress ip = WiFi.localIP(); 
  Serial.print("IP Address: ");
  Serial.println(ip);
}
 
void setup() {
  
  // Start the Serial port
  Serial.begin(9600);
  
  while (!Serial) {
    ; // Wait for serial port to connect.
  }
  
  // Check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("WiFi module failed!");
    while (true);
  }
   
  connectToAP();  
    
  printWifiStatus();
  
}
 
void loop() {
}