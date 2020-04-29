#include <Servo.h>

Servo myservo;
Servo myservo1;

int pushButton = 10;

int pos = 0;
int pos1 = 0;

int pirPin = 8; //digital 2
int counter = 0;
int state;
int laststate = HIGH;

const int trigPin1 = 2;
const int echoPin1 = 3;

const int trigPin2 = 4;
const int echoPin2 = 5;

const int trigPin3 = 6;
const int echoPin3 = 7;

long duration1;
int distance1;

long duration2;
int distance2;

long duration3;
int distance3;


String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {

  
  Serial.begin(9600); // Starts the serial communication
 pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  myservo.attach(9);
    myservo1.attach(10);
  pinMode(pirPin, INPUT);

  pinMode(pushButton, INPUT_PULLUP);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
   int state = digitalRead(pirPin);
  if ( state != laststate)

  {
    counter = counter + 1;
    Serial.println("counter");
    Serial.println(counter);
  }
  laststate = state;
  delay(1000);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2;

  Serial.print("b1");
  Serial.print("\t");
  Serial.print("b2");
  Serial.print("\t");
  Serial.println("b3");


  Serial.print(distance1);
  Serial.print("\t");
  Serial.print(distance2);
  Serial.print("\t");
  Serial.println(distance3);

  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false; 
  if(inputString = "$0001630441")
  { 
    for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
    Serial.println("HIII");
  }
  for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }

delay(100);

for (pos1 = 0; pos1 <= 120; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 120; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  
    
  }


  
//  int buttonState = digitalRead(pushButton);
//  Serial.println(buttonState);
//  
  delay(1000); 
  
  }
}

void serialEvent() {
  while (Serial.available()) {

    char inChar = (char)Serial.read();

    inputString += inChar;

    if (inChar == '\n') {
      stringComplete = true;
      
    }
  }
}