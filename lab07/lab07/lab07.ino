
const int pingPin = 5;    
int d;                    
int dOld;                 
int DELTA_T = 1000;      

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  dOld = d;
  d = ping(pingPin);
  // calculate velocity in cm per second
  int v = 1000 * (d - dOld) / DELTA_T;
  // print everything
  Serial.print("D: ");
  Serial.print(d);
  Serial.print(" / V: ");
  Serial.println(v);
  delay(DELTA_T);
}

int ping(int pingPin)
{
  int duration;                      
  
  pinMode(pingPin, OUTPUT);          
  digitalWrite(pingPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(pingPin, HIGH);      
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);       
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
                                     
                                     
  return duration / 29 / 2;          
}
