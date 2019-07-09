#include <Servo.h>   
Servo servo_test;
Servo servo_test1;
int angle = 0; 
int angle1 = 0; 

#define IN1  11
#define IN2  10
#define IN3  9
#define IN4  8

int Steps = 0;
int Direction = 0;
int number_steps=1024;//= 2048/4

void setup()
{
  Serial.begin(9600);
  servo_test.attach(2);
  servo_test1.attach(3); 
  servo_test.write(0); 
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  delay(1000);
  
}

void loop()
{
  Serial.print("Loop started");
  
  for(angle = 0; angle < 90; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(40);   
    
                 
  } 
  
  delay(3000);

    for(angle1 = 0; angle1 < 90; angle1 += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test1.write(angle1);                 //command to rotate the servo to the specified angle
    delay(40);                       
  } 
  delay(3000);
  
  
//1 rotation counter clockwise
stepper(number_steps);
delay(5000);
//1 rotation clockwise
stepper(-number_steps);
delay(5000);    
  

//Keep track of step number


for(angle = 90; angle <= 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(40);   

  } 
  delay(3000);
  
/*for(angle1 = 90; angle1 <= 180; angle1 += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test1.write(angle1);                 //command to rotate the servo to the specified angle
    delay(40);                       
  } 
  delay(3000);
*/
  /*/1 rotation counter clockwise
stepper(number_steps);
delay(5000);
//1 rotation clockwise
stepper(-number_steps);
delay(5000);
  */



 for(angle = 180; angle>=90; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(40);

      }  delay(3000);
      
   for(angle1 = 90; angle1>=0; angle1-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test1.write(angle1);              //command to rotate the servo to the specified angle
    delay(40);                       
  }  delay(3000);

  stepper(number_steps);
delay(5000);
//1 rotation clockwise
stepper(-number_steps);
delay(5000);



for(angle = 90; angle>=1; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(40);    

    delay(3000);}
    
   /*   for(angle1 = 90; angle1>=1; angle1-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test1.write(angle1);              //command to rotate the servo to the specified angle
    delay(40);                       
  } 
    delay(3000);}*/
/*        
stepper(number_steps);
delay(5000);
//1 rotation clockwise
stepper(-number_steps);
delay(5000);} */

}

void stepper(double nbStep){
if(nbStep>=0){
Direction=1;
}else{
Direction=0;
nbStep=-nbStep;
}
for (int x=0;x<nbStep*8;x++){
switch(Steps){
case 0:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
break; 
case 1:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH);
break; 
case 2:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
break; 
case 3:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
break; 
case 4:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
break; 
case 5:
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
break; 
case 6:
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
break; 
case 7:
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
break; 
default:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
break; 
}
delayMicroseconds(1000);
if(Direction==1){ Steps++;}
if(Direction==0){ Steps--; }
if(Steps>7){Steps=0;}
if(Steps<0){Steps=7; }
} 
} 
