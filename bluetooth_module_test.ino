#define relay 7       //assigns 7 to "relay" 

unsigned int a;
unsigned int b;
unsigned int passcode;

void setup() 
{
  Serial.begin(9600);      //reading serial communication   
  pinMode(relay, OUTPUT);  //setting "relay" pin7 to output 
}

void loop()
{
  if(Serial.available() >= 2)  //when serial communication has any value condition is called
  {
    a = Serial.read();  //revieve 1/2 byte of 2 byte number passcode
    b = Serial.read();  //revieve 2/2 byte of 2 byte number passcode
    passcode = (b*256) + a; //convert back to decimal
    
    if (passcode == 1234) //when proper signal code recieved from phone // Replace with secure 2byte number
    {
    Serial.print(passcode);
    Serial.print(" Confirmed correct Passcode");    //prints to serial monitor password confirmation
    Serial.print("\n");       
    digitalWrite (relay,HIGH);
    delay(250);    //acts as a short pulse foor door actuator
    digitalWrite (relay,LOW);            
    }    
   
  }                      
} 
