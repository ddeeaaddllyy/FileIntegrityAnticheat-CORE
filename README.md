# Echo Engine  
### Experimental Windows Systems Research Project (C++)

---

## 📘 Abstract

**Echo Engine** is an experimental C++ project developed for academic and research purposes, focusing on low-level interaction with the Microsoft Windows operating system.  
The project explores system behavior, hardware monitoring, user input processing, multimedia capture, and network diagnostics using native Windows APIs.

This work serves as a **technical research sandbox**, not as a production-ready application or deployable framework.

---

## ⚠️ Disclaimer

> This project is intended **solely for educational, academic, and experimental use**.
>
> - It is **not designed for deployment**
> - It is **not intended for use on third-party systems**
> - It is **not guaranteed to work outside the author’s environment**
>
> The author assumes **no responsibility** for misuse of this software.

---

## 🎯 Research Objectives

The primary goals of Echo Engine include:

- Studying **Windows internals** and OS-level mechanisms
- Experimenting with:
  - Low-level keyboard and mouse hooks
  - Hardware and peripheral monitoring
  - Multimedia data acquisition
  - Network diagnostics
- Understanding **security boundaries** enforced by modern operating systems
- Practicing **safe and controlled system programming**

---

## 🧭 Scope & Design Philosophy

- Platform-specific (Windows-only)
- Native API usage (WinAPI)
- Local-only execution
- No persistence, concealment, or remote communication
- Manual user interaction required for all operations

Echo Engine is **not a malware framework**, **not a remote administration tool**, and **not stealth software**.

---

## 🧩 Functional Overview

### 0. `echo`
Basic connectivity and responsiveness check for the engine.

---

## 🔧 Core Modules

### 1. `k3ylogger`
A low-level keyboard input research module:
- Captures key presses via Windows hooks
- Detects active keyboard layout (e.g., EN / RU)
- Correctly maps characters based on layout
- Logs active window titles
- Outputs to:
  - Console
  - Local text files

> Purpose: study keyboard layouts, Unicode handling, and input hooks.

---

### 2. Human Presence Predictor
Attempts to infer human presence using activity heuristics over a **10-second interval**:
- Keyboard input
- Mouse movement
- Webcam (face presence, if available)
- Microphone (voice activity, if available)

> This module uses **heuristic detection**, not machine learning.

---

### 3. USB Watcher
Monitors USB activity for **10 seconds**:
- Detects connected USB devices
- Reads accessible metadata
- Lists files and approximate sizes (when permitted)

---

### 4. PC Data
Retrieves system-level information:
- Active windows
- Basic hardware data
- Operating system details

---

### 5. CMD Executor
Executes arbitrary Command Prompt commands locally.

> Used to study process creation and command execution APIs.

---

### 6. Display a Message
Displays user-defined messages in a styled console or window output.

---

### 7. Open Link
Opens a specified URL using the system default browser.

---

### 8. Shutdown
Performs a system shutdown with explicit confirmation to prevent accidental execution.

---

## 🎥 Recording & Capture Modules

### 9. Screenshot
Captures a screenshot and saves it locally (default: Desktop).

---

### 10. Video Recording
Records video output for **10 seconds by default**.

---

### 11. Audio Recording
Records audio for **10 seconds by default**:
- Format: `.wav`
- Stored locally (default: Desktop)

---

### 12. Screen Recording
Captures screen activity for **10 seconds by default**.

---

## 🌐 Networking Modules

### 13. Echo Ping
Sends ICMP echo requests to test network connectivity.

---

### 14. Echo WiFi
Retrieves available network information:
- Local IP address
- Connection type (wired / wireless)
- Network name (SSID, if applicable)
- Provider information (when available)

> Network credentials are **not guaranteed** to be retrievable.

---

### 15. Echo Sniffer
Experimental packet-sniffing module.

> Highly unstable and incomplete.

---

### 16. TData Stiller
Experimental module under development.

---

## 🖥️ Technical Requirements

- **Operating System:** Windows
- **Language:** C++
- **APIs:** WinAPI
- **Encoding:** UTF-8
- **Compiler:** MSVC (recommended)

---

## 🚧 Project Status

- Experimental
- Non-portable
- Environment-specific
- Actively evolving

This repository is **not intended to be cloned and executed without modification**.

---

## 📄 License

This project is licensed under the **MIT License**.

You are free to:
- Use
- Modify
- Distribute

Provided that the license notice is preserved and the software is used responsibly.

---

## 📌 Final Notes

Echo Engine is designed for:
- Students
- Researchers
- Developers studying Windows internals

It is **not suitable** for:
- Production environments
- Commercial deployment
- Surveillance or unethical usage

---

**Author:**  
github It was then I started gettin lost in books @ddeeaaddllyy
