int sensorPin = A0; // аналоговый вход
int ledPin = 13; // светодиод
int sensorValue = 0; // переменная
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  sensorValue = analogRead(sensorPin);
 // digitalWrite(ledPin, HIGH);
 // delay(sensorValue);
 // digitalWrite(ledPin, LOW);
 // delay(sensorValue);
  Serial.println(sensorValue);
  delay (500);
}
