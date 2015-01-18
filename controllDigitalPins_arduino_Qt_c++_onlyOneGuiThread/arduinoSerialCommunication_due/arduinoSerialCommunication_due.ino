
int incomingByte1 = 33;
int incomingByte2 = 558;

void setup() 
{
  // initialize serial:
  Serial.begin(57600);
  pinMode(2,OUTPUT);  
}

void loop() 
{
 
  
    if ((Serial.available() > 0))
    {
      
            // read the incoming byte:
            incomingByte1 = Serial.parseInt();
            incomingByte2 = Serial.parseInt();
                   

          if(incomingByte1==2)
          {
              
                          //digitalWrite, pin 2
                          if(incomingByte2==1)
                          {
                                PORTD |= _BV(D2);
                          }
                            
                          if(incomingByte2==0)
                          {
                                PORTD &= ~_BV(D2);   
                          }
                                                      
               
                          delay(5);
                          
                          //digitalWrite, pin 3
                          if(incomingByte2==1)
                          {
                                PORTD |= _BV(D3);
                          }
                            
                          if(incomingByte2==0)
                          {
                                PORTD &= ~_BV(D3);   
                          }                           
                      
              //flush incoming serial buffer   
              while(Serial.available())
                Serial.read();                         
                         
          }

  
//        for(int i = 2;i<=13;i++)
//        {
//                         if(incomingByte1 == i)
//                         {                     
//                           digitalWrite(i,incomingByte2);                           
//                         }
//        }
        
        
          Serial.print(incomingByte1);
          Serial.print(",");
          Serial.print(incomingByte2);
          Serial.print("\n");
     }
     

}
