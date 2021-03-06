//Vcc PIN1 (5V)
//Ground PIN2 (same ground as NodeMCU)
//Tx PIN5 ==> GPIO2
//SoftwareSerial(rxPin, txPin)
//rxPin: the pin on which to receive serial data
//txPin: the pin on which to transmit serial data

#include <SoftwareSerial.h>
SoftwareSerial pmsSerial(2,3);
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "Your SSID";
const char* password = "Your SSID password";
const char * myWriteAPIKey = "Write API Key";
unsigned long myChannelNumber = 111111; //replace 111111 with your Channel number
const char* server = "api.thingspeak.com";
WiFiClient client;

void setup() {
  Serial.begin(9600);
  //pmsSerial.begin(9600);
  delay(10000);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
      while (WiFi.status() != WL_CONNECTED) {
            delay(250);
            Serial.print(".");
     }
  Serial.println(":-)");
  Serial.println("WiFi connected");
 
}
 
struct pms5003data {
  uint16_t framelen;
  uint16_t pm10_standard, pm25_standard, pm100_standard;
  uint16_t pm10_env, pm25_env, pm100_env;
  uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
  uint16_t unused;
  uint16_t checksum;
};
 
struct pms5003data data;
    
void loop() {

  if (readPMSdata(&pmsSerial)) {
    // reading data was successful!
    Serial.println();
    Serial.println("---------------------------------------");
    Serial.println("Concentration Units (standard)");
    Serial.print("PM 1.0: "); Serial.print(data.pm10_standard);
    Serial.print("\t\tPM 2.5: "); Serial.print(data.pm25_standard);
    Serial.print("\t\tPM 10: "); Serial.println(data.pm100_standard);
    Serial.println("---------------------------------------");
    Serial.println("Concentration Units (environmental)");
    Serial.print("PM 1.0: "); Serial.print(data.pm10_env);
    Serial.print("\t\tPM 2.5: "); Serial.print(data.pm25_env);
    Serial.print("\t\tPM 10: "); Serial.println(data.pm100_env);
    Serial.println("---------------------------------------");
    Serial.print("Particles > 0.3um / 0.1L air:"); Serial.println(data.particles_03um);
    Serial.print("Particles > 0.5um / 0.1L air:"); Serial.println(data.particles_05um);
    Serial.print("Particles > 1.0um / 0.1L air:"); Serial.println(data.particles_10um);
    Serial.print("Particles > 2.5um / 0.1L air:"); Serial.println(data.particles_25um);
    Serial.print("Particles > 5.0um / 0.1L air:"); Serial.println(data.particles_50um);
    Serial.print("Particles > 10.0 um / 0.1L air:"); Serial.println(data.particles_100um);
    Serial.println("---------------------------------------");

    Serial.println("....writing to Thingspeak...");
    if (client.connect(server, 80)) {
      Serial.println("Connected to thingspeak");
      ThingSpeak.setField(1,data.pm25_standard );
      ThingSpeak.setField(2,data.pm10_standard );
      ThingSpeak.setField(3,data.pm100_standard );
      ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
      delay(10000);
  }
   
  }  
}
 
boolean readPMSdata(Stream *s) {
  if (! s->available()) {
    return false;
  }
  
  // Read a byte at a time until we get to the special '0x42' start-byte
  if (s->peek() != 0x42) {
    s->read();
    return false;
  }
 
  // Now read all 32 bytes
  if (s->available() < 32) {
    return false;
  }
    
  uint8_t buffer[32];    
  uint16_t sum = 0;
  s->readBytes(buffer, 32);
 
  // get checksum ready
  for (uint8_t i=0; i<30; i++) {
    sum += buffer[i];
  }
 
  uint16_t buffer_u16[15];
  for (uint8_t i=0; i<15; i++) {
    buffer_u16[i] = buffer[2 + i*2 + 1];
    buffer_u16[i] += (buffer[2 + i*2] << 8);
  }
 
  // put it into a nice struct :)
  memcpy((void *)&data, (void *)buffer_u16, 30);
 
  if (sum != data.checksum) {
    Serial.println("Checksum failure");
    return false;
  }

  return true;
}
