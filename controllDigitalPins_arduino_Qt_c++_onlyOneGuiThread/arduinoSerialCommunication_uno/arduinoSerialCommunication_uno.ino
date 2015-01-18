
int incomingByte1 = 33;
int incomingByte2 = 558;
char incoming0 = 0;
int delayInMs = 0;

void setup() 
{
  // initialize serial:
  Serial.begin(57600);
  pinMode(2,OUTPUT);  
  pinMode(3,OUTPUT);  
  pinMode(4,OUTPUT);  
  pinMode(5,OUTPUT);  
  
  
  digitalWrite(2,OUTPUT);
  digitalWrite(3,OUTPUT);
  digitalWrite(4,OUTPUT);
  digitalWrite(5,OUTPUT);
}

void loop() 
{
 
  
    if ((Serial.available() > 0))
    {
      
            // read the incoming byte:
            incoming0 = Serial.read();
            
           if(incoming0=='s'){
             delay(20);
            
            incomingByte1 = Serial.parseInt();
            incomingByte2 = Serial.parseInt();
                   
                   

          if(incomingByte1==2)
          {
              
                          //digitalWrite, pin 2
                          if(incomingByte2==1)
                          {
                                PORTD |= _BV(PD2);
                          }                                                                            
   
                          if(incomingByte2==0)
                          {
                                PORTD &= ~_BV(PD2);   

                          }            
          }
          
          if(incomingByte1==3)
          {
              
                          //digitalWrite, pin 3
                          if(incomingByte2==1)
                          {
                                PORTD |= _BV(PD3);
                          }                                                                            
   
                          if(incomingByte2==0)
                          {
                                PORTD &= ~_BV(PD3);   

                          }                          
        
          }
          
                    if(incomingByte1==4)
          {
              
                          //digitalWrite, pin 4
                          if(incomingByte2==1)
                          {
                                PORTD |= _BV(PD4);
                          }                                                                            
   
                          if(incomingByte2==0)
                          {
                                PORTD &= ~_BV(PD4);   

                          }                          
            
          }
          
                    if(incomingByte1==5)
          {
              
                          //digitalWrite, pin 5
                          if(incomingByte2==1)
                          {
                                PORTD |= _BV(PD5);
                          }                                                                            
   
                          if(incomingByte2==0)
                          {
                                PORTD &= ~_BV(PD5);   

                          }                          
          }

              
              //flush incoming serial buffer   
              while(Serial.available())
                Serial.read();  
        
        
          Serial.print(incomingByte1);
          Serial.print(",");
          Serial.print(incomingByte2);
          Serial.print("\n");
          }
     }
     

}
