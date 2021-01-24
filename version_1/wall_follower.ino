const int ir1=2;
const int ir2=3;
const int trigPin1=4;
const int echoPin1=5;
const int trigPin2=6;
const int echoPin2=7;
const int lm1=8;
const int lm2=9;
const int en1=10;
const int en2=11;
const int rm1=12;
const int rm2=13;
void setup() {
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  Serial.begin(9600);

}
//int ultra_active(int trigPin)
//{
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//}
//int obst_distance(int echoPin)
//{
//  int duration;
//  duration = pulseIn(echoPin, HIGH);
//  int distance;
//  distance= duration*0.034/2;
//  return distance;
//}
int distance1, distance2;
void loop() {

//  ultra_active(trigPin1);
//  distance1=obst_distance(echoPin1);
////  ultra_active(trigPin2);
////  distance2=obst_distance(echoPin2);
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
int duration1;
duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;

  if((distance1<100)&&(distance1>25))
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite(en1,150);
    analogWrite(en2,150);
    Serial.print("Distance 1: ");
    Serial.println(distance1);
    Serial.println("25-100");
  }
  else if((distance1<=25)&&(distance1>10))
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite(en1,30);
    analogWrite(en2,30);
    Serial.print("Distance 1: ");
    Serial.println(distance1);
    Serial.println("10-25");
  }
  else if(distance1<=10)
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
    Serial.print("Distance 1: ");
    Serial.println(distance1);
    Serial.println("Less Than 10");
  }
  else if(distance1>=100)
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    analogWrite(en1,255);
    analogWrite(en2,255);
    Serial.print("Distance 1: ");
    Serial.println(distance1);
    Serial.println("Greater than 100");
  }
}
