double alpha = 0.75;
int period = 100;
double change = 0.0;
double minval = 0.0;

void setup() {
    Serial.begin(9600);
    pinMode(A1, INPUT);
}

void loop() {
     static double oldValue = 0;
     static double oldChange = 0;
     int rawValue = analogRead(A1);
     double value = alpha * oldValue + (1 - alpha) * rawValue;
     Serial.print (rawValue);
     Serial.print (",");
     Serial.println (value);
     oldValue = value;
     delay(period);
}
