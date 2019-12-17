//  Define Motors
#define motor_left 4
#define motor_right 2

// Define sensors
#define sensor_left A0
#define sensor_right A3

//Include Adafruit Motor Shield Library
#include <AFMotor.h>

// create class of Adafruit Motor Shield
// Define motors on the motorcontroller shield
AF_DCMotor left_motor(motor_left, MOTOR34_8KHZ);
AF_DCMotor right_motor(motor_right,MOTOR12_8KHZ);

void setup() {
  Serial.begin(9600);
  
  //Defining Sensor pins to be input
  pinMode(sensor_left, INPUT);
  pinMode(sensor_right, INPUT);

  //Defining builtin LED to indicate a GO
  pinMode(LED_BUILTIN, OUTPUT);

  //  Defining Motor Speeds
  left_motor.setSpeed(255);
  right_motor.setSpeed(255);
}

void loop() {
  if (analogRead(sensor_left) > 400)  {
    left_motor.run(RELEASE);
    Serial.println("LEFT");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
  if (analogRead(sensor_right) > 400) {
    right_motor.run(RELEASE);
    Serial.println("RIGHT");
    digitalWrite(LED_BUILTIN, HIGH);
    
  }
  
  else  {
    left_motor.run(FORWARD);
    right_motor.run(FORWARD);
    Serial.println("FORWARD");
    digitalWrite(LED_BUILTIN, LOW);
  }

}
