#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 2     // контакт, к которому подключаемся 
#define DHTTYPE DHT11   // для датчика DHT11
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// создаем экземпляр класса для датчика DHT11: 
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Wire.begin();
  dht.begin(); // инициализируем объект «dht»
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // инициализируем объект «display» с I2C-адресом «0x3C», для 128x32
  Serial.begin(9600);
}
void displayTempHumid(){
  delay(2000);
  // считывание данных о температуре и влажности 
  // занимает около 250 мс; кроме того, это считывание
  // может запаздывать примерно на 2 секунды 
  // (это очень медленный датчик):
  float h = dht.readHumidity();
  // считываем температуру в градусах Цельсия:
  float t = dht.readTemperature();
  // считываем температуру в градусах Фаренгейта:
  float f = dht.readTemperature(true);

  // проверяем, корректны ли данные, и если нет,
  // то выходим и пробуем снова:
  if (isnan(h) || isnan(t) || isnan(f)) {
    display.clearDisplay();  //  очищаем дисплей
    display.setTextColor(WHITE);  //  задаем цвет 
    display.setTextSize(1);  //  задаем шрифт
    display.setCursor(5,0);  //  задаем координаты курсора
    display.print("Failed to read from DHT sensor!");
    //  "Не удалось прочесть данные с датчика DHT!"
    return;
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Humidity: ");  //  "Влажность: "
  display.print(h);
  display.print(" %\t");
  display.setCursor(0,10);
  display.print("Temperature: ");  //  "Температура: "
  display.print(t);
  display.print(" C"); 
  display.setCursor(0,20);
  display.print("Temperature: ");  //  "Температура: " 
  display.print(f);
  display.print(" F"); 
}
void loop()
{
  displayTempHumid();
  display.display();
}
