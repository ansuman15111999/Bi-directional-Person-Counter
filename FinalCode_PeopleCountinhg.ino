// This code is without the using Sevseg.h library counts to number of people


 int sensA=0;

int sensB=0;

int thresehold1=95;
int thresehold2=1000;


int counT=0,newCount=0,backCount=0,frontCount=0;

int ldr1=A0;
int ldr2=A1;

int count=0;

int resetPin = A2;



boolean firstGate=false;
boolean secondGate=false;
int digit1 = 6; //PWM Display pin 1
int digit2 = 9; //PWM Display pin 2
int digit3 = 10; //PWM Display pin 6
int digit4 = 11; //PWM Display pin 8

int segA = 13; //Display pin 14
int segB = 12; //Display pin 16
int segC = 8; //Display pin 13
int segD = 7; //Display pin 3
int segE = 5; //Display pin 5
int segF = 4; //Display pin 11
int segG = 3; //Display pin 15



void setup() {                
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  
  pinMode(resetPin, INPUT);
Serial.begin(9600);
}

void loop() {
  ldrReading();
countingPeople();
checkReset();
  displayNumber(count);
 
}




void displayNumber(int toDisplay) {
#define DISPLAY_BRIGHTNESS  400

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  long beginTime = millis();

  for(int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch(digit) {
    case 1:
      digitalWrite(digit1, DIGIT_ON);
      break;
    case 2:
      digitalWrite(digit2, DIGIT_ON);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      break;
    }

    //Turn on the right segments for this digit
    lightNumber(toDisplay % 10);
    toDisplay /= 10;

    delayMicroseconds(DISPLAY_BRIGHTNESS); 
   //    lightNumber(10); 

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
  }

//  while( (millis() - beginTime) < 3) ; 
 
}


void lightNumber(int numberToDisplay) {

#define SEGMENT_ON  LOW
#define SEGMENT_OFF HIGH

  switch (numberToDisplay){

  case 0:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 1:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 2:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_OFF);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 3:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 4:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 5:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 6:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 7:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 8:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 9:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 10:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_OFF);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;
  }
}







void show(){
  Serial.print("Total number of People in the room");
  Serial.print("  :  "); 
  Serial.println(count);
}

void countingPeople(){

//  if(secondGate==false&&firstGate==true){
//  count++;
//  show();
//  delay(1);
//   
//  }
//  
//   if(firstGate==false&&secondGate==true){
//   count--;
//   if(count<0)count=0;
//   show();
//   delay(1);
//    }
 if(firstGate==true){
  counT=1;  
  frontCount=1;
  if(backCount==1)frontCount=0;
 }
 if(secondGate==true){
  newCount=1;
   backCount=1;
   if(frontCount==1)backCount=0;
 }
 
 
 Serial.print("Count : ");
 Serial.println(counT);
 Serial.print("newCount : ");
 Serial.println(newCount);

 
 if(counT==1&&frontCount==1){
  if(newCount==1){
    Serial.println("front");
   count++;
  show();
  for(int f=0;f<=100;f++)
  displayNumber(count);
  //delay(1000);
   counT=0;
   frontCount=0;
    newCount=0;
   backCount=0;
   }
 }

 
 if(newCount==1&&backCount==1){
  if(counT==1){
 Serial.println("back");
    count--;
    if(count<0){count=0;}
  show();
   for(int f=0;f<=100;f++)
  displayNumber(count);
//  delay(1000);
   newCount=0;
   backCount=0;
    counT=0;
   frontCount=0;
  }
 }
}

void ldrReading(){
  sensA=analogRead(ldr1);

 sensB=analogRead(ldr2);

if(sensA<=thresehold1){
  firstGate=true;

}
else{
firstGate=false;
}

if(sensB<=thresehold2){
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

