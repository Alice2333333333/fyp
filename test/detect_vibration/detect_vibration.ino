void setup() {
  Serial.begin(9600);
}

void loop() {
  int vibration_val;
  vibration_val = analogRead(0); // connect to analog pin 0
  Serial.println(vibration_val, DEC);
  delay(1000);
}