---

# Antivirus-Linux

## Overview

Antivirus-Linux is a robust antivirus solution designed specifically for Linux systems. It combines a graphical user interface (GUI) written in Python with an engine developed in C, utilizing YARA rules for efficient malware detection. The GUI provides a user-friendly interface for managing scans and viewing results, while the C-based engine handles the core functionality of scanning and detecting malicious files.

## Features

- **User-Friendly GUI**: Built with Python, offering an intuitive interface for scanning and monitoring.
- **Powerful Engine**: Developed in C for performance, leveraging YARA rules for advanced malware detection.
- **Real-Time Monitoring**: Includes real-time monitoring capabilities to detect threats as they occur.
- **Detailed Scan Reports**: Provides comprehensive reports of scan results, highlighting detected threats.

## Installation

### Prerequisites

- Python 3.x
- GCC (GNU Compiler Collection)
- YARA
- `tkinter` Python library
- `Pillow` (PIL Fork) Python library

### Steps

1. **Clone the Repository**
   ```sh
   git clone https://github.com/yourusername/antivirus-linux.git
   cd antivirus-linux
   ```

2. **Install Python Dependencies**
   ```sh
   sudo apt-get install python3-tk
   python3 -m venv env
   source env/bin/activate
   pip install pillow
   ```

3. **Install YARA**
   ```sh
   sudo apt-get install yara
   sudo apt-get install libyara-dev
   ```

4. **Compile the C Engine**
   ```sh
   gcc -o engine engine.c -lyara
   gcc -o engine-rtm engine-rtm.c -lyara
   ```

## Usage

### Running the GUI

To start the GUI, execute the following command:
```sh
python gui.py
```

### Performing a Scan

1. Open the GUI.
2. Select the directory or files you want to scan.
3. Click on the 'Scan' button to initiate the scan.

### Real-Time Monitoring

1. Ensure the real-time monitoring engine is running:
   ```sh
   ./engine-rtm
   ```

## Project Structure

- `gui.py`: The Python script for the graphical user interface.
- `engine.c`: The main C file containing the antivirus engine.
- `engine-rtm.c`: The C file for the real-time monitoring engine.
- `README.md`: Documentation file.

## Contributing

We welcome contributions! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch.
3. Make your changes.
4. Submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- The [YARA](https://virustotal.github.io/yara/) project for providing a powerful pattern matching tool.
- All contributors and community members for their support and contributions.

## Contact

For any questions or feedback, please contact `Jaywantadhau16003@gmail.com`.

---
