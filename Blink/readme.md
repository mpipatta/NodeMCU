# Blink 
My first NodeMCU code - Blink ;-)

On your Arduino IDE, 
Go to File -> ESP8266 -> Blink

![blink](https://user-images.githubusercontent.com/11530521/50457503-8dc4c600-098e-11e9-9d1e-4c5276908c67.png)

Remember to set up your NodeMCU

1. <b>Set up your Arduino IDE </b>
Go to File->Preferences and copy the URL below to get the ESP board manager extensions: http://arduino.esp8266.com/stable/package_esp8266com_index.json Placing the http:// before the URL lets the Arduino IDE use it...otherwise it gives you a protocol error.

2. <b>Install WiFi library</b>
Go to Tools > Board > Board Manager> Type "esp8266" and download the Community esp8266 and install. 

3. <b>Set up your chip</b>
Tools -> Board -> NodeMCU 1.0 (ESP-12E Module)
Tools -> Flash Size -> 4M (3M SPIFFS)
Tools -> CPU Frequency -> 80 Mhz
Tools -> Upload Speed -> 921600
Tools-->Port--> (whatever it is)
