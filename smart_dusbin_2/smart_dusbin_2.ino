#include <Servo.h>   //servo library
Servo servo;    

const int trigPin = 5;
const int echoPin = 6;
int servoPin = 7;

// defines variables
long duration;
int distance;
int safetyDistance;
 
 
void setup() {
servo.attach(servoPin);   
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
servo.write(0);         //close cap on power on
delay(100);
servo.detach(); 
}
 
 
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
 
// Calculating the distance
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 8){
   servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(90);    
 delay(1000);
 servo.detach();
}

 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
