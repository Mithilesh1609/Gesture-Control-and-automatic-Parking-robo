#include "Arduino.h"
#define xPin A3
#define yPin A1
#define zPin A5
int GNDPin=A4; //Set Analog pin 4 as GND
int VccPin=A5; //Set Analog pin 5 as VCC

//int xPin=A3; //X axis input
//int yPin=A1; //Y axis input
//int zPin=A5; //Z axis input(not used)

int Q1=10,Q2=11,Q3=12,Q4=13; //Output pins to be connected to 10, 11, 12, 13 of Decoder IC

long x; //Variable for storing X coordinates
long y; //Variable for storing Y coordinates
long z; //Variable for storing Z coordinates

void setup()
{
  Serial.begin(9600);
  pinMode(Q1,OUTPUT); //here Q1,Q2 is two side of motor1 and Q3,Q4 is two side of motor2
  pinMode(Q2,OUTPUT);
  pinMode(Q3,OUTPUT);
  pinMode(Q4,OUTPUT);
  pinMode(GNDPin, OUTPUT);
  pinMode(VccPin, OUTPUT);
  digitalWrite(GNDPin, LOW); //Set A4 pin LOW
  digitalWrite(VccPin, HIGH); //Set A5 pin HIGH
}
void loop()
{

  x = analogRead(xPin); //Reads X coordinates
  y = analogRead(yPin); //Reads Y coordinates
  z = analogRead(zPin); //Reads Z coordinates (Not Used)
  
    if(x<340)      // Change the value for adjusting sensitivity  
      forward();
    else if(x>400) // Change the value for adjusting sensitivity
      backward();
    else if(y>400) // Change the value for adjusting sensitivity
      right();
    else if(y<340) // Change the value for adjusting sensitivity
      left();
    else
      stop_();
}

void stop_() // for stoping the boat we need to stop all motors.
{
  Serial.println("");
  Serial.println("STOP");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,LOW);
}

void forward() // for move forward we need to on one side of the motor1 and same side of motor-2
{
  Serial.println("");
  Serial.println("Forward");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,HIGH);
  digitalWrite(Q4,LOW);
}

void backward()  // to move the boat in backwards we need to on one side of the motor1 and same side of motor-2 which are opposite of forwarding part.
{
  Serial.println("");
  Serial.println("Backward");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,HIGH);
}

void left() // to move left we need to move motor-1 anticlockwise and motor-2 clockwise.
{
  Serial.println("");
  Serial.println("Left");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,HIGH);
  digitalWrite(Q4,LOW);
}

void right()  // to move the boat in right we need to move motor-1 in clockwise and motor-2 in the anticlockwise direction.
{
  Serial.println("");
  Serial.println("Right");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,HIGH);
}
