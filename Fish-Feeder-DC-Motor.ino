// Sketch for driving the following components:
// Sparkfun Pro Micro board - https://ebay.to/2l3fNPL
// L298N Board - https://amzn.to/2l0zbfS
// Worm Gear Motor - https://tinyurl.com/y2lurj6c
// Add https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json to 
// Arduino->Preferences-> Additional Boards Manager URLs
// Questions?  Email pascal.girard@jhu.edu
// Todo:  Calibrate feedings by changing FeedSpeed, FeedTime, and FeedInterval. How much does one full revolution deliver?

// Read: http://bit.ly/2kYOFBa

#define MILLISECOND   1
#define SECOND        MILLISECOND * 1000
#define MINUTE        60 * SECOND
#define HOUR          60 * MINUTE
#define DAY           24 * HOUR

int enB = 9;          // PWM pin that alters speed
int in3 = 8;          //                     In3
int in4 = 7;          //              High       Low
                      //           |---------|--------|
                      //      High |   ?     | Reverse|
                      // In4       |------------------|
                      //       Low | Forward |   Off  |
                      //           |---------|--------|
                      
int FeedSpeed = 200;            // Set speed to 200 out of possible 0~255 range (high)
int FeedTime = 2 * SECOND;      // With a 4 second interval between feedings, that's 10 feedings per minute for testing
int FeedInterval = 6 * HOUR;    // Feed every 6 hours
int count = 0;

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
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
  delay(FeedTime);  // Feed for "Seconds"
  // now turn off motor
  digitalWrite(in3, LOW); 
}

void loop()
{
  Feed();
  Serial.print("Feed Count: ");
  Serial.println(count++);
  delay(FeedInterval);
}
