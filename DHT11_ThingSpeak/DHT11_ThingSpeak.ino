#include <ESP8266WiFi.h>
#include "DHT.h"
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
#include "ThingSpeak.h"

const char* ssid = "add_your_WiFi_ssid";
const char* password = "add_your_WiFi_password";
const char * myWriteAPIKey = "add_your_thingspeak_writeAPIkey";
unsigned long myChannelNumber = 111111; //add your thingspeak channel number
const char* server = "api.thingspeak.com";
WiFiClient client;

void setup() {
  Serial.begin(9600);      // PC Arduino Serial Monitor
  //Serial1.begin(115200);   // Arduino to ESP01 Communication
  delay(10000);
  Serial.println("DHTxx test!");
  dht.begin();
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(250);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}

void loop() {
  // put your main code here, to run repeatedly: 
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    
    if (isnan(h) || isnan(t)) { h=0; t=0; }
   
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C ");
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println(" % ");
    
    Serial.println("....writing to Thingspeak...");
    if (client.connect(server, 80)) {
      Serial.println("Connected to thingspeak");
      ThingSpeak.setField(1, t);
      ThingSpeak.setField(2, h);
      ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    delay(15000);
  }
}
