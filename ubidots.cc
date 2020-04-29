#include "UbidotsMicroESP8266.h"
#include <ESP8266WiFi.h>

#define TOKEN  "A1E-ii2tqV8yW3FaUM21UiZJcurFhuKzzj"  // Put here your Ubidots TOKEN
#define ID_1 "5c7e27a8c03f976d01ce4966" // b1
#define ID_2 "5c7e27cac03f976d3a5f60cf" // b2
#define ID_3 "5c7e27d1c03f976d01ce496e" // b3
#define ID_4 "5c7e27d9c03f976d3a5f60ef" // c1
#define WIFISSID "admin" // Put here your Wi-Fi SSID
#define PASSWORD "12345678" // Put here your Wi-Fi password

int pirPin = D8; //digital 2
int counter = 0;
int state;
int laststate = HIGH;

const int trigPin1 = D1;
const int echoPin1 = D2;

const int trigPin2 = D3;
const int echoPin2 = D4;

const int trigPin3 = D5;
const int echoPin3 = D6;

long duration1;
int distance1;

long duration2;
int distance2;

long duration3;
int distance3;
Ubidots client(TOKEN);

void setup() {
Serial.begin(115200);
   client.wifiConnection(WIFISSID, PASSWORD);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input

  pinMode(pirPin, INPUT);
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
  delay(0);
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
  delay(1000);

  client.add(ID_1,distance1);
  client.add(ID_2,distance2);
  client.add(ID_3,distance3);
  client.add(ID_4,counter);
  client.sendAll(false);
  delay(1000);
}