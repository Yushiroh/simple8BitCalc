#include <Arduino.h>

int var1;
int var2;

int carry[5] = {0,0,0,0,0};
int varA[5] =  {0,1,0,1,0};
int varB[5] =  {0,1,1,1,1};
int ans[5] =   {0,0,0,0,0};


void setup() {
  Serial.begin(9600);
}

void loop() {

  delay(3000);

  for (int i = 4; i > -1; i--)
  {

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
    
  } 

}

