#include<IRremote.h>
int recvPin = 7;  // CONNECT THE OUTPUT PIN OF THE IR RECIEVER TO THIS PIN

IRrecv irrecv(recvPin);
decode_results results;
int IN1=6,IN2=8,IN3=12,IN4=13;
int fwd=9254,rev=25638;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
irrecv.enableIRIn();
//pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))
{ 

  if(results.value==fwd)
    forward();
  else if(results.value==rev)
    reset();
   /*else if(results.value==left)
      left();
    else if(results.value==right)
      right();*/
   /*else
    reset();*/
      
   
  Serial.println(results.value,HEX);
  irrecv.resume();
  /*digitalWrite(LED_BUILTIN,HIGH);
  delay(500);*/
}
 /* digitalWrite(LED_BUILTIN,LOW);
  delay(1000);*/
}
  
  
  /*forward();
  delay(2000);
  reverse();
  delay(2000);
  left();
  delay(2000);
  right();
  delay(2000);
  forward();
  delay(2000);
  reverse();
  delay(2000);
  sharpLeft();
  delay(2000);
  sharpRight();
  delay(2000);*/
  

void forward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void reverse()
{
   digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void left()
{
   digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
void right()
{
 digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void sharpLeft()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void sharpRight()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void reset()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
