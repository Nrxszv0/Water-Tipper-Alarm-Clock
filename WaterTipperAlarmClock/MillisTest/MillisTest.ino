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

unsigned long prevTime =0;
unsigned long timerDoneVal = 10000;
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

  
unsigned long currTime= millis();

if(currTime - prevTime>= 1000){
  lcd.clear();
  lcd.print(currTime);
  lcd.setCursor(0,1);
  lcd.print(timerDoneVal);
  prevTime = currTime;
  
}

if(digitalRead(upSwitchPin)){
  timerDoneVal += currTime;
}

if(currTime >= timerDoneVal){
  lcd.print("timer done");
  timerDoneVal += currTime;
}
}
