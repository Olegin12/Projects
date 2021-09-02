int led = 13 ;// define LED Interface
int sensorObstaclesPin = 10; // назначение пина для датчика
int value ;// переменная для значения с датчика
void setup ()
{
  pinMode (led, OUTPUT) ; 
  pinMode (sensorObstaclesPin, INPUT); 
}
void loop ()
{
  value = digitalRead (sensorObstaclesPin) ;// чтение значения с датчика
  if (value == LOW) // когда датчик определил препятсвие светодиод горит
  {
    digitalWrite (led, HIGH);
  }
  else
  {
    digitalWrite (led, LOW);
  }
}
