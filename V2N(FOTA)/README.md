
# V2N (Firmware Over-The-Air) Sub-system

The V2N (Firmware Over-The-Air) sub-system facilitates the secure remote updating of firmware for the target STM32F103 BLUE PILL microcontroller. This sub-system consists of a web server for uploading .hex applications, a NodeMCU for downloading the .hex file from the server, and a secure transmission mechanism using XOR symmetric encryption.

## Overview

The V2N sub-system enables seamless firmware updates for the target microcontroller, enhancing the flexibility and functionality of the device without the need for physical intervention. By leveraging web-based communication and wireless technology, the sub-system simplifies the process of deploying and updating firmware in real-time.
![image](https://github.com/mohnagah/V2X_STM32_BLUEPILL/assets/157398651/1888ffe1-65d0-4990-a629-1911d9db8463)

## Features

- **Web Server Integration:** Utilizes a web server for uploading .hex applications and providing access to firmware updates.
- **NodeMCU Communication:** Facilitates communication between the web server and the target device, handling the download and flashing process.
- **Secure Transmission:** Uses XOR symmetric encryption to encrypt data at the server side and decrypt data at the NodeMCU side.
- **Remote Firmware Updates:** Enables remote updating of firmware over-the-air, eliminating the need for physical connections or manual intervention.
- **Bootloader Integration:** Integrates with the STM Bootloader to manage the flashing process and execute the updated firmware.

## Usage

To use the V2N sub-system, follow these steps:

1. **Access FOTA Website:**
   - Go to the [FOTA website](http://sgnfinalproject.atwebpages.com) link provided.
   - Follow the instructions on the website regarding the linker script of the desired application.

2. **NodeMCU Configuration:**
   - Connect the NodeMCU to any COM port through a USB to TTL module.
   - Add an appropriate COM interface in the Proteus simulation.
   - ![image](https://github.com/mohnagah/V2X_STM32_BLUEPILL/assets/157398651/3cba085d-b092-47cc-b7f7-e6e20bd01be8)
   - Configure the NodeMCU from the `config.h` file to:
     - Receive the .hex file uploaded to the web server using .hex File URL.
     - Set the Wi-Fi SSID and Password for connecting to the network.
     - Specify the timeout interval for trying to connect to Wi-Fi.

3. **Flashing Process:**
   - On reset, the STM Bootloader waits for a specified timeout interval (configurable in the bootloader code).
   - If any code is received from the NodeMCU within this interval, the bootloader will:
     - Erase the application area.
     - Flash the received code onto the Flash memory.
     - Run the application code.
   - If no code is received from the NodeMCU for the specified timeout interval, the bootloader will jump to the latest flashed application code.

## Additional Information

- **Web Server URL:** [FOTA Website](http://sgnfinalproject.atwebpages.com)
- **.hex File URL:** [Uploaded .hex File](https://sgnfinalproject.atwebpages.com/uploads/Application.txt)

## Video 
[V2N(FOTA)](https://drive.google.com/file/d/16HHp2k4ZJ4EfdxErTHpvzzUdmCOtrauz/view?usp=sharing)

## License

This sub-system is part of the V2X Project and is licensed under the [GPL-3.0 License](../LICENSE).
