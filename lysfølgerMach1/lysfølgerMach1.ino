#include <Servo.h>

Servo verticalServo;
Servo horisontalServo;

const int verticalServoPin = 9;
const int horisontalServoPin = 10;
const int t = 1000;
const int lightSensor1 = A2;
const int lightSensor2 = A3;
const int lightSensor3 = A4;
const int lightSensor4 = A5;

byte inputArray[] = {lightSensor1, lightSensor2, lightSensor3, lightSensor4};

int verticalValue = 90;
int horisontalValue = 90;
int adjustment = 2;

unsigned long previousMillis = 0;
const long interval = 10;

void setup(){
    for (int i = 0; i < sizeof(inputArray); i++){
      pinMode(inputArray[i], INPUT);
    } // end for
    verticalServo.attach(9);
    horisontalServo.attach(10);
    Serial.begin(9600);
}

void loop(){
    potmeterControl();
}

void potmeterControl(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval){
    int upLeft = analogRead(lightSensor1);
    int upRight = analogRead(lightSensor2);
    int downLeft = analogRead(lightSensor3);
    int downRight = analogRead(lightSensor4);

    upLeft = map(upLeft, 0, 1023, 0, 100);
    upRight = map(upRight, 0, 1023, 0 , 100);
    downLeft = map(downLeft, 0 ,1023, 0, 100);
    downRight = map(downRight, 0, 1023, 0 ,100);
    
    if (upLeft > downLeft){
      if (upLeft > upRight){
        if (upLeft - upRight > 5){
          horisontalValue += adjustment;
        } // end if
      } // end if
      else if (upLeft < upRight){
        if (upRight-upLeft > 5){
          horisontalValue -= adjustment;
        } // end if
      } // end if
    }
    else if (upLeft < downLeft){
      if (downLeft > downRight){
        if (downLeft - downRight > 5){
          horisontalValue += adjustment;
        } // end if
      } // end if
      else if (downLeft < downRight){
        if (downRight-downLeft > 5){
          horisontalValue -= adjustment;
        } // end if
      } // end if
    }
    
    if (upLeft > upRight){
      if (upLeft > downLeft){
        if (upLeft - downLeft > 5){
          verticalValue -= adjustment;
        } // end if
      } // end if

      if (upLeft < downLeft){
        if (downLeft - upLeft > 5){
          verticalValue += adjustment;
        } // end if
      } // end if
    } // end if

    if (upLeft < upRight){
      if (upRight > downRight){
        if (upRight - downRight > 5){
          verticalValue -= adjustment;
        } // end if
      } // end if

      if (upRight < downRight){
        if (downRight - upRight > 5){
          verticalValue += adjustment;
        } // end if
      } // end if

    }


    if (horisontalValue > 180){
      horisontalValue = 180;
    } // end if
    if (horisontalValue < 0){
      horisontalValue = 0;
    } // end if
    if (verticalValue > 180){
      verticalValue = 180;
    } // end if
    if (verticalValue < 0){
      verticalValue = 0;
    } // end if


    verticalServo.write(verticalValue);
    horisontalServo.write(horisontalValue);

    previousMillis = currentMillis;
  } // end if
} // end void