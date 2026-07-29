# ESP32-MCPWM-Wrapper

An object-oriented C++ library designed to simplify hardware-accelerated motor control on the ESP32. This repository provides a clean wrapper around the ESP32's Motor Control Pulse Width Modulator (MCPWM) peripheral. 

At its core, it features a base `Motor` class for standard open-loop control, and a derived `PIDController` class that inherits from `Motor` to provide precise, closed-loop feedback control.

---

## **Features**

* **Hardware Accelerated:** Utilizes the ESP32's dedicated MCPWM peripheral rather than standard software LEDC PWM, freeing up CPU cycles and providing highly precise motor control.
* **Object-Oriented Design:** Clean C++ architecture making it easy to instantiate multiple motors and controllers.
* **Base Motor Class:** Handles the low-level MCPWM initialization, frequency setting, and duty cycle assignment for standard directional control.
* **Integrated PID Controller:** A derived class that layers Proportional-Integral-Derivative control on top of the base motor functionality for closed-loop systems (e.g., using encoders).
* **PlatformIO Ready:** Structured for immediate use with PlatformIO, as shown by the `platformio.ini` configuration.

---

## **Prerequisites**

* **Hardware:** Any ESP32 development board.
* **Software:** [PlatformIO](https://platformio.org/) IDE (VSCode extension recommended) or ESP-IDF.
* **Framework:** Arduino framework or ESP-IDF (depending on your specific implementation in `platformio.ini`).

---

## **Installation**

1. Clone this repository into your local environment:
   ```bash
   git clone https://github.com/ayush-shukla03/ESP32-MCPWM-Wrapper.git
   ```

   