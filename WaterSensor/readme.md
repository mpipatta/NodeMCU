# Ultrasonic sensor SR04
File: Ultrasonic.ino

In this setup, you will use your NodeMCU to read distance from SR04, and display the distance on the serial monitor in 30-second intervals. 


You will need:

- NodeMCU v2 cp2102 
- SR04 (Ultrasonic sensor)
- MicroUSB
- Jumper wires 4x(F-F)

<b>1. Set up NodeMCU:</b><br>
Please follow the instructions available at the bottom of this page https://github.com/ICECapstone/Blink to set up your NodeMCU. 

<b>2. Physical connections: </b><br>
SR04 Vcc -> 5V from nodeMCU Vcc <br>
SR04 Ground -> Ground from NodeMCU ground <br>
SR04 TRIG pin -> GPI12 of NodeMCU <br>
SR04 ECHO pin -> GPI13 of NodeMCU <br>

![](https://raw.githubusercontent.com/mpipatta/NodeMCU/master/images/WaterSensor.png)
