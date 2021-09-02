int led = 13 ;// встроенный в адуино светодиод
int vibrationSensor = 8; // пин для подлкючения вибродатчика
int value; // переменная состояния датчика
void setup ()
{
  pinMode (led, OUTPUT) ; 
  pinMode (vibrationSensor, INPUT) ; // назначение входа для датчика
}
void loop ()
{
  value = digitalRead (vibrationSensor) ; // чтение состояния датчика
  if (value == HIGH) // когда сенсор определяет вибрацию, светодиод загорается 
  {
    digitalWrite (led, LOW);
  }
  else
  {
    digitalWrite (led, HIGH);
  }
}
