# I-See: Assistance Robot for the Blind

![Project Status](https://img.shields.io/badge/status-active-brightgreen.svg)
![License](https://img.shields.io/badge/license-open--source-blue.svg)

## Overview

**I-See** is a robotic system designed to assist visually impaired individuals with safe navigation. Combining object detection, obstacle avoidance, and motor control, I-See acts as a real-time guide for users. The system is powered by **DC motors**, **Arduino boards**, and a **Raspberry Pi 3** to enable interaction between the environment and the user.

This project enables the robot to recognize objects in real-time and provide navigation assistance.

## Features

- **Object Detection**: Python-based object recognition on Raspberry Pi.
- **Ultrasonic Sensor Control**: Ultrasonic sensors, managed by Arduino boards, help detect and avoid obstacles.
- **Motor and Servo Control**: DC motors provide movement, and servo motors ensure precise adjustments.

## Hardware

- **6 x DC Motors** (12V, 100 RPM Johnson geared)
- **2 x Arduino Uno Boards** for motor and sensor control
- **Raspberry Pi 3 with 1GB RAM** for processing object detection
- **Ultrasonic Sensors** for obstacle detection
- **Servo Motors** for additional mechanical functions

## Software Components

- **Arduino Sketches**:
  - `ultrasonic_control.ino`: Controls the ultrasonic sensors.
  - `pwm_servo.ino`: Controls PWM signals for the servo motors.
  
- **Raspberry Pi Code**:
  - `I-See Object Recognition.py`: Python script for object detection using image processing.

## Technologies Used

- **Python**: Object detection using OpenCV.
- **C++ (Arduino)**: Motor control and sensor interfacing.
- **Raspberry Pi**: Central processing unit for object recognition.

## Getting Started

### Prerequisites

You will need:

- **Arduino IDE** to upload `.ino` files to the Arduino Uno boards.
- **Python 3** installed on the Raspberry Pi.
- **OpenCV** library installed on the Raspberry Pi for object detection.

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/Kanad-Patel/I-See.git
    cd I-See
    ```

2. **Arduino Setup**:
   - Connect the ultrasonic sensors and motor drivers to the Arduino Uno.
   - Upload `ultrasonic_control.ino` to one Arduino for sensor control.
   - Upload `pwm_servo.ino` to another Arduino for servo motor control.

3. **Raspberry Pi Setup**:
   - Ensure OpenCV and required Python packages are installed.
   - Run the object detection script on Raspberry Pi:
     ```bash
     python3 I-See\ Object\ Recognition.py
     ```

### Running the Robot

- After wiring and uploading the code to both Arduino boards and the Raspberry Pi, power on the system.
- The robot will begin detecting objects and avoiding obstacles, guiding the user in real-time.

## Demo

You can view a demo of the project in action here:

[![Demo Video](https://img.shields.io/badge/Watch%20Video-Demo-red)](https://github.com/Kanad-Patel/I-See/blob/main/Demo.mp4)

## Contribution

Contributions are welcome! Please fork the repository, create a feature branch, and submit a pull request for any improvements or bug fixes.

## License

This project is open-source and licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
