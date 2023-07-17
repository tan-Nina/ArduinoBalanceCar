#include "move.h"

//definations of the pins to control the motors
#define PWMLeft 9
#define PWMRight 10
#define LeftIn1 7
#define LeftIn2 6
#define RightIn1 12
#define RightIn2 13

//definations of the fuctions to control the motors
#define LeftForward() digitalWrite(LeftIn1,HIGH);digitalWrite(LeftIn2,LOW)
#define LeftBackward() digitalWrite(LeftIn1,LOW);digitalWrite(LeftIn2,HIGH)
#define RightForward() digitalWrite(RightIn1,HIGH);digitalWrite(RightIn2,LOW)
#define RightBackward() digitalWrite(RightIn1,LOW);digitalWrite(RightIn2,HIGH)
#define LeftStop() digitalWrite(LeftIn1,LOW);digitalWrite(LeftIn2,LOW)
#define RightStop() digitalWrite(RightIn1,LOW);digitalWrite(RightIn2,LOW)

//definations of the fuctions to control the car
#define stop() LeftStop();RightStop()
#define forward(speed) LeftForward();RightForward();analogWrite(PWMLeft,speed);analogWrite(PWMRight,speed)
#define backward(speed) LeftBackward();RightBackward();analogWrite(PWMLeft,speed);analogWrite(PWMRight,speed)
#define left(speed) LeftStop();RightForward();analogWrite(PWMRight,speed)
#define right(speed) LeftForward();RightStop();analogWrite(PWMLeft,speed)

/*
Description: a move function
@param: direction: 0:forward 1:backward 2:left 3:right
@param: speed: 0~255
@param: time: 0~255,if time=0, then move forever
*/
void move(uint8_t direction,uint8_t speed, uint8_t time){
    switch(direction){
        case 0:
            forward(speed);
            break;
        case 1:
            backward(speed);
            break;
        case 2:
            left(speed);
            break;
        case 3:
            right(speed);
            break;
        default:
            stop();
            break;
    }
    if(time!=0){
        delay(time);
        stop();
    }

}

