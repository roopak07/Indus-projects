#define EN        8  
#define Y_DIR     6
#define Y_STP     3
#define Z_DIR     7
#define Z_STP     4 
//DRV8825
#include<String.h>
#define spin 13 // buzzer pin
#define bpin 12 // button pin
#define ipin2 5  // IR sensor 2 pin
#define ipin1 2  // IR sensor 1 pin
int delayTime=150; //Delay between each pause (uS) ,speed 
int stps=6400;// Steps to move 10000 ,no:of steps
int bval,i,ival2,ival1;// button value

void setup(){
  Serial.begin(9600);
  pinMode(Z_DIR, OUTPUT); 
  pinMode(Z_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); 
  pinMode(Y_STP, OUTPUT);
  pinMode(EN, OUTPUT);
 pinMode(bpin,INPUT);
 pinMode(ipin2,INPUT);
pinMode(spin,OUTPUT);
}
void loop(){
 bval=digitalRead(bpin);
 Serial.println("button value: "+String(bval));
 while(digitalRead(bpin)==1)
 {
  Serial.println("removing plates");
  for (i=0 ; i < 6400; i++) 
  {
  digitalWrite(EN,LOW);// actuating stepper motor, low- on , high-off
  digitalWrite(Z_DIR, false); //direction of stepper motor  
  digitalWrite(Y_DIR, false); //direction of stepper motor 
    
  digitalWrite(Z_STP, HIGH);
  digitalWrite(Y_STP, HIGH);
  delayMicroseconds(delayTime); 
  digitalWrite(Z_STP, LOW);
  digitalWrite(Y_STP, LOW);
  delayMicroseconds(delayTime);
  } 
 }
 ival2=digitalRead(ipin2);
 Serial.println("ival2="+String(ival2));
 
 ival1=digitalRead(ipin1);
 delay(100);// delay for standing at sensor
 Serial.println("ir sensor 1 value: "+String(ival1));
 
 if(ival2==1 || (ival1==1 && ival2==1))
 {
  digitalWrite(EN,HIGH);// actuating stepper motor, low- on , high-off
  Serial.println("Plates are full");
  digitalWrite(spin,HIGH);
 }
 else
 {
  digitalWrite(spin,LOW);
  i=0;
  while(digitalRead(ipin1)==1) // if someone detected
  {
  digitalWrite(EN, LOW); 
  digitalWrite(Z_DIR, true);
  digitalWrite(Y_DIR, true);
   for (i ; i < stps; i++) 
   {  
   digitalWrite(Z_STP, HIGH);
   digitalWrite(Y_STP, HIGH);
   delayMicroseconds(delayTime); 
   digitalWrite(Z_STP, LOW);
   digitalWrite(Y_STP, LOW);
   delayMicroseconds(delayTime);
   }
 }
 }
 }
