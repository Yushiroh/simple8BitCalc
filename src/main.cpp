#include <Arduino.h>

const int ledStore1 = 7;
const int ledStore2 = 8;

const int dip1 = 9;
const int dip2 = 10;
const int dip3 = 11;
const int dip4 = 12;

const int storeBut = 13;

const int led1 = A4;
const int led2 = A3;
const int led3 = A2;
const int led4 = A1;
const int led5 = A0;

int leds[] = {led5,led4,led3,led2,led1};

int bitArray[4];

int var1[4];
int var2[4];

bool var1State = false;
bool var2State = false;

int progState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(ledStore1, OUTPUT);
  pinMode(ledStore2, OUTPUT);

  pinMode(dip1, INPUT);
  pinMode(dip2, INPUT);
  pinMode(dip3, INPUT);
  pinMode(dip4, INPUT);

  pinMode(storeBut, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

}

void loop() {

  int inputStates[] = {digitalRead(dip1), digitalRead(dip2), digitalRead(dip3), digitalRead(dip4)};
  
  int buttonState = digitalRead(storeBut);
  delay(200);
  Serial.print("Program State: ");
  Serial.println(progState);

  if(buttonState == 1){
   
    if(var1State == false && var2State == false){

      var1[0] = inputStates[0];
      var1[1] = inputStates[1];
      var1[2] = inputStates[2];
      var1[3] = inputStates[3];
      
      var1State = true;
      digitalWrite(ledStore1, HIGH);

    }else if(var1State == true && var2State == false){

      var2[0] = inputStates[0];
      var2[1] = inputStates[1];
      var2[2] = inputStates[2];
      var2[3] = inputStates[3];
      
      var2State = true;
      digitalWrite(ledStore1, HIGH);

    }

  }else{
    
    for(int ledPos = 0; ledPos < 4; ledPos++){
      if(inputStates[ledPos] == 1){
        digitalWrite(leds[ledPos], HIGH);
      }else{
        digitalWrite(leds[ledPos], LOW);
      }
   }

   digitalWrite(ledStore1, LOW);
   digitalWrite(ledStore2, LOW);

  }



  // if(progState == 1){
  //   digitalWrite(ledStore1, HIGH);
  //   var1[0] = inputStates[0];
  //   var1[1] = inputStates[1];
  //   var1[2] = inputStates[2];
  //   var1[3] = inputStates[3];

  // }else if(progState == 2){
  //   digitalWrite(ledStore2, HIGH);
  //   var2[0] = inputStates[0];
  //   var2[1] = inputStates[1];
  //   var2[2] = inputStates[2];
  //   var2[3] = inputStates[3];

  // }else if(progState == 3){
  //   progState = 0;

  // }else{
  //   digitalWrite(ledStore1, LOW);
  //   digitalWrite(ledStore2, LOW);
  // }

  Serial.print("var 1 value: ");
  Serial.print(var1[0]);
  Serial.print(var1[1]);
  Serial.print(var1[2]);
  Serial.println(var1[3]);

  Serial.print("var 2 value: ");
  Serial.print(var2[0]);
  Serial.print(var2[1]);
  Serial.print(var2[2]);
  Serial.println(var2[3]);




}


