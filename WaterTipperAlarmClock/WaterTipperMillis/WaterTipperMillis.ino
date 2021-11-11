#include <Servo.h>
#include <LiquidCrystal.h>
int serPin = 5;
float serVal=0;
int potPin = A0;
int potVal;
int lightSensPin=A1;
int lightSensVal;
int upSwitchPin = 7, downSwitchPin = 6;
int RS=2,E=3,D4 = 8, D5=9,D6=10,D7=12; 
int piezoPin=11;

int prevMillisVal =0;
Servo ser;
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(upSwitchPin, INPUT);
pinMode(downSwitchPin, INPUT);
pinMode(piezoPin,OUTPUT);
ser.attach(serPin);
lcd.begin(16,2);

}

void loop() {
  int millisVal = millis();
  while(millisVal < prevMillisVal + 1000){
    // do nothing
  }
  prevMillisVal = millisVal;
  lcd.clear();
  lcd.print(prevMillisVal);

  
  // put your main code here, to run repeatedly:
//potVal = analogRead(potPin);
//serVal = (potVal * 180.) / 1023.;
//Serial.print(potVal);
//Serial.print("\t");
//Serial.print(serVal);

//Serial.print("\t");

lightSensVal = analogRead(lightSensPin);
Serial.print(lightSensVal);
Serial.print("\t\t");
Serial.print(digitalRead(upSwitchPin));
Serial.print("\t");
Serial.print(digitalRead(downSwitchPin));
Serial.print("\t");
//
if(digitalRead(upSwitchPin)){
  serVal = 0;
  lcd.clear();
  lcd.print("Sweet Dreams");
  analogWrite(piezoPin,0);
}
else if(digitalRead(downSwitchPin) || lightSensVal >= 700){
  serVal=130;
  lcd.clear();
  lcd.print("Wake Up");
  analogWrite(piezoPin,20);
}


Serial.println(serVal);
ser.write(serVal);
//delay(10);


}
