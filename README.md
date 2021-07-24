# ultrasonic-scanner

<p align="center">
  <a href="https://docs.google.com/document/d/1h26WxozLwDxCvQk0HH0gCvA0ckOZmEKNL86gxf7ZDMk/edit">
    <img
      alt="an image of the paper I wrote on this device" 
      src="https://lh5.googleusercontent.com/I3U-Kk1Dz8ourRyA7Nyi6sMZ3jywi84YwpIcqYVCO6z2IEk3gJpKgrVMomXeaSrKLS624GIK4fS5wQ" 
      height="200px" 
    >
    <img
      alt="a picture of my prototype, static" 
      src="https://lh5.googleusercontent.com/LlrhuzXqNhQMRn6wlfK7RQnhTuTM_RC1oSGC7d1EZTTQ4wc12FO8uk48hTKopSXc6dhGe_BqGLxRWjB5Nh1Lif0Nw7hI2VnQFh-RhQbBEZeXKXIMkqDCmtomYtoVFGK4-86HTeCm" 
      height="200px" 
    >
    <img
      alt="a picture of my prototype in action"
      src="https://lh6.googleusercontent.com/YZOSLe-Ihri1DV-zPh6W7mYmj2pohc-xe9DYHRdpsJwUTX1ZHXZWnPY5l0fSH5bScrTSImsxUwXjFRoEgBupqs-RUR1M_Dh3gvCwKQGTHWz9LgH1AHbGBHOWprFtE7FWpzMYjCLZ"
      height="200px"
    >
  </a>
</p>

This uses an Arduino, a cheap ultrasonic sensor, and a servo to make a map of the environment and display it on an 8 by 8 dot grid module. A full paper with background, documentation, and pictures can be found [here](https://docs.google.com/document/d/1h26WxozLwDxCvQk0HH0gCvA0ckOZmEKNL86gxf7ZDMk/edit).

Deploy the project super easily with [PlatformIO](https://platformio.org). Alternatively, to use the Arduino IDE: open the library manager and download the [`Servo`](https://www.arduino.cc/reference/en/libraries/servo/), [`Ultrasonic`](https://www.arduino.cc/reference/en/libraries/ultrasonic/), and [`MD_MAX72XX`](https://www.arduino.cc/reference/en/libraries/md_max72xx/) libraries, then copy in [`src/main.cpp`](https://github.com/solanto/ultrasonic-scanner/blob/master/src/main.cpp).

This was my final project for JHU's EN.560.112 Electromagnetism & Sensors Lab course in Spring 2021.
