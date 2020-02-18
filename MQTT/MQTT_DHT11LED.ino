#include "DHT.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
#define RED 3
DHT dht(DHTPIN, DHTTYPE);

int ledState = LOW;
long now=millis();
long lastMeasure=0;
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFipassword";
const char* mqttServer = "m11.cloudmqtt.com";
const int mqttPort = 13436; // add your mqtt port (number only, no quotation)
const char* mqttUser = "your mqtt username"; 
const char* mqttPassword = "your mqtt password";

const char* topicT ="/GROUPNAME/temp";
const char* topicH ="/GROUPNAME/humidity";
const char* topicLED ="/GROUPNAME/LED";
//replace "GROUPNAME" with your groupname....
//kookkook, fogponic, avl, weebstone, igloo, cheezyavocado


WiFiClient espClient;
PubSubClient client(espClient);


void setup() {
  Serial.begin(9600);
  
  dht.begin();
  
  pinMode(RED, OUTPUT);
  digitalWrite(RED, ledState);
  
  delay(10000);
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  Serial.println(":-)");
  Serial.println("WiFi connected");

  connectToMqttServer();
}


void connectToMqttServer() {
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
      Serial.println("connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }

  client.subscribe(topicLED);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  ledState = !ledState;
  digitalWrite(RED, ledState);
  Serial.println("-----------------------");
}
 

    
void loop() {
  now = millis();
  if (now - lastMeasure > 10000) {
    lastMeasure = now;

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) ) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    static char temperatureTemp[7];
    dtostrf(t, 6, 2, temperatureTemp);
    static char humidityTemp[7];
    dtostrf(h, 6, 2, humidityTemp);
    client.publish(topicT, temperatureTemp);
    client.publish(topicH, humidityTemp);
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t Temperature: ");
    Serial.print(t);
    Serial.println(" *C ");
  }
  client.loop();
  
}
