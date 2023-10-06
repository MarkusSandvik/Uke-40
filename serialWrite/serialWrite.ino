int redLed = 2;
int greenLed = 3;
int blueLed = 4;
int redState = LOW;
int greenState = LOW;
int blueState = LOW;

byte outputArray[] ={redLed,greenLed,blueLed};

void startUpMessage(){
  Serial.println("Here are available commands:");
  Serial.println("R - Turns on red Led");
  Serial.println("G - Turns on green Led");
  Serial.println("B - Turns on blue Led");
  Serial.println("X - Turns off all Leds");
} // end void

void setup(){
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  Serial.begin(9600);
  startUpMessage();
} // end void

void loop(){
  serialControl();
} // end void

void serialControl(){
    if (Serial.available() > 0){
        byte inputReading = Serial.read();

        switch (inputReading){
            case 'R':
                redState = !redState;
                digitalWrite(redLed, redState);
                break;
            case 'G':
                greenState = !greenState;
                digitalWrite(greenLed, greenState);
                break;
            case 'B':
                blueState = !blueState;
                digitalWrite(blueLed, blueState);
                break;
            case 'X':
                digitalWrite(redLed, LOW);
                digitalWrite(greenLed, LOW);
                digitalWrite(blueLed, LOW);
                break;
            default:
                startUpMessage();
        } // end switch
    } // end if
} // end void

  
    