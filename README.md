# 🔥  Smart RGB LED System (ESP32)

An intelligent Smart Lighting System built using ESP32 that detects motion and room brightness to automatically control a light using a relay and display system status using an RGB LED.

---

## 🚀 Features

- Motion Detection using PIR sensor
- Light intensity detection using LDR
- Automatic light control using Relay
- RGB LED status indication
- Auto turn-off timer (20 seconds)
- Non-blocking timing using millis()
- Expandable for IoT upgrades

---

## 🧠 System Logic

| Condition | Relay | RGB LED |
|-----------|--------|----------|
| No Motion | OFF | Blue |
| Motion + Bright | OFF | Red |
| Motion + Dark | ON | Green |
| After 20 sec | OFF | Blue |

---

## 🧰 Hardware Components

- ESP32 Dev Module
- PIR Motion Sensor
- LDR Light Sensor Module
- 4-Pin RGB LED (Common Cathode)
- 3 × 220Ω Resistors
- 2-Channel Relay Module
- Breadboard & Jumper Wires

---

## 🔌 Pin Configuration

| Component | ESP32 Pin |
|------------|------------|
| PIR OUT | GPIO 27 |
| LDR OUT | GPIO 34 |
| Relay IN1 | GPIO 26 |
| RGB Red | GPIO 14 |
| RGB Green | GPIO 12 |
| RGB Blue | GPIO 13 |

---

## ⚙️ How It Works

1. PIR detects motion.
2. LDR checks if room is dark.
3. If motion + dark → relay turns ON.
4. RGB LED changes color based on system state.
5. Light automatically turns OFF after 20 seconds.

---

## 🛠 Technologies Used

- Embedded C++
- ESP32 PWM (LEDC)
- Digital & Analog Sensor Integration
- Non-blocking timer using millis()

---

## 🔥 Future Improvements

- WiFi Control via Web Interface
- Mobile App Integration
- Cloud Logging
- Energy Usage Monitoring
- Manual Override Switch

---

## 📜 License

This project is licensed under the MIT License.
