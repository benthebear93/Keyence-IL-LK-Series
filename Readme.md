# IL and LK series Keyence
## Read distance data from IL & LK-G5000 laser sensor from Keyence

## [Table of Contents(IL_)](#table-of-contents)

- [Network Settings](#network-settings)
- [Keyence Ethernet IP Address Setting](#keyence-ethernet-ip-address-setting)
	
- [Keyence Laser Sensor Data Check](#keyence-laser-sensor-data-check)

- [Keyence Laser Sensor ROS](#keyence-laser-sensor-ROS)

## Network Settings
### Keyence Ethernet IP address setting
Using Keyence Ethernet communication module (DL-EN1), configure static ip address.  
configuration program (https://www.keyence.com/downloads/?mode=so&q=DL-EN1&o=0)
<img width="398" alt="ifconfig" src="https://user-images.githubusercontent.com/34788458/86210593-d5de2d80-bbaf-11ea-9380-53ac167bb592.PNG">
## Keyence Laser Sensor Data Check
Using open serial communication protocol test program J1C (http://www.j1lab.com/)  
Find out Data protocol.  

<img width="695" alt="check" src="https://user-images.githubusercontent.com/34788458/86210515-b6df9b80-bbaf-11ea-9e87-5a56988d6632.PNG">

<img width="696" alt="J1" src="https://user-images.githubusercontent.com/34788458/86210591-d4ad0080-bbaf-11ea-8032-c8886fa0fb03.PNG">

## Keyence Laser Sensor ROS(only IL-Series)
18.04 / melodic
publish laser sensor data ("laser")

## LK-G5001

reference : LK-G5000_measurement_protocol.xlsx