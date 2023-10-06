#include <Servo.h>

Servo verticalServo;
Servo horisontalServo;

const int verticalServoPin = 9;
const int horisontalServoPin = 10;
const int t = 1000;


const int potmeterVertical = A0;
const int potmeterHorisontal = A1;



void setup(){
    verticalServo.attach(9);
    horisontalServo.attach(10);
    pinMode(potmeterVertical, INPUT);
    pinMode(potmeterHorisontal, INPUT);
    Serial.begin(9600);

}

void loop(){
    potmeterControl();

}

void potmeterControl(){
    int verticalControl = analogRead(potmeterVertical);
    int horisontalControl = analogRead(potmeterHorisontal);
    int verticalValue = map(verticalControl, 0, 1023, 0 , 180);
    int horisontalValue = map(horisontalControl, 0, 1023, 0, 180);
    //Serial.println(verticalValue);
    //Serial.println(horisontalValue);
    verticalServo.write(verticalValue);
    horisontalServo.write(horisontalValue);


}