#define laser 3
#define touch A0
 
void setup(){
    pinMode(touch, INPUT);
    pinMode(laser, OUTPUT);
    Serial.begin(9600);
}
void loop(){
   if (analogRead(touch) < 1000) 
   {
    digitalWrite(laser, HIGH);
   }
    else
    {
     digitalWrite (laser, LOW); 
    }
    delay(10);
}
