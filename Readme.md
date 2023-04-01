# Keyence IL and LK Series Laser Sensors
## This repository provides instructions and resources for reading distance data from Keyence IL and LK-G5000 laser sensors.


## [Table of Contents](#table-of-contents)

- [Network Settings](#network-settings)
- [Keyence(IL) Ethernet IP Address Setting](#keyence-ethernet-ip-address-setting)
	
- [Keyence(IL) Laser Sensor Data Check](#keyence-laser-sensor-data-check)

- [Keyence(IL & LK-G5000) Laser Sensor ROS](#keyence-laser-sensor-ROS)

- [Keyence LK Series protocol reference](#keyence-LK-Series-Protocol)

## Network Settings
## Keyence(IL) Ethernet IP Address Setting
To begin, make sure your Keyence IL or LK-G5000 laser sensor is connected to your network using the Keyence Ethernet communication module (DL-EN1). Then, follow these steps to configure a static IP address:

1. Download the Keyence configuration program from the Keyence website.
2. Open the configuration program and enter your desired IP address and subnet mask.
3. Apply the changes and verify that the IP address has been successfully configured using the ifconfig command.

<img width="398" alt="ifconfig" src="https://user-images.githubusercontent.com/34788458/86210593-d5de2d80-bbaf-11ea-9380-53ac167bb592.PNG">

## Keyence(IL) Laser Sensor Data Check
Using open serial communication protocol test program J1C (http://www.j1lab.com/)  
Find out Data protocol.  

<img width="695" alt="check" src="https://user-images.githubusercontent.com/34788458/86210515-b6df9b80-bbaf-11ea-9e87-5a56988d6632.PNG">

<img width="696" alt="J1" src="https://user-images.githubusercontent.com/34788458/86210591-d4ad0080-bbaf-11ea-8032-c8886fa0fb03.PNG">

## Keyence IL & LK-G5000 Laser Sensor ROS Integration
This repository provides a ROS package for publishing distance data from Keyence IL and LK-G5000 laser sensors. The package has been tested on Ubuntu 18.04 with ROS Melodic.

To use the ROS package, follow these steps:
1. Clone this repository into your catkin workspace.
2. Build the ROS package using catkin_make.
3. Connect your Keyence laser sensor to your computer's Ethernet port.
4. Launch the ROS node using roslaunch keyence_laser_sensor keyence_laser_sensor.launch.
5. The node will publish distance data on the topics /laser (for IL Series) and /lk_laser (for LK Series).

## Keyence LK Series protocol reference
For more information on the data protocol used by Keyence LK-G5000 laser sensors, please refer to the LK-G5000_measurement_protocol.xlsx file included in this repository.
