# project-DE2
Repository for our team working on the project in the summer semester.
# Project in C
Topic: Solar panel monitoring and optimization

# Team members
 Ondřej Pulpit (responsible for programming C) 
 
 Petr Horáček (responsible for GitHub, programming C)
 
 Jan Dedera (responsible for programming C, circuit design)
 
 Patrik Bachorec (responsible for GitHub, programming C)

# Description
This project focuses on the design and implementation of an embedded system for monitoring and optimizing the performance of solar panels. The goal is to create a device capable of collecting real-time data on solar radiation, energy output, and panel efficiency, displaying this data on an OLED screen, and enabling analysis to improve the overall performance of the solar system.

The system is built on the Arduino Uno platform and integrates several key components. A solar panel simulates energy production, a servo motor optimizes the panel's orientation towards the sun, an OLED display presents the measured data, and a current sensor monitors energy consumption or output. A joystick is included for manual control, and all components are connected using a breadboard, allowing for easy prototyping and modifications.

The project’s key features include the ability to monitor data on solar radiation, energy output, and efficiency, optimize the panel's orientation using the servo motor, display current values on the OLED screen, and ensure simple construction through the use of a breadboard. 

# Hardware description
The hardware setup for this project is built around the Arduino Uno platform. It processes sensor data, controls the servo motor, and communicates with the OLED display. The components are connected using a breadboard for easy prototyping and wiring. The solar panel is used to simulate energy generation and provides real-time data for monitoring and analysis. Its position is adjusted by a servo motor. An OLED display is integrated into the system to present data, including current, voltage, and the panel's orientation. The display uses the I2C communication protocol. To measure energy consumption or output, a current sensor (ACS712) is employed. This sensor provides real-time current readings, which are processed by the Arduino for monitoring and optimization purposes. A joystick is included in the system to enable manual control of the panel's position if needed. 

Describe your implementation and include block or circuit diagram

![circuit_image (4)](https://github.com/user-attachments/assets/138e0fb0-c242-43c7-8115-bb602196505d)
In this project, we used following resources:

* Solar panel

* Current sensor

* I2C OLED display

* Ardruino uno

* Servo-motor

* Joystick

* Breadboard

* Resistor 

* LED diode

# Code structure

```plaintext
DE2_Project       
├── include         
├── lib          
│   ├── acs712
│   │   ├── acs712.c
│   │   └── acs712.h
│   ├── adc
│   │   ├── adc.c
│   │   └── adc.h
│   ├── measurement
│   │   ├── measurement.c
│   │   └── measurement.h
│   ├── oled        
│   │   ├── oled.c
│   │   ├── oled.h
│   │   └── font.h
│   ├── servo
│   │   ├── servo.c
│   │   └── servo.h
│   ├── timer
│   │   ├── timer.c
│   │   └── timer.h
│   ├── twi           
│   │   ├── twi.c
│   │   └── twi.h
│   ├── uart           
│   │   ├── uart.c
│   │   └── uart.h
├── src            
│   └── main.c
├── test          
└── platformio.ini
```
  
# References
For OLED display were used libraries from this course 
https://github.com/tomas-fryza/avr-course/tree/master/lab6-i2c#part4

For analog-digital converison was used and modified code from this site 
https://controllerstech.com/avr-tutorial-5-how-to-use-adc/?fbclid=IwZXh0bgNhZW0CMTEAAR27_foWSF4OlkPb-ShHUU9OzTmkm-_3d9HVtNByBWgLn7uGfFMeP0cDFrw_aem_m_QVIuPIvK1ps0oYTS7A0g

