
int sensorObstaclesPin = 10; // назначение пина для датчика
int digital ;// переменная для значения с датчика
void setup ()
{
  pinMode (sensorObstaclesPin, INPUT); 
  Serial.begin(9600);
}
void loop ()
{
  digital = digitalRead (sensorObstaclesPin) ;// чтение значения с датчика
  Serial.print("Digital: ");
  Serial.print(digitalRead(digital));
  delay(500);
}
