#include<LiquidCrystal_I2C.h>
#include<Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo ser;
int val;
unsigned long previousMillis = 0;   
void setup() {
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  ser.attach(9);
  pinMode(A0,OUTPUT);
  pinMode(A2,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("Karya Solderanku");
  lcd.setCursor(0,1);
  lcd.print("Yuk Subscribe");
}

void loop() {
  digitalWrite(A0,0);
  digitalWrite(A2,1);
  val = analogRead(A1);            
  val = map(val, 0, 1023, 0, 180); 
  ser.write(val);
  String text= "Servo Write: " + String(val);
  Serial.println(text);
  lcd.setCursor(0,1);
  lcd.print(text);  
  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 300) {
    lcd.clear();
    previousMillis = currentMillis;
  }
}
