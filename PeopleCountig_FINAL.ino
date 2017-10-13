#include "SevSeg.h"


byte numDigits = 4;

byte digitPins[] = { 6,9,10,11};

byte segmentPins[] = {13, 12, 8, 7, 5, 4, 3, 2};


int thresehold1=70;
int thresehold2=950;

SevSeg sevseg;

int ldr1=A0;
int ldr2=A1;
int count=0;

const int resetPin = A2;



boolean firstGate=false;
boolean secondGate=false;

void setup() {
  // put your setup code here, to run once:
pinMode(ldr1,INPUT);
pinMode(ldr1,INPUT);

pinMode(resetPin, INPUT);

Serial.begin(19200);

sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);

sevseg.setBrightness(90);

sevseg.setNumber(0000, 4);

delay(2000);
Serial.println("Let's start counting the no of people");
}



void loop() {
  // put your main code here, to run repeatedly:
ldrReading();
countingPeople();
checkReset();
sevseg.setNumber(count, 4);

sevseg.refreshDisplay();

}



void show(){
  Serial.print("Total number of People in the room");
  Serial.print("  :  "); 
  Serial.println(count);
}

void countingPeople(){
  if(secondGate==false&&firstGate==true){

   while(secondGate==true){
        Serial.println("it came to gate1");
    }
    
  count++;
  show();
  delay(500);
   
  }
   else if(firstGate==false&&secondGate==true){

    while(firstGate==true){
        Serial.println("it came to gate2");
    }
  count--;
    if(count<0)count=0;
  show();
   delay(500);
    }
   

  
}

void ldrReading(){
  int val1=analogRead(ldr1);

int val2=analogRead(ldr2);

if(val1<=thresehold1){
  firstGate=true;

}
else{
firstGate=false;
}

if(val2<=thresehold2){
  secondGate=true;
 
}
else{
secondGate=false;
}
}

void checkReset(){
  if(digitalRead(resetPin)==HIGH){
    delay(200);
    count=0;
    show();
  }
}


