void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);  

  Serial.println("RAM VALUES FIRST");
  show((char *) 0x20, (char *) 0x30);
  Serial.write('\n');

  //PIN 13 ..Setting output and high
  int pin = 13;
  Serial.print("PIN : ");
  Serial.println(pin);
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  show((char *) 0x20, (char *) 0x30);
  Serial.write('\n');

  //Setting low
  Serial.print("LOW ");
  Serial.println(pin);
  digitalWrite(pin, LOW);
  show((char *) 0x20, (char *) 0x30);
  Serial.write('\n');
}

void loop() {
  //FOR FLASHING THE MEMORY
  char *pin13 = (char *) 0x25;
  *pin13 ^= 0x20;
  delay(1000);
}


//show function displays the RAM
void show(char *first, char *last)
{
  unsigned int mem;
  for(mem = first; mem < last; mem++) {
      Serial.print("Address : ");
      Serial.println(mem, HEX);
      Serial.print("Values ");
      Serial.println(*(int *) mem & 0xff, HEX);
  }
}
