#define MQ2pin1 (A8)
#define MQ2pin2 (A9)

// pin init
int pwm1 = 9;
int dir1 = 8;
int pwm2 = 11;
int dir2 = 10;

int wave1 = 7;
int wave2 = 6;

int pir_val;
int pir_val2;
float sensorValue1;  //variable to store sensor value
float sensorValue2;  //variable to store sensor value

void exhaust_on();
void exhaust_off();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pwm1, OUTPUT); // PWM
  pinMode(dir1, OUTPUT); // DIR
  pinMode(pwm2, OUTPUT); // PWM
  pinMode(dir2, OUTPUT); // DIR

  pinMode(wave1, INPUT);    //Proximity sensor
  Serial.println("Gas sensor warming up!");
  delay(20000); // allow the MQ-6 to warm up

}

void loop() 
{
  // put your main code here, to run repeatedly:
  pir_val = digitalRead(wave1);
  pir_val2 = digitalRead(wave2);
//Serial.println(pir_val);
if(pir_val == 0)
{
  if(pir_val2 == 0)
  {
      exhaust_on(40);
      delay(5000);
  }
}
else
  exhaust_off(0);
//exhaust_on(25);
 // delay(2000); // allow the MQ-6 to warm up
  
  sensorValue1 = analogRead(MQ2pin1); // read analog input pin 0
  sensorValue2 = analogRead(MQ2pin2); // read analog input pin 0

  Serial.print("Sensor Value 1: ");
  Serial.println(sensorValue1);
  Serial.print("Sensor Value 1: ");
  Serial.println(sensorValue2);

  while(sensorValue1 > 300 || sensorValue2 > 300)
  {
    Serial.print(" | Smoke detected!");
    exhaust_on(40);
    break;
  }


}

void exhaust_on(int spd) // 1.5m pwm approx 118
{
  Serial.println("Smoke!Smoke! Go away!");
  digitalWrite(dir1, HIGH);
  analogWrite(pwm1, spd);
  digitalWrite(dir2, HIGH);
  analogWrite(pwm2, spd);
  delay(5000);

}

void exhaust_off(int spd) // 1.5m pwm approx 118
{
  Serial.println("No smoke");
  digitalWrite(dir1, LOW);
  analogWrite(pwm1, spd);
  digitalWrite(dir2, LOW);
  analogWrite(pwm2, spd);

}
