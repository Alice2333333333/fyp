#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h"

// Wi-Fi® information
char ssid[] = SECRET_SSID;        
char pass[] = SECRET_PASS;
WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

// MQTT broker information

const char broker[] = "192.168.100.10";
int        port     = 1883;
const char topic[]  = "test";

// Interval for sending messages (in milliseconds) to the MQTT broker
const long interval = 5000;
unsigned long previousMillis = 0;

// Data to send to the MQTT broker
int count = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect, needed for native USB port only
  }

  // Attempt to connect to the defined Wi-Fi® network
  Serial.print("- Attempting to connect to WPA SSID: ");
  Serial.println(ssid);

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // Connection attempt failed, retry again
    Serial.print(".");
    delay(5000);
  }

  Serial.println("- You're connected to the network!");
  Serial.println();
  
  // Attempt to connect to the defined Wi-Fi® network
  Serial.print("- Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  // Connection attempt to the MQTT broker failed
  if (!mqttClient.connect(broker, port)) {
    Serial.println("- MQTT connection failed!");
    Serial.print("- Error code: ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("- You're connected to the MQTT broker!");
  Serial.println();
}

void loop() {
  // Keep the board connected to the MQTT broker
  mqttClient.poll();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Send the gathered data to an specific topic of the MQTT broker
    previousMillis = currentMillis;

    Serial.print("Sending message to topic: ");
    Serial.println(topic);
    
    // Detect vibration value
    int vibration_val;
    vibration_val = analogRead(0); // connect to analog pin 0
    Serial.println(vibration_val, DEC);
    mqttClient.beginMessage(topic);
    mqttClient.print(vibration_val);
    mqttClient.endMessage();
    Serial.println();
    delay(1000);
  }
}