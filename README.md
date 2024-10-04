# Keylogger Application

This repository contains a basic keylogger program written in C++ that captures keystrokes and logs them to a file. The program utilizes the `Windows.h` library to track keypress events and logs them to a file called `keylogger.txt`. 

## Features

- **Keystroke Logging**: The program captures both standard keys and special keys (like `SHIFT`, `BACKSPACE`, and mouse clicks).
- **Real-time Logging**: Each keypress is immediately logged to a file, providing real-time capture of input.
- **Logging File**: The logged keys are stored in a file named `keylogger.txt`, appended continuously as the program runs.

## How It Works

1. The program continuously checks for keypresses using the `GetAsyncKeyState` function from the Windows API.
2. When a key is pressed, it first checks if it matches any special keys (e.g., space, enter, shift, mouse buttons).
3. If the key matches a special key, it logs a descriptive string (e.g., `" shift "` for the `SHIFT` key) to both the console and the `keylogger.txt` file.
4. If the key doesn't match a special key, it logs the character directly.
5. The log is appended to the file, so the log file grows as the program runs.

## Usage

To compile and run the program on a Windows system, follow these steps:

### Compilation

You will need a C++ compiler like `g++` that supports Windows libraries. To compile, use the following command:

```bash
g++ keylogger.cpp -o keylogger.exe -lUser32
