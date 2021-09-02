#include <Wire.h>                       // библиотека для протокола I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для LCD 1602
#include <DHT.h>                         // подключаем библиотеку для датчика

LiquidCrystal_I2C LCD(0x27,16,2);  // присваиваем имя LCD для дисплея
DHT dht(2, DHT11);                          // сообщаем на каком порту будет датчик

void setup() {
   LCD.begin();            // инициализация LCD дисплея
   LCD.backlight();  // включение подсветки дисплея
   dht.begin();         // запускаем датчик DHT11
}

void loop() {
   // считываем температуру (t) и влажность (h)
   float h = dht.readHumidity();
   float t = dht.readTemperature();

   // выводим температуру (t) и влажность (h) на жк дисплей
   LCD.setCursor(0,0);
   LCD.print("Humidity:");
   LCD.print(h);

   LCD.setCursor(0,1);
   LCD.print("Temp:");
   LCD.print(t);

   delay(1000);
   LCD.clear();
}
