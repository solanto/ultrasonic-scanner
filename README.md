# ultrasonic-scanner

This uses an Arduino, a cheap ultrasonic sensor, and a servo to make a map of the environment and display it on an 8 by 8 dot grid module. A full paper with background, documentation, and pictures can be found [here](https://docs.google.com/document/d/1h26WxozLwDxCvQk0HH0gCvA0ckOZmEKNL86gxf7ZDMk/edit).

Deploy the project super easily with [PlatformIO](https://platformio.org). Alternatively, to use the Arduino IDE: open the library manager and download the [`Servo`](https://www.arduino.cc/reference/en/libraries/servo/), [`Ultrasonic`](https://www.arduino.cc/reference/en/libraries/ultrasonic/), and [`MD_MAX72XX`](https://www.arduino.cc/reference/en/libraries/md_max72xx/) libraries, then copy in [`src/main.cpp`](https://github.com/solanto/ultrasonic-scanner/blob/master/src/main.cpp).

This was my final project for JHU's EN.560.112 Electromagnetism & Sensors Lab course in Spring 2021.

[![full paper](https://user-images.githubusercontent.com/20602415/117628437-01199d80-b12e-11eb-901a-9f3170b8b645.jpeg)](https://docs.google.com/document/d/1h26WxozLwDxCvQk0HH0gCvA0ckOZmEKNL86gxf7ZDMk/edit)
