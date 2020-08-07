#include <ThingSpeak.h>               // add librery
#include <WiFi.h>
#include "TrafficLight.h"
#include "Timer.h"

WiFiClient  client;
unsigned long counterChannelNumber =1098402;                // Channel ID
const char * myCounterReadAPIKey = "N3C3VU2XJHR8I7DI";      // Read API Key
const int FieldNumber1 = 1;                                 // The field you wish to read
const int FieldNumber2 = 2;   // The field you wish to read
// variables
int PIN_GREEN = 4;
int PIN_YELLOW = 16;
int PIN_RED = 17;
int DELAY_GREEN = 5000;
int DELAY_YELLOW = 2000;
int DELAY_RED = 5000;
Timer timer;
TrafficLight trafficLight(PIN_GREEN, PIN_YELLOW, PIN_RED);
void green_light()
{
  digitalWrite(PIN_GREEN, HIGH);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_RED, LOW);
}

void yellow_light()
{
  digitalWrite(PIN_GREEN, LOW);
  digitalWrite(PIN_YELLOW, HIGH);
  digitalWrite(PIN_RED, LOW);
}

void red_light()
{
  digitalWrite(PIN_GREEN, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_RED, HIGH);
}

void setup()
{
  pinMode(PIN_GREEN,OUTPUT);
   pinMode(PIN_YELLOW,OUTPUT);
    pinMode(PIN_RED,OUTPUT);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("Huawei Mate 10", "1234554321");                 // write wifi name & password           

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
 int A = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
 Serial.println(A);
  if (A==0) {
    trafficLight.stop();
    timer.startTimer(1000);
  }
  else{
    if (timer.isTimerReady()) {
      trafficLight.go();
    }
  }

  trafficLight.loop();
}
