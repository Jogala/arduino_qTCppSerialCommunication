
int incomingByte1 = 33;
int incomingByte2 = 558;

void setup() 
{
  // initialize serial:
  Serial.begin(115200);
  pinMode(2,OUTPUT);  
}

void loop() 
{
 
  
    if ((Serial.available() > 0))
    {
      
            // read the incoming byte:
            incomingByte1 = Serial.parseInt();
            incomingByte2 = Serial.parseInt();
                   
//          Serial.print(incomingByte1);
//          Serial.print(",");
//          Serial.print(incomingByte2);
//          Serial.print("\n");
  
        for(int i = 2;i<=13;i++)
        {
                         if(incomingByte1 == i)
                         {                     
                           digitalWrite(i,incomingByte2);                           
                         }
        }
     }
     

}
