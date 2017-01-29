#define in A0
#define ledpin 13
#define fan 7
#define led 6
#include <Servo.h>
Servo myservo;
int pos=90;
int c=0;
void setup() {
Serial.begin(9600);
pinMode(in,INPUT);
pinMode(ledpin,OUTPUT);
pinMode(fan,OUTPUT);
pinMode(led,OUTPUT);
myservo.attach(9);
delay(1000);
}
void loop() {
if(c<2)
 { int n=analogRead(in);
 Serial.println(n);
 if(n>100){
 digitalWrite(ledpin,HIGH);
 digitalWrite(fan,HIGH);
 delay(1000);
 digitalWrite(ledpin,LOW);
 digitalWrite(fan,LOW);
for (pos = 0; pos <= 90; pos += 1)
 {
 myservo.write(pos);
 delay(15);
 }
 Serial.println("gate open");
 c=c+1;
 Serial.print("the number of cars inside the parking area :");
 Serial.println(c);
 delay(1000);
 for (pos = 90; pos >= 0; pos -= 1)
{
 myservo.write(pos);
 delay(15);
 }Serial.println("gate close");
if(c>0){
 digitalWrite(led,HIGH);
}}
 delay(1000);}
 else{
 int n=analogRead(in);
 if(n>100)
 {
 Serial.println("limit exceeded");
 Serial.println(n);
myservo.write(0);
 delay(1000);
 }
 }
 }
