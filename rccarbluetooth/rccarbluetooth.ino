

#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(9, 10); 

AF_DCMotor m1(1, MOTOR12_1KHZ);
AF_DCMotor m2(2, MOTOR12_1KHZ);
AF_DCMotor m3(3, MOTOR34_1KHZ);
AF_DCMotor m4(4, MOTOR34_1KHZ);

char command;

void setup()
{
  bluetooth.begin(9600);  
}

void loop() {
  if (bluetooth.available() > 0) {
    command = bluetooth.read();

    Stop(); 
    
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }
  }
}

void forward()
{
  m1.setSpeed(255); 
  m1.run(FORWARD);  
  m2.setSpeed(255); 
  m2.run(FORWARD);  
  m3.setSpeed(255); 
  m3.run(FORWARD); 
  m4.setSpeed(255); 
  m4.run(FORWARD); 
}

void back()
{
  m1.setSpeed(255); 
  m1.run(BACKWARD); 
  m2.setSpeed(255); 
  m2.run(BACKWARD);
  m3.setSpeed(255); 
  m3.run(BACKWARD); 
  m4.setSpeed(255); 
  m4.run(BACKWARD); 
}

void left()
{
  m1.setSpeed(255); 
  m1.run(BACKWARD); 
  m2.setSpeed(255); 
  m2.run(BACKWARD); 
  m3.setSpeed(255); 
  m3.run(FORWARD);  
  m4.setSpeed(255); 
  m4.run(FORWARD);  
}

void right()
{
  m1.setSpeed(255);
  m1.run(FORWARD);  
  m2.setSpeed(255); 
  m2.run(FORWARD);  
  m3.setSpeed(255); 
  m3.run(BACKWARD); 
  m4.setSpeed(255); 
  m4.run(BACKWARD); 
}

void Stop()
{
  m1.setSpeed(0);  
  m1.run(RELEASE);
  m2.setSpeed(0);  
  m2.run(RELEASE); 
  m3.setSpeed(0);  
  m3.run(RELEASE); 
  m4.setSpeed(0);  
  m4.run(RELEASE); 
}
