//pins for ultrasonic sensor 1
const int trigoPin1=2;
const int echoPin1=3;

//pins for ultrasonic sensor 2
const int trigoPin2=6;
const int echoPin2=7;

//pins for ultrasonic sensor 3
const int trigoPin3=9;
const int echoPin3=10;

//pin for buzzer 
const int buzzer = 8;

long duration;
int distance;


void setup() 
{
  
  pinMode(trigoPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  
  pinMode(trigoPin2,OUTPUT);
  pinMode(echoPin2,INPUT);

  pinMode(trigoPin3,OUTPUT);
  pinMode(echoPin3,INPUT);
  
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,LOW);  
  Serial.begin(9600);
}

void loop() 
{
  calcDistance(trigoPin1,echoPin1);
  calcDistance(trigoPin2,echoPin2);
  calcDistance(trigoPin3,echoPin3);
}

void calcDistance(int trigPin,int echoPin)
{
  digitalWrite(trigPin,LOW);
  delay(100);
  digitalWrite(trigPin,HIGH);
  delay(1000);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration * 0.034/2;
  if(trigPin == 2)
  {
    Serial.print("Distance of ultrasonic Sensor 1: ");
    Serial.println(distance);
    if(distance<15)
    {
      digitalWrite(buzzer,HIGH);
      delay(1000);
    }
    else
    {
      digitalWrite(buzzer,LOW);
    }
  }
  
  if(trigPin == 6)
  {
    Serial.print("Distance of ultrasonic Sensor 2: ");
    Serial.println(distance);
    if(distance<15)
    {
      digitalWrite(buzzer,HIGH);
      delay(700);
    }
    else
    {
      digitalWrite(buzzer,LOW);
    }
    
  }
  
  if(trigPin == 9)
  {
    Serial.print("Distance of Ultrasonic Sensor 3: ");
    Serial.println(distance);
    if(distance<15)
    {
      digitalWrite(buzzer,HIGH);
      delay(500);
    }
    else
    {
      digitalWrite(buzzer,LOW);
    }
  }  
  
}
