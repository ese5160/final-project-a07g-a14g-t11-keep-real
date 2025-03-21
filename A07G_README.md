<!--
 * @Author: wyiwei1 wyiwei@seas.upenn.edu
 * @Date: 2025-03-18 22:48:58
 * @LastEditors: wyiwei1 wyiwei@seas.upenn.edu
 * @LastEditTime: 2025-03-21 14:35:20
 * @FilePath: \final-project-a07g-a14g-t11-keep-real\A07G_README.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
# a07g-exploring-the-CLI

* Team Number:11
* Team Name: Keep Real
* Team Members: Binsheng Zhang, Yiwei Wang
* GitHub Repository URL: https://github.com/ese5160/final-project-a07g-a14g-t11-keep-real.git
* Description of test hardware: SAMW25, Air Quality Sensor(BME680), Servo(SER0006), Matrix Keypad, Fingerprint Sensor, LCD Screen, Active Buzzer, laptop + Windows  

# 1. Software Architecture

## 1. Hardware Requirements Specification (HRS)

### 1.1 Overview

The project's hardware comprises a fingerprint sensor, a secure 4x4 matrix keypad for password input, and an SG90 servo motor for accurate lock simulation. The air quality sensor is used to detect data such as temperature, humidity, and air quality inside the house and display it on an LCD screen. A buzzer is used to trigger an alarm when necessary.

### 1.2 Definitions, Abbreviations

**ST7735**: Single-chip controller/driver for 262K-color, graphic type TFT-LCD.
**4x4 matrix keypad**: Traditional input method.
**SG90**: Servo motor controlled by PWM.
**BME680**: Environmental Sensor that combines a gas sensor with temperature, humidity and barometric pressure sensing

### 1.3 Functionality

- HRS 01 – Microcontroller Core
    - The project will focus on the SAM W25 microcontroller, offering Wi-Fi connectivity and powerful data processing to manage sensor inputs and control output devices. Interfaces include SPI, I2C, and UART, with an operating voltage of 3.3V.
- HRS 02 – Door Opening and Closing
    - The system shall be capable of accurately controlling SG90's rotation angle via PWM signals to simulate the locking and unlocking of a door. Connection for SG90: PWM, Voltage: 5V
- HRS 03 – Password Input
    - 4x4 matrix keypad shall be used to get the password input. Connection for Keypad：GPIO*8
- HRS 04 – Air Quality Monitoring
    - BME680 shall be able to measure air quality, temperature, humidity, and atmospheric pressure. Connection for BME680: I2C, Voltage: 3.3V
- HRS 05 – Fingerprint Detection
    - The fingerprint sensor shall be capable of detecting the user's fingerprint input and performing fingerprint storage and comparison. Connection for Fingerprint Sensor: UART, Voltage: 5V
- HRS 06 - Data Display
    - ST7735 shall be able to display air quality information and feedback from entered passwords. Connection for ST7735: SPI, Voltage: 3.3V
- HRS 07 - Buzzer Warning
    - The buzzer shall alarm if the password or fingerprint is entered incorrectly too many times. Connection for ST7735: GPIO, Voltage: 3.3V

## 2. Software Requirements Specification (SRS)

### 2.1 Overview

The software is responsible for managing user input and controlling hardware behavior, including the storage, recognition, and comparison of fingerprints and passwords. If the number of incorrect inputs exceeds the limit, the system will generate an alarm and control the locking and unlocking of the door. Additionally, the software reads parameters from the air quality sensor, displays air quality information on the LCD screen, and finally uploads alarm messages and air quality data to the cloud. Users can also control the locking and unlocking of the door remotely via the cloud.

### 2.2 Users

Suitable for users with large households, who care about indoor air quality, and prefer not to carry keys when going out.  

### 2.3 Definitions, Abbreviations

N/A

### 2.4 Functionality

- SRS 01 – Fingerprint Detection
    - When the user presses "A" on the keypad and enters a password, the software shall enter fingerprint enrollment mode, using the fingerprint sensor to capture and store the user's fingerprint.
    - When the user presses "B" on the keypad, the software shall switch to fingerprint recognition mode to capture the fingerprint and compare it with the stored fingerprints.
- SRS 02 – Password Input
    - When the user presses "C" on the keypad, the software shall enter password input mode and compare the entered password with the stored password.
    - When the user presses "D" on the keypad and enters a password, the software shall switch to password modification mode, saving the entered password as the new password.
- SRS 03 – Door Unlocking or Alarm
    - If the fingerprint or password matches correctly, the system shall control the servo motor to rotate, simulating unlocking.
    - If the user enters an incorrect fingerprint or password more than three times, the system shall send an alert notification to the cloud and activate the buzzer alarm.
    - If the user sends an unlock signal from the cloud, the system shall be able to recognize and execute the unlocking operation.
- SRS 04 – Air Quality Detection
    - The system shall measure air quality every 10 minutes, including humidity, temperature, and air pressure, and upload this data to the cloud.
- SRS 05 – Information Display
    - By default, the LCD screen shall display the current indoor temperature, humidity, and air pressure information.
    - If the user enters fingerprint input mode, the LCD screen shall display a prompt to guide the user to start entering their fingerprint.
    - If the user enters password input mode, the LCD screen shall display a prompt to guide the user to start entering the password.

## 3. Block Diagram

![Block Diagram](./images/7_1_Task_Diagram.png)

## 4. Flowcharts

### 4.1 Keypad 

![Keypad Flowchart](./images/7_2_Keypad_FlowChart.png)