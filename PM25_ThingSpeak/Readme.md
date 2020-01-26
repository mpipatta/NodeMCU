# PM2.5 with ThingSpeak
File: pm25_ThingSpeak.ino

In this setup, you will use your NodeMCU to read PM1, PM2.5 and PM10 level from PMS5003, and display them on ThingSpeak in 20-second intervals. 


You will need:

- NodeMCU v2 cp2102 (~$3)
- PMS5003 (~$14)
- MicroUSB
- Jumper wires

<b>1. Set up NodeMCU:</b><br>
Please follow the instructions available at the bottom of this page https://github.com/ICECapstone/Blink to set up your NodeMCU. 

<b>2. Physical connections: </b><br>
PMS5003 Vcc -> 5V from nodeMCU Vcc <br>
PMS5003 Ground -> Ground from NodeMCU ground <br>
PMS5003 TX -> GPIO2 of NodeMCU <br>

![](https://raw.githubusercontent.com/mpipatta/PM2.5/master/images/PM25config.png)


<b>3. Set up ThingSpeak: </b><br>
Please set up your ThingsSpeak channel on www.thingspeak.com.  Gather your 'API key' and 'Channel ID' for use in the code.  Under Channel setting, enable three fields for data gathering (field 1: PM2.5; field 2: PM1.0; field3: PM10).

![](https://raw.githubusercontent.com/mpipatta/PM2.5/master/images/TSAPI.png)

<b>4. Upload the code to your NodeMCU (file, "PM25_TS.ino"): </b><br>
Note: I slightly modified the original code (https://learn.adafruit.com/pm25-air-quality-sensor) to allow displaying data online via ThingSpeak. You will need to replace:
- ssid with your ssid
- password with your Wi-Fi password
- myWriteAPIKey with your ThingSpeak's writeAPI 
- myChannelNumber with your ThingSpeak's channel number

<b>5. Enjoy: </b></br>
Once you upload the code, your NodeMCU starts gathering data from PMS5003, and data are displayed on ThingsSpeak.  

![data](https://raw.githubusercontent.com/mpipatta/PM2.5/master/images/TSvisual.png)

