
//defining for first ultrasonic
#define TRIGGER_PIN1 13
#define ECHO_PIN1 12
#define MAX_DISTANCE1 200
long dur1;
int dis1;
void Read () ;
//for second one
#define TRIGGER_PIN2 11
#define ECHO_PIN2 10
#define MAX_DISTANCE2 200
int dis2;
long dur2;

#define TRIGGER_PIN3 9
#define ECHO_PIN3 8
#define MAX_DISTANCE3 200
int dis3;
long dur3;

#define TRIGGER_PIN4 7
#define ECHO_PIN4 6
#define MAX_DISTANCE4 200
int dis4;
long dur4;

//defining the motors
int Q1LF = 2;
int Q2LR = 3;
int Q3RR = 4;
int in4RF = 5;

void setup() {
  pinMode(Q1LF, OUTPUT);
  pinMode(Q2LR, OUTPUT);
  pinMode(Q3RR, OUTPUT);
  pinMode(in4RF, OUTPUT);
  Serial.begin (9600);
}

void loop(){
  Read();
  if ((dis1 < 10 && dis3 < 15 && dis4 < 15) || (dis2 < 5 && dis3 < 15 && dis4 < 15)) { //we have applied the left hand side approach in this case and finding the distance of all side base on that we will decide to move in which direction 
    digitalWrite (Q1LF, LOW);
    digitalWrite (Q2LR, LOW);
    digitalWrite (Q3RR, LOW);
    digitalWrite (in4RF, LOW);
  }else if (dis1 > 10) {
    digitalWrite (Q1LF, HIGH);
    digitalWrite (Q2LR, LOW);
    digitalWrite (Q3RR, LOW);
    digitalWrite (in4RF, HIGH);
    
if (dis3 < 55 && dis3 > 27) {
      digitalWrite(Q1LF, LOW);
      digitalWrite(Q3RR, LOW);
      digitalWrite(in4RF, LOW);
      digitalWrite(Q2LR, LOW);



      while (1) {
        digitalWrite(Q1LF, HIGH);
        digitalWrite(Q3RR, HIGH);
        digitalWrite(in4RF, LOW);
        digitalWrite(Q2LR, LOW);
        Read ();
        if (dis1 > 20 && dis3 > 40){ 
           break;
        }
      }
    }
    else if (dis4 < 55 && dis4 > 27) {
      digitalWrite(Q1LF, LOW);
      digitalWrite(Q3RR, LOW);
      digitalWrite(in4RF, LOW);
      digitalWrite(Q2LR, LOW);

      while (1) {
        digitalWrite(Q1LF, LOW);
        digitalWrite(Q3RR, LOW);
        digitalWrite(in4RF, HIGH);
        digitalWrite(Q2LR, HIGH);
        Read ();
        if (dis1 > 20 && dis4 > 40) {
           break;
        }
      }
    }
  }
  else if (dis1 < 10 && dis2 > 70 && dis3 < 15 && dis4 < 15){ 
    digitalWrite(Q1LF, LOW);
    digitalWrite(Q3RR, LOW);
    digitalWrite(in4RF, LOW);
    digitalWrite(Q2LR, LOW);

    while (1){
      digitalWrite(Q1LF, LOW);
      digitalWrite(Q3RR, HIGH);
      digitalWrite(in4RF, LOW);
      digitalWrite(Q2LR, HIGH);
      Read ();
      
      if (dis2 > 10) {
         break;
      }
    }
  }
}
void Read(){
  dis1= dur1*0.034/2; //calculating the distance
  Serial.print("Distance: "); // Prints the distance on the Serial Monitor
  Serial.println(dis1);
  dis2= dur2*0.034/2; //calculating the distance
  Serial.print("Distance: "); // Prints the distance on the Serial Monitor
  Serial.println(dis1);
  dis3= dur3*0.034/2; //calculating the distance
  Serial.print("Distance: "); // Prints the distance on the Serial Monitor
  Serial.println(dis1);
  dis4= dur4*0.034/2; //calculating the distance
  Serial.print("Distance: "); // Prints the distance on the Serial Monitor
  Serial.println(dis4);
}
