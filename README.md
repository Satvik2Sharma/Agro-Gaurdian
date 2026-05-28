# Agro-Guardian 🌾

Smart edge-based crop protection system built using ESP32, PIR motion sensing, and ultrasonic distance analysis to detect animal intrusions and trigger real-time deterrent responses.

Developed during a 4-Day Automation Bootcamp guided by IIT Mandi Professors.

<p align="left">
  <a href="https://www.linkedin.com/in/satvik2sharma">
    <img src="https://img.shields.io/badge/LinkedIn-Satvik%20Sharma-0A66C2?style=flat&logo=linkedin" />
  </a>
</p>

---

## 📸 Prototype Demonstration

### Hardware Prototype

![Prototype](prototype_demo_images-gifs/prototype.jpg)

---

### Working Demonstration

![Demo](prototype_demo_images-gifs/demo.gif)

---

## 📌 Overview

Agro-Guardian is a lightweight embedded IoT system designed for basic farm intrusion monitoring and localized crop protection.

The system combines:
- PIR-based motion detection
- Ultrasonic distance sensing
- Sudden movement analysis

to detect nearby animal activity and activate:
- buzzer-based deterrence
- LED alert signaling

The project focuses on practical edge automation using an ESP32 microcontroller.

---

## ⚡ Features

- Multi-sensor intrusion detection using PIR + ultrasonic sensing
- Sudden movement detection through distance-change analysis
- Real-time audio-visual deterrent response
- Lightweight ESP32 edge processing
- Rapid hardware prototyping workflow

---

## 🧠 Detection Logic

An intrusion is triggered when:

- motion is detected within the configured distance threshold
- OR sudden distance variation exceeds the change threshold

```cpp
if ((pirState == HIGH && distance < DIST_THRESHOLD) || 
    (change > CHANGE_THRESHOLD)) {
    intrusion = true;
}
````

---

## 🛠️ Hardware Components

| Component                 | Purpose              |
| ------------------------- | -------------------- |
| ESP32 Dev Board           | Main controller      |
| PIR Sensor                | Motion detection     |
| HC-SR04 Ultrasonic Sensor | Distance measurement |
| Piezo Buzzer              | Audio deterrent      |
| LED Indicator             | Visual alert         |

---

## 📍 Pin Configuration

| Component          | ESP32 Pin |
| ------------------ | --------- |
| PIR Sensor         | GPIO 5    |
| Ultrasonic Trigger | GPIO 18   |
| Ultrasonic Echo    | GPIO 19   |
| Buzzer             | GPIO 26   |
| LED                | GPIO 4    |

---

## 🧩 System Architecture

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

## 🚀 Getting Started

### Clone Repository

```bash
git clone https://github.com/Satvik2Sharma/Agro-Guardian.git
```

### Setup

1. Open Arduino IDE
2. Select:

   ```text
   ESP32 Dev Module
   ```
3. Connect hardware according to the pin mapping table
4. Upload the firmware to the ESP32 board

---

## 📊 Serial Monitor Output

Example runtime logs:

```text
PIR: 1 | Distance: 72 cm | Change: 25
🚨 Animal Detected!
```

---

## 🔧 Tech Stack

* ESP32
* Embedded C++
* Arduino IDE
* PIR Motion Sensing
* Ultrasonic Telemetry
* Edge-Based Detection Logic

---

## 📈 Future Improvements

* GSM/SMS alerts
* Solar-powered deployment
* Camera integration
* LoRa communication
* Cloud dashboard support

---

## 🤝 Acknowledgements

* IIT Mandi Automation Bootcamp
* ESP32 Open Hardware Ecosystem
* Arduino Community

---

## 📬 Contact

**Satvik Sharma**
Aspiring Software & AI Engineer

* GitHub: https://github.com/Satvik2Sharma
* LinkedIn: https://www.linkedin.com/in/satvik2sharma

```
```

