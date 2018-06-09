// Sketch for driving the following components:
// Sparkfun Pro Micro board - https://ebay.to/2l3fNPL
// L298N Board - https://amzn.to/2l0zbfS
// Worm Gear Motor - https://amzn.to/2l0DGHC
// Questions?  Email pascal.girard@jhu.edu
// Todo:  Calibrate feedings by changing FeedSpeed and Delay. How much does one full revolution deliver?

// Read: http://bit.ly/2kYOFBa

int enB = 9;          // Pins
int in3 = 8;          // ... 
int in4 = 7;          // ...

int FeedSpeed = 200;  // Set speed to 200 out of possible 0~255 range (high)
int Seconds = 2;      // With a 4 second interval between feedings, that's 10 feedings per minute for testing
int Minutes = 12*60;  // Feed every 12 hours

void setup()
{
  // set all the motor control pins to outputs and motor is off
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT); digitalWrite(in3, LOW);
  pinMode(in4, OUTPUT); digitalWrite(in4, LOW);
  analogWrite(enB, FeedSpeed);
}
void Feed()
{
  // turn on motor B
  digitalWrite(in3, HIGH);
  delay(Seconds*1000);  // Feed for "Seconds"
  // now turn off motor
  digitalWrite(in3, LOW); 
}
void loop()
{
  Feed();
  delay(4000);   // At some point convert this to Minutes*(1000*60)
}
