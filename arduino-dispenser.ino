#include <Servo.h>

#define SERVO_PIN 9

#define TRIG_PIN  5
#define ECHO_PIN  6

long duration, distance;

Servo myServo;

void push_Sanitizer() {
  myServo.write(30); // adjust the degree here
  delay(500);
  myServo.write(0); // adjust the degree here
  delay(500);
  myServo.write(30); // adjust the degree here
  delay(1000);
}

float read_Distance() {
  // Clears the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Set the TRIG_PIN on HIGH state for 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculating the distance
  distance = (duration/2) / 29.1;

  return distance;
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(30); // set the default position of servo motor
}

void loop() {
  if(read_Distance() < 25) {
    push_Sanitizer();
  }
  
// Prints the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.print(read_Distance());
//  Serial.println(" cm");
//  delay(250);
}
