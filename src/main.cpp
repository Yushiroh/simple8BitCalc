#include <Arduino.h>

//alpha code wa


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

int ans[5] =   {0,0,0,0,0};
int carry[5] = {0,0,0,0,0};
int varA[5] =  {0,0,0,0,0};
int varB[5] =  {0,0,0,0,0};

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

void loop(){

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
      digitalWrite(ledStore2, HIGH);

    }else if(var1State && var2State == true){

      digitalWrite(ledStore1, LOW);
      digitalWrite(ledStore2, LOW);

      var1State = false;
      var2State = false;

      for (size_t i = 0; i < 4; i++)
      {
        varA[i+1] = var1[i];
        varB[i+1] = var2[i];
        ans[i] = 0;
      } 
      
      for (size_t i = 0; i < 5; i++)
      {
        Serial.print("Value of VarA ");
        Serial.print(varA[i]);
        Serial.print(" - in index: ");
        Serial.println(i);
      }

      Serial.println("---------");

      for (size_t i = 0; i < 5; i++)
      {
        Serial.print("Value of VarB ");
        Serial.print(varB[i]);
        Serial.print(" - in index: ");
        Serial.println(i);
      }
      

      for (int i = 4; i > -1; i--){

        if(carry[i] == 1){

            if((carry[i] ^ varA[i]) == 1){

              varA[i] = 1;

            }else if(carry[i] && varA[i] == 1){

              carry[i-1] = 1;
              varA[i] = 0;

            }else{

              varA[i] = 0;

            }

            if((varA[i] ^ varB[i]) == 1){

              ans[i] = 1;

            }else if(varA[i] && varB[i] == 1){

              carry[i-1] = 1;
              ans[i] = 0;

            }else{

              ans[i] = 0;
              
            }

        }else{

            if((varA[i] ^ varB[i]) == 1){

              ans[i] = 1;

            }else if(varA[i] && varB[i] == 1){

              carry[i-1] = 1;
              ans[i] = 0;

            }else{

              ans[i] = 0;
              
            }
        }

        Serial.print("ans for index ");
        Serial.print(i);
        Serial.print(":");
        Serial.print(ans[i]);
        Serial.print(" - carry: ");
        Serial.println(carry[i]);  
       
        for(int ledPos = 0; ledPos < 5; ledPos++){
          
          Serial.print("Index: ");
          Serial.print(ledPos);

          if(ans[ledPos] == 1){
            digitalWrite(leds[ledPos], HIGH);
            Serial.print("led on:");
            Serial.println(leds[ledPos]);
          }else{
            digitalWrite(leds[ledPos], LOW);
            Serial.print("led off:");
            Serial.println(leds[ledPos]);
          }

        } 

      }
      
      for (size_t i = 0; i < 5; i++)
      {
        varA[i] = 0;
        carry[i] = 0;
      }
       

      delay(10000);
    }

  }else{
    
    digitalWrite(leds[0], LOW);

    for(int ledPos = 0; ledPos < 4; ledPos++){
      if(inputStates[ledPos] == 1){
        digitalWrite(leds[ledPos+1], HIGH);
      }else{
        digitalWrite(leds[ledPos+1], LOW);
      }
    }



  }

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


