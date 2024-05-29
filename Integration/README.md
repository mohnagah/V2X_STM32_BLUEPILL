
# V2X Project Integration

The V2X Mega Project integrates three sub-systems: V2V, V2I, and V2N (FOTA) to create a comprehensive vehicular communication system. This integrated system enhances road safety and traffic efficiency through real-time communication between vehicles and infrastructure, as well as enabling secure remote firmware updates.

## Overview

The V2X integration combines the functionalities of the V2V, V2I, and V2N sub-systems to provide a robust and adaptive vehicular network. The V2I sub-system continuously sends traffic state updates to the master car, while the V2N sub-system ensures that the slave car's firmware is up-to-date to receive signals from the master car's ultrasonic sensors.

## Sub-Systems

### V2V (Vehicle-to-Vehicle Communication)
- **Master-Slave Communication:** Establishes communication between the master and slave cars via USART.
- **Ultrasonic Sensors:** Utilizes front and backward ultrasonic sensors on the master car to detect obstacles and measure distances.
- **Motor Control:** Controls motor actions in both master and slave cars based on predefined modes.

### V2I (Vehicle-to-Infrastructure Communication)
- **RSU Integration:** Connects the master car with the Roadside Control Unit (RCU) to receive traffic light status updates.
- **Real-time Updates:** Delivers continuous traffic light status to the master vehicle.
- **Adaptive Driving:** Enables the master vehicle to adapt its driving behavior based on traffic light signals.

### V2N (Firmware Over-The-Air Updates)
- **Web Server Integration:** Uses a web server for uploading .hex applications.
- **NodeMCU Communication:** Downloads the .hex file from the server and flashes it onto the target device's Flash memory.
- **Secure Transmission:** Uses XOR symmetric encryption to ensure secure data transmission between the server and NodeMCU.
- **Remote Firmware Updates:** Allows remote updating of the slave car's firmware to enable it to receive signals from the master car's ultrasonic sensors.

## Integration Scenario

1. **Continuous Traffic State Updates:**
   - The V2I sub-system continuously sends the traffic state from the RSU to the master car, ensuring it has up-to-date traffic information.

2. **Firmware Updates for the Slave Car:**
   - The V2N (FOTA) sub-system updates the firmware of the slave car, enabling it to receive and respond to signals from the master car's ultrasonic sensors.

3. **Real-time Vehicle Communication:**
   - The integrated system ensures that both master and slave cars can communicate effectively, adapt to traffic conditions, and respond appropriately to obstacles.

## Installation and Setup

To run the integrated V2X system, follow these steps:

1. **Software Requirements:**
   - Use Proteus version 8.17 for simulation.
   - Use a virtual serial ports emulator in pair mode.

2. **Hardware Setup:**
   - Connect the components as shown in the Proteus schematic for the V2X integration.
   - Configure the appropriate COM ports in the virtual serial ports emulator and ensure they match the configuration in Proteus.

3. **Running the Simulation:**
   - Load the Proteus schematic for the V2X integration.
   - Ensure that the virtual serial ports are correctly paired and configured.
   - Run the simulation in Proteus to observe the integrated system in action.

## License
This project is licensed under the GPL-3.0 License.
