
# 🧩 Arrangatan
A simple drag‑and‑drop arrangement game built with **C++**, **SFML 3**, and **CMake**.  
Users can drag blocks, snap them into storage regions, and interact with a clean, minimal UI.

---

## 📸 Screenshots
will add later

---

## ✨ Features
will add later

---

## 🛠️ Requirements
This project uses:

- **MSYS2 UCRT64**
- **GCC (ucrt64)**
- **CMake 3.20+**
- **SFML 3.0.2**

---

## 📥 Installation (Windows)

### 1. Install MSYS2
Download from: https://www.msys2.org/

### 2. Open the **MSYS2 MinGW UCRT64** terminal  

### 3. Update and install dependencies
```bash
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc \
          mingw-w64-ucrt-x86_64-cmake \
          mingw-w64-ucrt-x86_64-sfml
```          

### 4. 🧭 Add MSYS2 to PATH 
Add these entries to your system PATH (preferably at the top):
```bash
C:\msys64\ucrt64\bin
C:\msys64\usr\bin
```

### 5. Restart VS Code or your terminal


## 🚀 Build Instructions

1. Clone the repository
```bash
git clone https://github.com/<yourname>/arrangatan.git
cd arrangatan
```

2. Configure the project
```bash
cmake -S . -B build -G "MinGW Makefiles"
```

3. Build
```bash 
cmake --build build -j
```

4. Run
```bash
./build/arrangatan.exe
```


## 🚀 VS Code Build Instructions 

1. Install the **CMake Tools** extension

2. Open the project folder

3. Select the Kit:
```bash 
GCC <version> (ucrt64)
```
4. Run **CMake: Configure**

5. Run **CMake: Build**

6. Click **Run** in the bottom status bar
    the triangle icon

