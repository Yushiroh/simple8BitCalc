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

int leds[] = {led1,led2,led3,led4,led5};

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

  for(int ledPos = 0; ledPos < 4; ledPos++){

    if(inputStates[ledPos] == 1){
      digitalWrite(leds[ledPos], HIGH);
    }else{
      digitalWrite(leds[ledPos], LOW);
    }
  }

}


