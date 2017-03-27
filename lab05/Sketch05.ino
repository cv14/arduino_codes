
#include <SoftwareSerial.h>
const int rxpin = 2;
const int txpin = 3;
SoftwareSerial serial_display(rxpin, txpin);

void setup() { 
  serial_display.begin(9600);           // setup port at 9600bps
  serial_display.write(0x0c);          
  // ASCII Form Feed - clear display
  delay(10);                            // delay required
  serial_display.write("CS341 LAB 5 "); // Write Hello World
  serial_display.write(0x0d);           
  serial_display.write("KEKISTAN"); // and again in Italian
}

void loop() {
  delay(10000);
  serial_display.write(0xD7);  // lowest octave
  charge();
  
  delay(2000);
  serial_display.write(0xD8);  // middle octave
  charge();
  
  delay(2000);
  serial_display.write(0xD9);  // middle octave
  charge();
  
  delay(2000);
  serial_display.write(0xDA);  // middle octave
  charge();
  
  delay(2000);
  serial_display.write(0xDB);  // highest octave
  charge();
}
void charge()
{
  // Play "Charge!!!"
  /*
  serial_display.write(0xD2); // set note length to 1/16 note
  serial_display.write(0xE6); // G note
  serial_display.write(0xDF); // C note
  serial_display.write(0xD3); // set note length to 1/8 note
  serial_display.write(0xE3); // E note
  serial_display.write(0xD4); // set note length to 1/4 note
  serial_display.write(0xE6); // G note
  serial_display.write(0xD3); // set note length to 1/8 note
  serial_display.write(0xE3); // E note
  serial_display.write(0xD5); // set note length to 1/2 note
  serial_display.write(0xE6); // G note
  */
  serial_display.write(211); 
  serial_display.write(223);
  serial_display.write(210); 
  serial_display.write(223); 
  serial_display.write(212); 
  serial_display.write(225); 
  serial_display.write(212); 
  serial_display.write(223); 
  serial_display.write(212); 
  serial_display.write(228); 
  serial_display.write(213); 

  serial_display.write(227); 
  serial_display.write(211);
  serial_display.write(223); 
  serial_display.write(210); 
  serial_display.write(223); 
  serial_display.write(212); 
  serial_display.write(225); 
  serial_display.write(212); 
  serial_display.write(223); 
  serial_display.write(212); 
  serial_display.write(230);

   serial_display.write(213); 
  serial_display.write(228);
  serial_display.write(211); 
  serial_display.write(223); 
  serial_display.write(210); 
  serial_display.write(223); 
  serial_display.write(217); 
  serial_display.write(212); 
  serial_display.write(223); 
  serial_display.write(216); 
  serial_display.write(212);

   serial_display.write(220); 
  serial_display.write(212);
  serial_display.write(228); 
  serial_display.write(212); 
  serial_display.write(227); 
  serial_display.write(212); 
  serial_display.write(225); 
  serial_display.write(211); 
  serial_display.write(222); 
  serial_display.write(210); 
  serial_display.write(222);

   serial_display.write(212); 
  serial_display.write(228);
  serial_display.write(212); 
  serial_display.write(230); 
  serial_display.write(213); 
  serial_display.write(228); 
  delay(3000);
  
}
