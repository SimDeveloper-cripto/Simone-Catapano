#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C schermo(0x27,20,4);

void setup(){
  Serial.begin(9600); 
  pinMode(13, OUTPUT); 
  schermo.init();
  schermo.backlight();
  myservo.attach(11);
  myservo.write(90);
}
void loop(){
  char COMANDO = Serial.read();

  if (COMANDO == 'a' || COMANDO == 'A'){
    myservo.write(180);
    schermo.setCursor(0,1);
    schermo.print("SINISTRA");
    delay(1500);
    schermo.clear();
    // digitalWrite(13, HIGH); 
  } else if (COMANDO == 's' || COMANDO == 'S'){
    myservo.write(90);
    schermo.setCursor(0,1);
    schermo.print("DESTRA");
    delay(1500);
    schermo.clear();
    // digitalWrite(13, LOW); 
  } else {
    Serial.print("ERRORE DI INSERIMENTO!");
  }
}
