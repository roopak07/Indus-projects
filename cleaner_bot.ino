int val; 
int m1 = 8;     //Motor PIN=1
int m2 = 9;     //Motor PIN=2
int m3 = 10;    //Motor PIN=3
int m4 = 11;    //Motor Pin=4
int rpin=7; // RELAY PIN
void setup() {

  pinMode(m1, OUTPUT); 
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT); 
  pinMode(m4, OUTPUT);
  pinMode(rpin,OUTPUT);
  Serial.begin(9600);       
}

void loop() {


  if( Serial.available() )  
  {
    val = Serial.read();   
  }
  Serial.println("val:"+String(val));
  if( val == '1' )          // Move Forward      
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  } 
else if ( val == '2' )    // Move BACKWARD  
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }
else if  ( val == '3' )      // Move RIGHT  
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  } 
  else if ( val == '4' )    // Move LEFT
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  } 

  else if(val == '5') // Relay on
  {
    digitalWrite(rpin,HIGH );
  }                          
  else if(val == '6') // Relay oFF
  {
    digitalWrite(rpin,LOW );
  }
  
  else if(val == '0') //Stop The All Motor
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }                          //Stop The All Motor
  delay(100);                 
}
