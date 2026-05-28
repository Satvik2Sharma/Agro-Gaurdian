````md
# Agro-Guardian 🌾

Smart edge-based crop protection system built using ESP32, PIR motion sensing, and ultrasonic distance analysis to detect animal intrusions and trigger real-time deterrent responses.

Developed during a 4-Day Automation Bootcamp guided by IIT Mandi Professors.

<div align="left">

**Built by Satvik Sharma**  
[LinkedIn](https://www.linkedin.com/in/satvik2sharma)

</div>

---

## 📌 Overview

Agro-Guardian is an embedded IoT system designed for basic farm intrusion monitoring and localized crop protection.

The system combines:
- PIR-based motion detection
- Ultrasonic distance measurement
- Sudden movement analysis

to identify nearby animal movement and activate:
- buzzer-based deterrence
- LED alert signaling

The project was developed as a rapid hardware prototype focused on practical edge automation workflows using an ESP32 microcontroller.

---

# 📸 Prototype Demonstration

## Hardware Prototype

> Add your prototype image inside:
```text
prototype_demo_images-gifs/
````

Expected example:

```text
prototype_demo_images-gifs/prototype.jpg
```

![Hardware Prototype](prototype_demo_images-gifs/prototype.jpg)

---

## Working Demonstration

> Add your working GIF inside:

```text
prototype_demo_images-gifs/
```

Expected example:

```text
prototype_demo_images-gifs/demo.gif
```

![Working Demo](prototype_demo_images-gifs/demo.gif)

---

# ⚡ Features

* Multi-sensor intrusion detection using PIR + ultrasonic sensing
* Sudden movement detection through distance-change analysis
* Real-time audio-visual deterrent response
* ESP32-based edge processing
* Lightweight embedded system architecture
* Rapid prototype designed during a constrained bootcamp timeline

---

# 🧠 Detection Logic

The system combines thermal motion sensing and ultrasonic telemetry to determine possible intrusion activity.

An intrusion is triggered if:

* motion is detected within the configured distance threshold
* OR sudden distance variation exceeds the change threshold

```cpp
if ((pirState == HIGH && distance < DIST_THRESHOLD) || 
    (change > CHANGE_THRESHOLD)) {
    intrusion = true;
}
```

This helps reduce false positives while improving responsiveness to fast-moving targets.

---

# 🛠️ Hardware Components

| Component                 | Purpose              |
| ------------------------- | -------------------- |
| ESP32 Dev Board           | Main controller      |
| PIR Sensor                | Motion detection     |
| HC-SR04 Ultrasonic Sensor | Distance measurement |
| Piezo Buzzer              | Audio deterrent      |
| LED Indicator             | Visual alert         |
| Jumper Wires & Breadboard | Circuit connections  |

---

# 📍 Pin Configuration

| Component          | ESP32 Pin |
| ------------------ | --------- |
| PIR Sensor         | GPIO 5    |
| Ultrasonic Trigger | GPIO 18   |
| Ultrasonic Echo    | GPIO 19   |
| Buzzer             | GPIO 26   |
| LED                | GPIO 4    |

---

# 🧩 System Architecture

```text
                  ┌──────────────────────┐
                  │      ESP32 MCU       │
                  └──────────┬───────────┘
                             │
        ┌────────────────────┴────────────────────┐
        ▼                                         ▼

 ┌──────────────────┐                   ┌──────────────────┐
 │   INPUT MODULES  │                   │ OUTPUT MODULES   │
 ├──────────────────┤                   ├──────────────────┤
 │ PIR Sensor       │                   │ Piezo Buzzer     │
 │ Ultrasonic Trig  │                   │ LED Indicator    │
 │ Ultrasonic Echo  │                   └──────────────────┘
 └──────────────────┘
```

---

# 🚨 Alert Mechanism

When intrusion conditions are satisfied:

1. LED indicator activates
2. Rapid double-beep deterrence pattern begins
3. Long-duration alarm pulse is triggered
4. System resets and resumes monitoring

The buzzer pattern was intentionally designed to create a stronger deterrent effect for nearby animals.

---

# 📂 Project Structure

```text
Agro-Guardian/
│
├── AgroGuardian.ino
├── README.md
│
├── prototype_demo_images-gifs/
│   ├── prototype.jpg
│   └── demo.gif
│
└── assets/
```

---

# 🚀 Getting Started

## 1. Clone Repository

```bash
git clone https://github.com/Satvik2Sharma/Agro-Guardian.git
```

---

## 2. Open Arduino IDE

Install:

* Arduino IDE
* ESP32 Board Package

Board Selection:

```text
ESP32 Dev Module
```

---

## 3. Connect Hardware

Wire all sensors and output devices according to the pin mapping table above.

---

## 4. Upload Firmware

Open:

```text
AgroGuardian.ino
```

Upload the firmware to the ESP32 board.

---

# 📊 Serial Monitor Output

Example runtime logs:

```text
PIR: 1 | Distance: 72 cm | Change: 25
🚨 Animal Detected!
```

---

# 🔧 Core Technologies

* ESP32
* Embedded C++
* Arduino IDE
* PIR Motion Sensing
* Ultrasonic Telemetry
* Edge-Based Detection Logic

---

# 📈 Future Improvements

Potential future enhancements:

* GSM/SMS alerts
* Solar-powered deployment
* AI-based animal classification
* Camera integration
* LoRa communication
* Cloud monitoring dashboard

---

# 🤝 Acknowledgements

* IIT Mandi Automation Bootcamp
* ESP32 Open Hardware Ecosystem
* Arduino Community

---

# 📬 Contact

**Satvik Sharma**
Aspiring Software & AI Engineer

* GitHub: https://github.com/Satvik2Sharma
* LinkedIn: https://www.linkedin.com/in/satvik2sharma

---

```
```

