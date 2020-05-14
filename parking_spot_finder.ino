
#define trigPin 13
#define echoPin 12

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(5, OUTPUT); //pin of motor-A
pinMode(6, OUTPUT); //pin of motor-A
pinMode(9, OUTPUT); //pin of motor-B
pinMode(10, OUTPUT); //pin of motor-B
}

void loop() {
long duration, distance;
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(2); // wait for 2 seconds.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; //calculating the distance

if (distance < 7) {  // This is where the LED On/Off happens
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
  }else { //we are performing the parking when the car finds at least 7 cm space.
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    analogWrite(6, 110);
    analogWrite(5, LOW);
    delay(50);

    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    analogWrite(5, 110);
    analogWrite(6, LOW);
    delay(100);

 
   digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    analogWrite(5, 110);
    analogWrite(6, LOW);
    delay(100);

    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    analogWrite(5, LOW);
    analogWrite(6, LOW);
    delay(1000);
    }
}
