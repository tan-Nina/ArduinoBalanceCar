
uint8_t LeftSpeed=100;
uint8_t RightSpeed=100;
#include "SpeedModify.h"
#include "move.h"
/*
A是右轮
B是左轮更弱
*/



void setup() {
  // put your setup code here, to run once:
  motorInit();
  //setupSpeedTest();
  Serial.begin(9600);
  //TODO: modulize the initilization of the motor
}
/*
[REC]119 w


[REC]115 s 


[REC]100 d 


[REC]97 a

*/

void loop() {
  // put your main code here, to run repeatedly:  
  //static unsigned char Receive_Data;
  int Receive_Data;
  while(Serial.available()){
    int inByte = Serial.read();
    int direction;
    int speed = 25;
    //Receive_Data = (char)inByte;
    Receive_Data = inByte;
    Serial.println(Receive_Data);
    //if (Receive_Data==(char)'w'){
   if(Receive_Data>50){
    switch (Receive_Data)
    {
    case 119/* constant-expression */:
      direction = 0;
      /* forward:input w */
      break;
    case 115:
      direction = 1;
      /* backward input s */
      break;
    case 100:
      direction = 3;
      /* right: input d */
      break;
    case 97:
      direction = 2;
      /* right: input a */
      break;
    default:
      Serial.println("wrong input");
      break;
    }
 
   }
   else{
      speed = Receive_Data;
   }
   move(direction,speed,0);//move the car with the direction and speed forever
 }
}
