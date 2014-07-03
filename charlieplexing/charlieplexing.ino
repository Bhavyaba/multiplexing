/* Charlieplexing Example: 3-6 Multiplexor
   See Circuit at http://pcbheaven.com/wikipages/Charlieplexing/
*/
          
#define pin1 3
#define pin2 5
#define pin3 6


void setup(){
Serial.begin(9600);
}

void loop(){
if (Serial.available() > 0)
  switch(Serial.read()) {
    case '1':
     Serial.println("turning on 1");
     tristate('L','H','Z');
     break;
    case '2':
     Serial.println("turning on 2");
     tristate('H','L','Z');
     break;  
    case '3':
     Serial.println("turning on 3");
     tristate('Z','L','H');
     break;  
   case '4':
     Serial.println("turning on 4");
     tristate('Z','H','L');
     break;  
   case '5':
     Serial.println("turning on 5");
     tristate('L','Z','H');
     break;  
   case '6':
     Serial.println("turning on 6");
     tristate('H','Z','L');
     break;    
  }
  
  delay(50);
}

void tristate(char p1, char p2, char p3) {
  updatestate(pin1, p1);
  updatestate(pin2, p2);
  updatestate(pin3, p3);
}

void updatestate(int pin, char state)  {
 if (state == 'H') {
   pinMode(pin, OUTPUT);
   digitalWrite(pin, HIGH);
 } 
 else if (state == 'L') {
   pinMode(pin, OUTPUT);
   digitalWrite(pin, LOW); 
 }
 else if (state == 'Z')
   pinMode(pin, INPUT);
 else
   Serial.println("Invalid State Entry"); 
}
