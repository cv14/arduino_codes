
   //CdS Photoresistor
   const int psr = 0;
   // Pin for input from PIR Sensor                
   const int pir = 2;
   // Pin for output LED                
   const int led = 13;               
   
   void setup()
   {
     Serial.begin(9600);
     pinMode(led, OUTPUT);           
     pinMode(pir, INPUT);            
   }
   
   void loop()
   {
     //read the light value 
     int val = analogRead(psr);
     //print the rate
     Serial.print("PSR VALUE");      
     Serial.println(val);                
     for(int i = 0; i < val / 30; i++) 
       Serial.print("*");
     Serial.print("\n");
     delay(1000);                       
     int valPir = digitalRead(pir);     
     if (valPir == HIGH)  
       digitalWrite(led, HIGH);
     else
       digitalWrite(led, LOW);
   }
