#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
#define MQTT_SERVER  "192.168.43.208"   /// example 192.168.0.19
const char* ssid =         "Huawei Mate 10";
const char* password =    "1234554321";
long now = millis();
long lastMeasure = 0;
//String value = "";
char* Topic = "inTopic";

WiFiClient wifiClient;
/*PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;*/

void setup() {
 
  Serial.begin(9600);
  delay(100);
WiFi.begin(ssid,password);
//attempte to connect to wifi network and then connect to the MQTT broker
reconnect();
delay(2000);
 
 }
PubSubClient client(MQTT_SERVER,1883, callback, wifiClient);
void loop() {

  if (!client.connected() && WiFi.status()== 3) {reconnect();}
  client.loop();
  delay(20);
  }
void callback(char* topic, byte* payload, unsigned int length) {
String topicStr = topic;
  // Switch on the LED if an 1 was received as first character
  if (payload[0] == '0') {
    client.publish("outTopic","Realy 1 is ON");
    Serial.print("0");} 

  if (payload[0] == '1') {
    client.publish("outTopic","Realy 1 is OFF");
    Serial.print("1");}
    
  if (payload[0] == '2') {
    client.publish("outTopic","Realy 2 is ON");
    Serial.print("2");} 

  if (payload[0] == '3') {
    client.publish("outTopic","Realy 2 is OFF");
    Serial.print("3");}
    
  if (payload[0] == '4') {
    client.publish("outTopic","Realy 3 is ON");
    Serial.print("4");} 

  if (payload[0] == '5') {
    client.publish("outTopic","Realy 3 is OFF");
    Serial.print("5");}
    
  if (payload[0] == '6') {
    client.publish("outTopic","Realy 4 is ON");
    Serial.print("6");} 

  if (payload[0] == '7') {
    client.publish("outTopic","Realy 4 is OFF");
    Serial.print("7");}
}
void reconnect() {
      // Loop until we're reconnected
         if(WiFi.status() != WL_CONNECTED){
         while (WiFi.status() != WL_CONNECTED){
              delay(500);
                                              }
                                           }
    //make sure we are connected
      if(WiFi.status() == WL_CONNECTED){
    //loop until we are recennected to mqtt broker
     while(!client.connected()){
     String clientName;
    clientName +="esp8266-";
    uint8_t mac[6];
    WiFi.macAddress(mac);
    clientName += macToStr(mac);
    if(client.connect((char*) clientName.c_str())){
      Serial.print("\tMT00 Connected");
      client.subscribe(Topic);
      }
      //otherwise print failed for debugging
      else{Serial.println("\tFailed.");abort();}
    }
  }
}
//generate unique name for MAC Add
String macToStr(const uint8_t* mac){
  String result;
  for (int i = 0; i<6;++i){
    result += String(mac[i],16);
    if(i<5){
      result += ';';
      }
    }
    return result;
  }
