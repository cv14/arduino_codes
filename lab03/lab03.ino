#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  //pE();

  for(int address = 0; address < 0x09; address++) {
   
    char value = EEPROM.read(address);
  
    if (address < 0x10)
      Serial.print("00");
    else if (address < 0x100)
      Serial.print("0");
    Serial.print(address, HEX);
    Serial.print("\t");
    Serial.print(value, HEX);
    Serial.println();
  }
  Serial.println("|||||||||||||||||||||||||||||");
if((checkSum() & 0xff) != EEPROM.read(0x08))
  {
    EEPROM.write(0, 'S');
    EEPROM.write(1, 'A');
    EEPROM.write(2, 'U');
    EEPROM.write(3, 'R');
    EEPROM.write(4, 'A');
    EEPROM.write(5, 'V');
    EEPROM.write(6, 'P');
    EEPROM.write(7, 'P');
    EEPROM.write(8, checkSum());
    Serial.println("EEPROM has been reinitialized");
  }
  else
    Serial.println("EEPROM checksum is OK");
  
  Serial.println();
  for(int address = 0; address < 0x09; address++) {
   
    char value = EEPROM.read(address);
  
    if (address < 0x10)
      Serial.print("00");
    else if (address < 0x100)
      Serial.print("0");
    Serial.print(address, HEX);
    Serial.print("\t");
    Serial.print(value, HEX);
    Serial.println();
  }
  Serial.println("|||||||||||||||||||||||||||||");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

char checkSum()
{
  char checkSUM = 0;
  for (int i = 0; i < 0x08; i++) {
    checkSUM = checkSUM ^ EEPROM.read(i);
  }
  return ~checkSUM;
}
