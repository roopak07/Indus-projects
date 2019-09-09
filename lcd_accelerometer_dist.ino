#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include<string.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 coloums ,2 rows 16*2 lcd

const int tp=2; // trig pin
const int ep=3; // echo pin
int xv=0,yv=0,zv=0,t=0; // initial values
float d=0; // initial value
void setup()
{
 // initialize the LCD
 lcd.begin(); 
 lcd.backlight(); // Turn on the blacklight and print a message.
 lcd.clear(); // clears the screen
 lcd.setCursor(0, 0); // first colum ,first row
 lcd.print("Hello, world!");
 lcd.setCursor(0, 1); // first coloum, second row
 lcd.print("Welcome");
 pinMode(A0,INPUT); // x pin
 pinMode(A1,INPUT); // y pin
 pinMode(A2,INPUT); // z pin
 pinMode(13,OUTPUT); // green led
 pinMode(tp,OUTPUT);// TRIG PIN
 pinMode(ep,INPUT);// ECHO PIN
pinMode(12,OUTPUT);// LED FOR Y INCLINATION
pinMode(13,OUTPUT);// LED FOR X INCLINATION
}
 
void loop()
{
xv=analogRead(A0);
yv=analogRead(A1);
zv=analogRead(A2); 
if((xv >= 416 && xv <= 418) && (yv>=422 && yv <=424)) // condition for x & Y inclination, BOTH LEDS BLINK
 {
 digitalWrite(13,HIGH);
 delay(100);
 digitalWrite(13,LOW);
 delay(100);
 }
else
{
 digitalWrite(13,LOW);
 digitalWrite(12,LOW);
}

if(xv >= 416 && xv <= 418) // condition for x inclination
 digitalWrite(13,HIGH);
else
 digitalWrite(13,LOW);
 
if(yv>=422 && yv <=424) //condition for y inclinitaion
 digitalWrite(12,HIGH);
else
 digitalWrite(12,LOW);
 
digitalWrite(tp,LOW);
delayMicroseconds(50);
digitalWrite(tp,HIGH);
delayMicroseconds(50);
digitalWrite(tp,LOW);
t=pulseIn(ep,HIGH);
d=0.034*t/2;
lcd.clear(); // clears the screen
lcd.setCursor(0, 0); // first colum ,first row
lcd.print("x:"+String(xv));
lcd.print("      ");
lcd.print("y:"+String(yv));
lcd.setCursor(0, 1);
lcd.print("z:"+String(zv));
lcd.print(" ");
lcd.print("D:"+String(d));
lcd.print("CM");
delay(500);
}
