#include <Arduino.h>
#include <MD_MAX72xx.h>
#include <Servo.h>
#include <Ultrasonic.h>

#define forceinline __attribute__((always_inline))  // "inline" on its own doesn't work reliably in Arduino projects


// ✨ user parameters ✨

// 📍 pin configuration
namespace pins {

    // 📡 ultrasonic pins
    namespace ultrasonic {
        constexpr int
            trig = 4,
            echo = 3;
    } // since pins don't change at runtime, constexpr tells the compiler to copy-and-paste values into our code 

    // 💡 display pins
    namespace display {
        constexpr int
            CS = 6,
            DIN = 5,
            CLK = 7;
    }

    // ⚙ servo pin
    constexpr int servo = 2;
}

// 🔧 device settings
namespace settings {

    // 📡 ultrasonic settings
    namespace ultrasonic {
        constexpr int
            samples = 20,     // how many measurements to average per ray; trades speed for precision
            angleStep = 3,    // degrees; how far to turn between rays; trades speed for precision
            maxDistance = 50, // centimeters; greater distances squish the output more (HC-SR04 supports 400cm)
            timeout = 5000;   // microseconds; how long to wait for a sonar response before moving on
    }
}

// ✨ --------------- ✨


// 📦 runtime variables 📦

// ultrasonic sensor object with the pins & settings we set
Ultrasonic ultrasonic(
    pins::ultrasonic::trig,
    pins::ultrasonic::echo,
    settings::ultrasonic::timeout
);

// 8×8 display object with the pins we set
MD_MAX72XX display(
    MD_MAX72XX::GENERIC_HW,
    pins::display::DIN,
    pins::display::CLK,
    pins::display::CS
);

// servo object (pin passed in at setup)
Servo servo;

// which way the sensor is turning
bool direction = 0;

// 📦 ----------------- 📦


// 🤖 i/o processing 🤖

// stores a point as both a polar and cartesian representation
struct Polar {
    int x, y, radius, angle;

    // construct a Polar from radius & angle (degrees)
    Polar(const float radius, const int angle):
        radius(radius),
        angle(angle)
    {
        const float angleRadians = radians(angle);
        x = radius * cos(angleRadians);
        y = radius * sin(angleRadians);
    }
};

// map big, linear ultrasonic distances to displayable distances
inline int scale(const float) forceinline;  // inline to do simple calculations in-place where possible
inline int scale(const float reading) {
    return 8 * log(reading + 1) / log(settings::ultrasonic::maxDistance);  // logarithmic
    // return 8 * reading / maxDistance; // linear
}

// meaure how far the sensor can see at the specified angle (degrees)
Polar scanTo(const int angle) {
    // turn the sensor
    servo.write(angle);

    // average the number of samples set in parameters
    int sampleSum = 0;
    for (int i = 0; i < settings::ultrasonic::samples; i++) {
        sampleSum += ultrasonic.read();
    }

    const int average = sampleSum / settings::ultrasonic::samples;

    // scale the distance
    const int scaled = scale(average);

    // return the point as a Polar
    return Polar(scaled, angle);
}

// given a display point, illuminate all points on the radius until we reach the point
void fillRadial(const Polar& stop) {
    for (int i = 0; i <= stop.radius; i++) {
        const Polar point(i, stop.angle);
        display.setPoint(8 - point.y, 8 - point.x, HIGH); // translated to accomodate display orientation
    }
}

// measure along a full 90° turn, display, & print
void sweep(const bool reverse = false) {

    // if reversed, step backward from end to start
    const int start = reverse ? 90 : 0;

    const int step = reverse
        ? -settings::ultrasonic::angleStep
        : settings::ultrasonic::angleStep;

    display.clear();

    // for each angle step in the 90°
    for (int angle = start; abs(angle - start) <= 90; angle += step) {

        // measure distance at the angle
        const Polar point = scanTo(angle);

        // display the measurement
        fillRadial(point);

        // format measurement for serial plotter
        char out[32];
        sprintf(out, "direction:%01d radius:%02d x:%02d y:%02d", direction, point.radius, point.x, point.y);

        // format measurement as space-delimited CSV
        // char out[11]
        // sprintf(out, "%01d %02d %02d %02d", sweepDirection, point.radius, point.x, point.y);

        // print measurement
        Serial.println(out);
    }
}

// 🤖 -------------- 🤖


// ♾ Arduino functions ♾

void setup() {
    display.begin();
    display.clear();

    Serial.begin(9600);

    servo.attach(pins::servo);
}

void loop() {
    sweep(direction);
    direction = !direction; // flip
}

// ♾ ----------------- ♾
