# Smart-Traffic-Light-Controller
📌 Overview

This project implements a Smart Traffic Light Controller using an ESP32 microcontroller. It simulates a traffic signal at a single road junction with Red, Yellow, and Green LEDs. The system also includes a pedestrian crossing button that allows pedestrians to request a safe crossing by reducing the green light duration.

This project demonstrates basic embedded systems concepts such as GPIO control, interrupt handling, timing, and traffic signal sequencing.

✨ Features
🚦 Automatic traffic light sequence (Red → Green → Yellow)
🚶 Pedestrian crossing request using a push button
⚡ Interrupt-based button detection
🟢 Configurable signal timings
💻 Serial Monitor output for debugging
🔧 Easy to modify and expand

🛠 Hardware Requirements
ESP32 Development Board
1 × Red LED
1 × Yellow LED
1 × Green LED
3 × 220 Ω Resistors
1 × Push Button
Breadboard
Jumper Wires
USB Cable

🔌 Circuit Connections
Component	ESP32 GPIO
Red LED	GPIO 25
Yellow LED	GPIO 26
Green LED	GPIO 27
Push Button	GPIO 14 (INPUT_PULLUP)

Note: Connect each LED through a 220 Ω resistor to GND. The push button is connected between GPIO 14 and GND.

⚙️ Software Requirements
Arduino IDE
ESP32 Board Package
USB Driver (if required)

📂 Project Structure
Smart-Traffic-Light-Controller/
│
├── 1_Smart_Traffic_Light_Controller.ino
├── README.md
├── Circuit_Diagram.png        (Optional)
├── Images/                    (Optional)
└── LICENSE                    (Optional)

🚀 How to Run
Install the ESP32 board package in Arduino IDE.
Open 1_Smart_Traffic_Light_Controller.ino.
Select ESP32 Dev Module from Tools → Board.
Connect the ESP32 using a USB cable.
Select the correct COM port.
Upload the code.
Open the Serial Monitor at 115200 baud.

🔄 Working Principle
The system starts with the traffic light in the Red state.
The signal automatically cycles through:
🟢 Green
🟡 Yellow
🔴 Red
If a pedestrian presses the button during the green phase:
An interrupt detects the button press.
The green light duration is shortened.
The controller safely transitions to yellow and then red.

💡 Future Improvements
Four-way traffic junction
Vehicle detection using IR sensors
Emergency vehicle priority
LCD/OLED display
IoT monitoring using Wi-Fi
Adaptive timing based on traffic density

🎯 Learning Outcomes
ESP32 GPIO programming
Interrupt handling
Embedded C programming
Traffic signal logic
Timing and state control
