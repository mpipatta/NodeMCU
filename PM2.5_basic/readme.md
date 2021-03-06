# PM2.5 
File: pm25_basic.ino

In this setup, you will use your NodeMCU to read PM1, PM2.5 and PM10 level from PMS5003. 

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

<b>3. Upload the code to your NodeMCU (file, "PM25_basic.ino"): </b><br> The original code is available at (https://learn.adafruit.com/pm25-air-quality-sensor).

<b>4. Enjoy: </b></br>
Once you upload the code, your NodeMCU starts gathering data from PMS5003, and data are displayed on the serial interface.  

![](https://raw.githubusercontent.com/mpipatta/PM2.5/master/images/PM25readings.png)

