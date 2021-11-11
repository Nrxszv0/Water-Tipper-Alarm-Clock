#include <Servo.h>
int serPin = 5;
float serVal=0;
int potPin = A0;
int potVal;
int upSwitchPin = 7, downSwitchPin = 6;
Servo ser;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(upSwitchPin, INPUT);
pinMode(downSwitchPin, INPUT);

ser.attach(serPin);
}

void loop() {
  // put your main code here, to run repeatedly:
//potVal = analogRead(potPin);
//serVal = (potVal * 180.) / 1023.;
//Serial.print(potVal);
//Serial.print("\t");
//Serial.print(serVal);

//Serial.print("\t");

Serial.print(digitalRead(upSwitchPin));
Serial.print("\t");
Serial.print(digitalRead(downSwitchPin));
Serial.print("\t");
if(digitalRead(upSwitchPin)){
  serVal = 0;
}
else if(digitalRead(downSwitchPin)){
  serVal=130;
}

Serial.println(serVal);
ser.write(serVal);
delay(10);


}
