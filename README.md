**Online Smart Parking System**

This repository contains the code for an online smart parking system implemented using Arduino and various components. The system aims to optimize parking space utilization by providing real-time information about slot availability to users.


https://github.com/akhilpandit09/online-smart-parking-system/assets/64522940/983a3334-b55b-4aaa-8c30-d9c27748b582


### Components Used:
- Arduino ESP32 Dev Module
- IR Sensors (3 for each parking slot and 1 for the entrance gate)
- Servo Motor
- LCD Display with I2C module
- BLYNK software for visualization

### Features:
- Real-time monitoring of parking slot availability
- Automatic barrier control based on slot occupancy
- User-friendly interface for displaying slot status
- Integration with BLYNK for remote monitoring

### Setup Instructions:
1. Connect the IR sensors to the designated pins on the Arduino board.
2. Connect the servo motor to control the barrier.
3. Connect the LCD display using the I2C module.
4. Install the necessary libraries for IR sensors, servo motor, and LCD display.
5. Upload the provided Arduino sketch to the ESP32 Dev Module.
6. Set up the BLYNK app to visualize parking slot status remotely.

### Usage:
1. When a car approaches the entrance gate, the IR sensor detects its presence.
2. The system checks the occupancy status of each parking slot using the IR sensors.
3. If a parking slot is available, the barrier opens, allowing the car to enter.
4. The LCD display and BLYNK app reflect the updated status of the parking slots.
5. Once the car parks in a slot, the barrier closes, and the slot status is updated accordingly.

### Contributing:
Contributions to this project are welcome. Feel free to submit pull requests for bug fixes, enhancements, or new features.

### License:
This project is licensed under the [MIT License](LICENSE).

### Acknowledgments:
- Thanks to the developers of the BLYNK platform for enabling easy integration with IoT projects.
- Special thanks to the Arduino community for providing valuable resources and support for hardware projects.
