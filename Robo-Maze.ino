// pin initialization for front ultrasonic senosr
int trigger_pin1 = 2;
int echo_pin1 = 3;
// pin initialization for left ultrasonic sensor
int trigger_pin2 = 12 ;
int echo_pin2 = 13;
// pin initialization for right ultrasonic sensor
int trigger_pin3 = 4;
int echo_pin3 = 5;

//right motor
int rm1 = 9;
int rm2 = 10;
int en1 = 11; // enable (PWM) 

//left motor
int lm1 = 7;
int lm2 = 8;
int en2 = 6; // enable (pwm)

void setup()
{
  //front sensor
  pinMode(trigger_pin1, OUTPUT);
  pinMode(echo_pin1, INPUT);
  //left sensor
  pinMode(trigger_pin2, OUTPUT);
  pinMode(echo_pin2, INPUT);
  //right sensor
  pinMode(trigger_pin3, OUTPUT);
  pinMode(echo_pin3, INPUT);
  //right motor
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(en1, OUTPUT);
  //left motor
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(en2, OUTPUT);
  Serial.begin(9600); // set serial baud rate to 9600
}

int front_sensor() //front ultraonic sensor
{
  digitalWrite(trigger_pin1, LOW);
  delay(100);
  digitalWrite(trigger_pin1, HIGH);
  delay(10);
  digitalWrite(trigger_pin1, LOW);
  long duration1 = pulseIn(echo_pin1, HIGH);
  int distance1 = duration1 * 0.034 / 2;
  if (distance1 > 100) {
    distance1 = 0;
  }
  return distance1;
}

int left_sensor() // left ultrasonic sensor
{
  digitalWrite(trigger_pin2, LOW);
  delay(100);
  digitalWrite(trigger_pin2, HIGH);
  delay(10);
  digitalWrite(trigger_pin2, LOW);
  long duration2 = pulseIn(echo_pin2, HIGH);
  int distance2 = duration2 * 0.034 / 2;
  if (distance2 > 100) {
    distance2 = 0;
  }
  return distance2;
}

int right_sensor() //right ultrasonic sensor
{
  digitalWrite(trigger_pin3, LOW);
  delay(100);
  digitalWrite(trigger_pin3, HIGH);
  delay(10);
  digitalWrite(trigger_pin3, LOW);
  long duration3 = pulseIn(echo_pin3, HIGH);
  int distance3 = duration3 * 0.034 / 2;
  if (distance3 > 100) {
    distance3 = 0;
  }
  return distance3;
}

void right() // move the robot to the right
{
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  analogWrite(en1, 70);
  analogWrite(en2, 70);
  Serial.println("===============");
  Serial.println("RIGHT");
}

void left() // move the robot to the left
{
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  analogWrite(en1, 70);
  analogWrite(en2, 70);
  Serial.println("===============");
  Serial.println("LEFT");
}

void forward() // move the robot forward
{
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  analogWrite(en1, 70);
  analogWrite(en2, 70);
  Serial.println("===============");
  Serial.println("FORWARD");
}

void backward() // move the robot backward
{
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  analogWrite(en1, 70);
  analogWrite(en2, 70);
  Serial.println("===============");
  Serial.println("BACKWARD");
}
void stops() // stop the robot
{
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  analogWrite(en1, 0);
  analogWrite(en2, 0);
  Serial.println("===============");
  Serial.println("STOP");
}


void loop() // main loop
{
  int f = front_sensor(); // front sensor proximity  
  int l = left_sensor();// left sensor proximity
  int r = right_sensor(); // right sensor proximity

  Serial.print("left: ");
  Serial.print(l);
  Serial.print("forward: ");
  Serial.print(f);
  Serial.print("right: ");
  Serial.println(r);
  Serial.println("____________________________________________");

  if (l == 0 || r == 0 || f == 0) // if any sensor is out of range
  {
    stops();
    delay(100); // to counter vehicle momentum small delay is used
  }
  else if ((f>0)  && (f < 15)) // if any obstacle within 15 cm
  {
    stops();
    delay(100);

    if (r > l) // if right proximity is greater than left proximity
    {
      right(); // move right
      delay(500); // set this dely according to the time taken by bot to rotate left 90 degree
    } 
    else
    {
      left();
      delay(500); // set this delay according to the time taken by bot to rotate left 90 degree
    }
  } 
  else 
  { 
    forward(); // move forward
    delay(100);
  }
}
