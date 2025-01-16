# Stopwatch and Timer with Alarm

## Overview
The **Stopwatch and Timer with Alarm** is a C++ application that provides an interactive command-line interface for managing a stopwatch and a countdown timer with an alarm feature. This project is ideal for learning about time management in programming, interactive console applications, and working with C++ libraries for threading, sound playback, and input handling.

## Prerequisites
Before running the application, ensure you have the following installed:
- A C++ Compiler supporting C++11 or higher (e.g., `g++`, `Clang`, or Visual Studio).
- Windows environment for alarm functionality (uses `winmm.lib` for sound playback).
- Basic knowledge of running command-line programs.

## Installation

### C++ Compiler Installation
If you don't have a C++ compiler installed, you can install `g++` using the following commands:


- **For Ubuntu/Debian-based systems:**
  ```bash
  sudo apt update
  sudo apt install build-essential
  ```

- **For macOS (using Homebrew):**
    ```bash
    brew install gcc
    ```

- **For Windows:**
    - Install [MinGW](http://www.mingw.org/) or use [Visual Studio](https://visualstudio.microsoft.com/) with C++ development tools.

## Clone the Repository
Clone the repository to your local machine using Git:
```bash
git clone https://github.com/yourusername/Interactive-Stopwatch-and-Timer-with-Alarm-in-C-Plus-Plus.git
cd Interactive-Stopwatch-and-Timer-with-Alarm-in-C-Plus-Plus
```

## Compilation
Compile the C++ source code using your preferred compiler. For example, using g++:
```bash
g++ -std=c++11 -o Stopwatch_Timer main.cpp -lwinmm
```
Ensure that all necessary files (e.g., main.cpp) are in the project directory.

## Usage

### Running the Application
After compilation, execute the program:

```bash
./Stopwatch_Timer
```

## Menu Options

### Stopwatch
- A simple stopwatch that allows pausing and resuming.

### Timer
- A countdown timer where the user sets hours, minutes, and seconds, with an alarm upon completion.

### Exit
- Exits the application.

---

## Stopwatch Functionality
- **Starts at 00:00:00.**
- **Pause/Resume**: Press `P` to pause or resume.
- **Exit**: Press `E` to exit the stopwatch.

---

## Timer Functionality
- **Set Countdown**: Prompts the user to enter hours, minutes, and seconds for the countdown.
- **Countdown Display**: Displays the countdown in real-time.
- **Alarm Playback**: Plays an alarm sound when the timer ends.
- **Stop Alarm**: Press `Y` when prompted to stop the alarm.

---

## Features

### General Features
- **Intuitive Command-Line Menu**: Easy navigation through options.
- **Real-Time Timer and Stopwatch**: Displays time updates in real-time.
- **Alarm Sound**: Plays a sound when the timer completes.

### Stopwatch
- **Incremental Time Display**: Updates hours, minutes, and seconds.
- **Interactive Pause and Resume**: Allows user input to control the stopwatch.

### Timer
- **User-Defined Duration**: Accepts hours, minutes, and seconds for a countdown.
- **Real-Time Updates**: Continuously displays the remaining time.
- **Alarm Playback**: Looping alarm sound until manually stopped.

### Alarm
- **Plays `.wav` Sound File**: Ensures user attention with sound.
- **Stop Prompt**: Allows the user to stop the alarm manually.

---

## Important Notes

### Sound Playback
- **Alarm Dependency**: Uses `PlaySound` from `winmm.lib` (specific to Windows).
- Ensure the `.wav` file (e.g., `Alarm.wav`) is in the same directory as the executable.

### Cross-Platform Considerations
- The code is designed for Windows. Adjustments are required for sound playback on other platforms.

### Input Validation
- Ensures valid numeric inputs for hours, minutes, and seconds to prevent runtime errors.

---

## Troubleshooting

### Compilation Errors
- **Issue**: Errors related to missing headers or syntax.
- **Solution**: Ensure you are using a C++11-compatible compiler and verify the inclusion of `winmm.lib` for Windows builds.

### Sound Playback Issues
- **Issue**: Alarm sound does not play.
- **Solution**: Verify that `Alarm.wav` is in the correct directory. Check if your system supports `PlaySound` and ensure that `winmm.lib` is correctly linked.

### Runtime Errors
- **Issue**: The program crashes unexpectedly.
- **Solution**: Use debugging tools or print statements to trace execution. Handle edge cases like empty or invalid inputs.

---
   
## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your improvements or additional features. Whether it's enhancing the algorithm, optimizing performance, or adding new functionalities, your contributions are valuable.

## Acknowledgments

- [C++ Documentation](https://en.cppreference.com/w/)
- [Microsoft PlaySound Documentation](https://learn.microsoft.com/en-us/windows/win32/api/mmeapi/nf-mmeapi-playsound)
- Open-source contributors for tools and libraries.

