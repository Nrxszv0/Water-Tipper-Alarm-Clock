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
int piezoVal =0;

int timerVal = 28800;
Servo ser;
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
String lcdR1 ="", lcdR2 ="";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(upSwitchPin, INPUT);
pinMode(downSwitchPin, INPUT);
pinMode(piezoPin,OUTPUT);
ser.attach(serPin);
lcd.begin(16,2);
  lcdR1 = "Sweet Dreams";
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currTime = millis() / 1000;
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

if(digitalRead(upSwitchPin)){
  serVal = 0;
  lcdR1 = "Sweet Dreams";
  piezoVal = 0;

}
else if(digitalRead(downSwitchPin) || lightSensVal >= 800 || currTime == timerVal){
  serVal=130;
  lcdR1 = "Wake Up";
  piezoVal = 20;
}

Serial.println(serVal);
ser.write(serVal);
lcd.clear();
lcd.print(lcdR1);
lcd.setCursor(0,1);
lcd.print(timeFormat(timerVal-currTime));
analogWrite(piezoPin, piezoVal);
delay(10);


}
String timeFormat(unsigned long seconds){
  int hour = seconds / 3600;
  String sH = String(hour);
  int minute = (seconds % 3600) / 60;
  String sM = String(minute);
  int second = seconds % 60;
  String sS = String(second);
  return sH + ":" + sM+ ":" + sS;
}
