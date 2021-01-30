const int trigPin1 = A0;
const int echoPin1 = A1;
const int trigPin2 = A2; 
const int echoPin2 = A3;
const int trigPin3 = A4;
const int echoPin3 = A5;

const int in1 = 7;
const int in2 = 6;
const int in3 = 5;
const int in4 = 4;
const int enA = 10;
const int enB = 9;

#define PWM 200
#define DIS 15

void setup() 
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
  Serial.begin(9600); 
}

void loop()
{
  Serial.println("Sensor 1=");
  Serial.println(FrontSensor());
  Serial.println("Sensor 2=");
  Serial.println(RightSensor());
  Serial.println("Sensor 3=");
  Serial.println(LeftSensor());    
  if ( FrontSensor() < DIS && RightSensor () <DIS && LeftSensor ()<DIS) 
  {
    turn_right (); 
    delay(3000);
  }
  else if (FrontSensor() <DIS && RightSensor () <DIS && LeftSensor ()>DIS) 
  {
    turn_left (); 
  }
  else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor ()<DIS) 
  {
    turn_right (); 
  }
  else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor ()>DIS)
  {
    turn_right (); 
  }
  else if (FrontSensor() >DIS && RightSensor () >DIS && LeftSensor ()<DIS) 
  {
    turn_right ();
    delay(180);
    forward();
  }
  else if (FrontSensor() >DIS && RightSensor () <DIS && LeftSensor ()>DIS) 
  {
    turn_left (); 
    delay(180);
    forward();
  }
  else 
  {
    forward();
  }
}

void forward ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
}

void turn_left () 
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
}

void turn_right () 
{
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}

void reverse ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}

void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, LOW);
  analogWrite(enB, LOW);
}

long FrontSensor ()
{
  long dur;
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  dur = pulseIn(echoPin1, HIGH);
  return (dur* 0.034 / 2);
}

long RightSensor () 
{
  long dur;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  dur = pulseIn(echoPin2, HIGH);
  return (dur* 0.034 / 2);
}

long LeftSensor ()    
{
  long dur;
  digitalWrite(trigPin3, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  dur = pulseIn(echoPin3, HIGH);
  return (dur* 0.034 / 2);
}
