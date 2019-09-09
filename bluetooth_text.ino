String voice; 
char c;
void setup() {
  
  pinMode(2, OUTPUT);
  Serial.begin(9600);       
}

void loop() {

  while( Serial.available() )  
  {
    delay(10);
    c = Serial.read();
    if (c == '#') // after our voice last charcter will be # , so if we get # need to break the loop ,it will take only voice
    {
      break;
    }
    voice=voice+c;
  }
  if (voice.length() > 0)
 {
 Serial.print(voice);
 }
 if( voice == "turn on" )           
  {
    digitalWrite(13, HIGH);
  } 
else if  ( voice == "turn off" )      
  {
    digitalWrite(13, LOW); 
  } 
 voice="";
}
