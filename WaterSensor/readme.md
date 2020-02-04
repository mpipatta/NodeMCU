# Water sensor
File: WaterSensor.ino

In this setup, you will use your NodeMCU to read moisture reading from the water sensor, and display the distance on the serial monitor. 


You will need:

- NodeMCU v2 cp2102 
- Water sensor (M0088)
- MicroUSB
- Jumper wires 3x(F-F)

<b>1. Set up NodeMCU:</b><br>
Please follow the instructions available at the bottom of this page https://github.com/ICECapstone/Blink to set up your NodeMCU. 

<b>2. Physical connections: </b><br>
M0088 Vcc -> 5V from nodeMCU Vcc <br>
M0088 Ground -> Ground from NodeMCU ground <br>
M0088 Signal pin -> Analog pin of NodeMCU <br>


![](https://raw.githubusercontent.com/mpipatta/NodeMCU/master/images/WaterSensor.png)
