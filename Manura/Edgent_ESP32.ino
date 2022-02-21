
#define BLYNK_TEMPLATE_ID "TMPLz3Ao51LN"
#define BLYNK_DEVICE_NAME "Manura"
#define BLYNK_AUTH_TOKEN "2xKGCa4iJ6DNJ6iz-N65PUTt0iKiRg2R"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
#define USE_WROVER_BOARD

#include "BlynkEdgent.h"
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  digitalWrite(13,pinValue);
  } 
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  digitalWrite(12,pinValue);
  } 
BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  digitalWrite(14,pinValue);
  } 
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  digitalWrite(27,pinValue);
  } 
BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  digitalWrite(26,pinValue);
  } 

BLYNK_WRITE(V5)
{
  int pinValue = param.asInt();
  digitalWrite(25,pinValue);
  } 
BLYNK_WRITE(V6)
{
  int pinValue = param.asInt();
  digitalWrite(33,pinValue);
  } 
BLYNK_WRITE(V7)
{
  int pinValue = param.asInt();
  digitalWrite(32,pinValue);
  } 

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(32,OUTPUT);
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
