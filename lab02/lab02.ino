/*
  Program Memory and RAM Memory Exploration
 */
#include <avr/pgmspace.h>
// put a string in program memory
const char array1[] PROGMEM = "Array 1";

// put a string in RAM initialized data area
const char array2[] = "Array 2";

void setup() {
  // put your setup code here, to run once:
  // put a string in RAM stack area
  char array3[] = "Array 3";
  // put a string in RAM heap area
  char *array4 = (char*) malloc(strlen("Array 3") + 1);
  strcpy(array4, "Array 4");

  // Setup for Serial outputp
  Serial.begin(9600);  
  // Part 1:  print address ranges for each memory space
  Serial.print("\nEnd of Flash: ");
  Serial.println(FLASHEND, HEX);
  Serial.print("End of RAM: ");
  Serial.println(RAMEND, HEX);
  Serial.print("End of EEPROM: ");
  Serial.println(E2END, HEX);
  Serial.println();

  // Part 2: function pointer
  void (*pointer)() = &printHello;
  (*pointer) ();

  Serial.println((int) &printHello, HEX);  // address of function
  Serial.println((int) &pointer, HEX);     // address of pointer
  Serial.println((int) pointer, HEX);      // pointer value itself
  Serial.println((int) *((int *) pointer), HEX);              // RAM contents
  Serial.println((int) pgm_read_word(pointer) & 0xffff, HEX); // program memory contents
  Serial.println();

  // Part 3: Data stored in program memory
  Serial.println("String in program memory: ");
  char c;
  for (int i = 0; (c = pgm_read_byte(&array1[i])) != 0; i++)
    Serial.print(c);
  Serial.println(array1);    // accesses RAM - not program memory
  Serial.print("Address of string in program memory: ");
  Serial.println((int) &array1[0], HEX);
  Serial.println();

  Serial.println("String in RAM initialized data: ");
  Serial.println(array2);
  Serial.print("Address of string in RAM initialized data: ");
  Serial.println((int) &array2[0], HEX);
  Serial.println();

  Serial.println("String in RAM stack: ");
  Serial.println(array3);
  Serial.print("Address of string in RAM stack: ");
  Serial.println((int) &array3[0], HEX);
  Serial.println();

   
  /*
  char *array;  // pointer to scan memory locations
  int i;       // variable for 16 words per line
  for(array = 0; array < (char *) RAMEND; array += 0x10) {
    if (array < (char *)0x10)
      Serial.print('0');
    if (array < (char *)0x100)
      Serial.print('0');
    Serial.print((int)array, HEX);
    Serial.print(": ");
    for(i = 0; i < 0x10; i++) {
      if (array[i] >= 0x00 && array[i] < 0x10)
        Serial.print('0');
      Serial.print(array[i] & 0xFF, HEX);
      Serial.write(' ');
    }
    Serial.print("  ");
    for(i = 0; i < 0x10; i++) {
      Serial.print((array[i] >= ' ' && array[i] <= 'z') ? array[i] : '.');
      Serial.write(' ');
    }
    Serial.write('\n');
  }*/
}

void loop() {
  // put your main code here, to run repeatedly:

}

void printHello()
{
  Serial.println("printHello function works");
}

