#define LASER 8 // задаем имя для Pin10

void setup() {
   pinMode(LASER, OUTPUT); // инициализируем Pin10 как выход
}

void loop() {
digitalWrite(LASER, HIGH);
//for (int i=0; i<=5; i++) // мигание лазерным светодиодом
  // {
 //     digitalWrite(LASER, HIGH);
 //     delay(500);
  //    digitalWrite(LASER, LOW);
  //    delay(500);
 //  }
   //delay(3000);
}
