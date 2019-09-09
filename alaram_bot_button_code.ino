
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue>600)
  {
    Serial.println("alaram is activated");
  }
  else
  {
    Serial.println("alaram is deactivated");
  }
}
