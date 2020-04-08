#include <Stepper.h>
#include <Servo.h>

Servo servo;  
Servo servoLeft;
//Servo servoRight;
int servoAngle = 0;

void setup() {
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  servo.attach(4);
  servoLeft.attach(7);
  //servoRight.attach(8);
  int speed = 0;
}


void loop() {

char btData = Serial.read();
servo.write(90);


erial.print(btData);
digitalWrite(12, HIGH);

switch (btData)
{
  case 'f':                      // НАПРЕД
        servoLeft.write(0); //моторите са обърнати един срещу друг => за да се движи роботът напред (и двата мотора се движат напред), трябва посоката на оста на единия мотор да е противоположна на другия (те са огледални)
        //servoRight.write(180);
        delay(1000);
        servoLeft.write(90);
        //servoRight.write(90);
    break;
   case 'b':                    // НАЗАД
    for(int i=0;i<=300; i++)
    {
   
      delay(1);
    }
    break;
   case 'l':                    // ЛЯВО
    for(int i=0;i<=300; i++)
    {
      
      delay(1);
    }
    break;
   case 'r':                   // ДЯСНО
    for(int i=0;i<=300; i++)
    {
    
      delay(1);
    }
    break;
   case 'n':
    digitalWrite(12, HIGH);    // laser ON
    break;
   case 'm':
    digitalWrite(12, LOW);     // laser OFF
    break;
   case 'c':
    servo.write(90);           // center position - closed
    delay(1000);  
    break;
   case 'o':
    servo.write(40);           // open
    delay(1000);
    break;
   default: 
    break; 
}


}
