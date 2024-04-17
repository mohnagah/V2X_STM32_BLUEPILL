# V2I Sub-system
The V2I (Vehicle-to-Infrastructure) sub-system facilitates communication between the Roadside Unit (RSU), representing the traffic light system, and the master vehicle in the V2V sub-system. This sub-system ensures seamless delivery of traffic light status to the master vehicle, enabling adaptive driving strategies and efficient traffic flow.

## Overview
The V2I sub-system is crucial in enhancing road safety and traffic efficiency by providing real-time updates on traffic light status to the master vehicle. By integrating with the RSU, the sub-system enables the master vehicle to receive continuous traffic light information, allowing it to make informed decisions while navigating through intersections.

## Features
- RSU Integration: Establish communication with the Roadside Unit (RSU) to receive traffic light status updates.
- Real-time Updates: Delivers continuous traffic light status to the master vehicle, ensuring timely and accurate information.
- Adaptive Driving: Enables the master vehicle to adapt its driving behavior based on traffic light signals, optimizing traffic flow and reducing congestion.
  
## Installation and Setup
To run the V2I sub-system, follow these steps:

### 1. Hardware Setup:

- Connect the components as shown in the V2I diagram using Proteus 8.13 or later.
- Ensure that the virtual ports in the HDD Virtual Serial Port Tools application are bridged correctly:
  - COM1 and COM2 for V2V master and slave cars' communication.
  - COM3 (for RSU) connected with COM4 (in the master car through USART3) for traffic light status sharing.

### 2. Configuration:
- Configure the traffic light time according to your requirements in the TL_TIMER_config.h file.

### 3. Testing:
- Use the included Proteus project (for Proteus 8.13) to test the sub-system.
- Verify the communication between the RSU and the master vehicle by observing traffic light status updates in the simulation.
  
## Proteus Project
A Proteus project (compatible with Proteus 8.13 or later) is included in the repository to facilitate testing of the V2I sub-system. The project provides a simulated environment for evaluating the functionality and performance of the sub-system before deployment in real-world scenarios.
![image](https://github.com/mohnagah/V2X_STM32_BLUEPILL/assets/157398651/2865d2d2-39a2-4ef4-b773-a3902f2fe6ae)

## Video
  [V2I Project Video](https://drive.google.com/file/d/1kfDJT_t7LR6rfkv6qvNyGiT7B-GUHLA3/view?usp=sharing)
## License
This sub-system is part of the V2X Project and is licensed under the [GPL-3.0 License](https://github.com/mohnagah/V2X_STM32_BLUEPILL/blob/main/LICENSE).
