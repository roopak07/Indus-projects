#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<String.h>

char auth[] = "d10e00fc82954ce7b0665c192a4d1e6e";
char ssid[] = "PYP5"; // wifi user id
char pass[] = "Indus@123"; // wifi password

BlynkTimer timer;
int result;
void sendSensor()
{
  bool result = Blynk.connected();
  Serial.println("Online Status: "+String(result));
  if(result==1)  // indication for online
   digitalWrite(16,HIGH); 
  else
   digitalWrite(16,LOW);
   
  int x=analogRead(A0);
  Serial.println(x);
  Blynk.virtualWrite(V1,x); // sending values to blynk over internet 
  if(x<=870)
  {
   while(1)
   {
    Blynk.notify("Theft detected...!");
    Blynk.email("megnayadlapalli@gmail.com","Theft notification alert","Theft notifed"); 
   }
  }
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(A0,INPUT); // SENSOR PIN 
  pinMode(16,OUTPUT); //D0 , for check-in indication
  timer.setInterval(100L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
