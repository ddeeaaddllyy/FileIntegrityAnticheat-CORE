# File Integrity Anti-Cheat (C++)

A minimal yet practical **file integrity verification engine** written in modern C++.
This project demonstrates how anti-cheat / anti-tamper systems work at a **file-system level**.

The engine builds a **baseline snapshot** of files and later verifies that no files were:
- removed
- modified
- replaced

---

## 🚀 Features

- Recursive file system scanning
- Baseline snapshot generation
- Integrity verification (file size based)
- Detection of:
    - Missing files
    - Modified files
- Cross-platform C++17+ (`std::filesystem`)
- No external dependencies
- Clean and extensible architecture

---

## 🧠 How It Works (High-Level)

1. **First launch**
    - Scans the target directory
    - Saves file metadata into `baseline.txt`
    - Exits

2. **Subsequent launches**
    - Loads `baseline.txt`
    - Re-scans the directory
    - Compares current state with baseline
    - Reports integrity violations

This approach is commonly used as a **first layer** in:
- anti-cheat systems
- DRM / anti-tamper software
- malware detection
- system integrity monitoring

---

## 📁 Project Structure

You can find it in the comments/structure.txt

---

## 🛠 Build & Run

### Requirements
- C++20 (optimal but u can use c++17) or newer
- Any modern compiler:
    - MSVC
    - MinGW
    - Clang
    - GCC

### Build
```bash
g++ -std=c++20 main.cpp -o integrity_checker 
```

### ⚠️ Important Notes

- The baseline must be created on a clean, trusted system
- Any file change after baseline creation will be reported
- File size comparison is used for simplicity (can be replaced with hashes)

---

## 📜 License

This project is licensed under the **Apache License 2.0**. See the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Author

**ddeeaaddllyy** *"It was then I started getting lost in books"* - **GitHub:** [@ddeeaaddllyy](https://github.com/ddeeaaddllyy)
