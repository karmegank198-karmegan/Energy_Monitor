 # IoT-Based Smart Energy Meter Monitoring System

# Project Overview

The **IoT-Based Smart Energy Meter Monitoring System** is designed to collect electricity consumption readings from energy meters and transmit the data to a cloud server for centralized monitoring and visualization.

The system uses **RS485 serial communication** to retrieve energy meter readings. An **RS485-to-TTL converter** interfaces the meter with an ESP32 microcontroller, which processes the received data and publishes it to the cloud using the **MQTT (Message Queuing Telemetry Transport) protocol**.

The data is transmitted to the **BITSathy cloud server**, where it is made available for visualization through an energy monitoring dashboard.

This approach enables remote monitoring of energy consumption without requiring users to manually collect readings from individual meters.

# Project Objectives

- Retrieve energy meter readings through RS485 serial communication.
- Interface the energy meter with an ESP32 using an RS485-to-TTL converter.
- Establish Wi-Fi connectivity using the ESP32.
- Transmit energy data using the MQTT communication protocol.
- Publish meter readings to the BITSathy cloud server.
- Monitor energy consumption through a centralized dashboard.
- Support remote access to energy monitoring information.
- Provide a foundation for analyzing historical electricity consumption.

# System Architecture

The system consists of an energy meter, communication interface, embedded controller, cloud communication protocol, cloud server, and monitoring dashboard.

# System Block Diagram

 
        Electrical Loads
               |
               v
          Energy Meter
               |
               v
      RS485 Serial Communication
               |
               v
       RS485-to-TTL Converter
               |
               v
             ESP32
               |
               v
         Wi-Fi Connection
               |
               v
        MQTT Communication
               |
               v
      BITSathy Cloud Server
               |
               v
       Energy Monitoring
           Dashboard
               |
               v
       Data Visualization


# Data Flow

**Energy Meter → RS485 → RS485-to-TTL Converter → ESP32 → Wi-Fi → MQTT → BITSathy Cloud Server → Dashboard**

# Hardware Components

# 1. Energy Meter

The energy meter measures electrical parameters and provides readings through its RS485 communication interface.

Depending on the meter model, the available readings may include:

- Voltage
- Current
- Active power
- Power factor
- Frequency
- Cumulative energy consumption

The exact parameters depend on the energy meter's specifications and communication protocol.

# 2. RS485-to-TTL Converter

RS485 is a serial communication standard commonly used in industrial monitoring systems.

The RS485-to-TTL converter provides the electrical interface required to connect the meter's RS485 communication lines to the ESP32's UART interface.

Its main functions are:

- Converting RS485 differential signals into UART-compatible logic signals.
- Supporting serial communication between the meter and the ESP32.
- Enabling the ESP32 to receive energy meter readings.

The converter must be compatible with the selected meter and ESP32 logic voltage.

# 3. ESP32 Microcontroller

The ESP32 acts as the main embedded controller.

It is responsible for:

- Receiving serial data from the energy meter.
- Communicating with the meter through the RS485 interface.
- Extracting the required energy readings.
- Establishing Wi-Fi connectivity.
- Publishing the collected data to the cloud using MQTT.

The ESP32 provides the connection between the energy meter and the cloud monitoring system.

# 4. Wi-Fi Connectivity

The ESP32 uses Wi-Fi to establish a network connection with the cloud infrastructure.

This allows energy readings to be transmitted remotely without requiring a direct physical connection between the energy meter and the monitoring dashboard.

---

# Communication Technologies

# 1. RS485 Serial Communication

RS485 is used for communication between the energy meter and the ESP32 through an RS485-to-TTL converter.

It is widely used in industrial environments because it supports reliable communication over suitable cable lengths and in electrically noisy environments.

The meter may use a protocol such as Modbus RTU over RS485, depending on its configuration.

The communication settings must match the meter's requirements, including:

- Baud rate
- Data bits
- Parity
- Stop bits
- Device address, if applicable

**Note:** Modbus RTU should only be specified as the actual protocol if it is supported and used by the selected energy meter.

# 2. UART Communication

The ESP32 communicates with the TTL side of the converter using a UART interface.

UART provides serial transmission and reception between the ESP32 and the converter.

The ESP32 reads the incoming data and processes it according to the meter's communication protocol.

# 3. MQTT Protocol

MQTT stands for **Message Queuing Telemetry Transport**.

It is a lightweight messaging protocol commonly used in IoT applications.

In this project, MQTT is used to transmit energy meter readings from the ESP32 to the cloud infrastructure.

# How MQTT Works

1. The ESP32 connects to the network.
2. It establishes a connection with the configured MQTT broker.
3. It publishes energy meter readings to the configured MQTT topic.
4. The cloud infrastructure receives the published data.
5. The received readings are stored or processed for monitoring.
6. The dashboard displays the available energy information.

MQTT reduces communication overhead and is suitable for applications that periodically transmit sensor and meter data.

---

# BITSathy Cloud Integration

The BITSathy cloud server acts as the centralized destination for the energy monitoring data.

After receiving readings from the energy meter, the ESP32 publishes the information using MQTT according to the configured cloud connection and message format.

The cloud infrastructure processes the incoming information and makes the data available to the monitoring application.

# Cloud Processing Workflow


ESP32
  |
  v
MQTT Data Publishing
  |
  v
BITSathy Cloud Infrastructure
  |
  v
Data Reception and Processing
  |
  v
Energy Data Storage
  |
  v
Dashboard Data Retrieval
  |
  v
Energy Monitoring Dashboard


The exact implementation of data reception, storage, and retrieval depends on the BITSathy cloud services and APIs configured for the project.



# Energy Monitoring Dashboard

The energy monitoring dashboard provides a centralized interface for viewing the energy meter readings received by the cloud server.

It allows users to monitor energy information without connecting directly to the physical meter.

# Dashboard Features

Depending on the configured dashboard, the system can display:

- Energy meter readings.
- Meter-wise energy consumption.
- Historical energy data.
- Electrical parameter values supported by the meter.
- Graphical representations of energy consumption.
- Consumption trends over selected time periods.

# Dashboard Workflow

1. The energy meter provides readings through RS485.
2. The ESP32 receives the data through the TTL converter.
3. The ESP32 publishes the readings using MQTT.
4. The BITSathy cloud server receives and processes the information.
5. The dashboard retrieves the available data.
6. Users view the readings and consumption information through the dashboard.

This arrangement enables centralized monitoring of energy consumption from connected meters.

---

# Working Principle

The complete system operates through the following steps.

# Step 1: Read Energy Meter Data

The energy meter measures electrical parameters and makes its readings available through its RS485 interface.

# Step 2: Transfer Data Through the Converter

The RS485-to-TTL converter interfaces the meter's RS485 signals with the ESP32 UART interface.

# Step 3: Process Data Using the ESP32

The ESP32 receives the serial communication data and extracts the required readings according to the meter's communication protocol.

# Step 4: Connect to Wi-Fi

The ESP32 connects to the configured wireless network to establish internet connectivity.

# Step 5: Publish Data Using MQTT

The ESP32 publishes the collected readings to the configured MQTT broker and topic.

# Step 6: Process Data on the Cloud Server

The BITSathy cloud infrastructure receives the published readings and processes them according to the configured application.

# Step 7: Display Data on the Dashboard

The dashboard retrieves the available energy information and displays it for monitoring and analysis.

---

# Software and Development Tools

| Component | Technology |
|---|---|
| Embedded controller | ESP32 |
| Firmware programming | C/C++ |
| Serial communication | UART |
| Meter communication interface | RS485 |
| Signal conversion | RS485-to-TTL converter |
| Wireless connectivity | Wi-Fi |
| IoT messaging protocol | MQTT |
| Cloud platform | BITSathy cloud infrastructure |
| Development environment | PlatformIO |
| Version control | Git and GitHub |



# Repository Structure


Energy_Monitor/
│
├── .vscode/
│   ├── extensions.json
│   └── settings.json
│
├── include/
│   ├── Get_data.h
│   ├── Values.h
│   └── README
│
├── lib/
│   └── README
│
├── src/
│   └── main.cpp
│
├── test/
│   └── README
│
├── .gitignore
├── platformio.ini
└── README.md


# File Descriptions

| File | Description |
|---|---|
| `src/main.cpp` | Contains the main embedded application and communication logic. |
| `include/Get_data.h` | Contains declarations or functionality related to data collection. |
| `include/Values.h` | Contains project-specific values and configuration definitions. |
| `platformio.ini` | Configures the PlatformIO build environment and target board. |
| `.gitignore` | Specifies files that Git should ignore. |
| `README.md` | Documents the project architecture, hardware, communication, and operation. |

---

# Getting Started

# Prerequisites

Before setting up the project, ensure that you have:

- ESP32 development board.
- Energy meter with an RS485 communication interface.
- Compatible RS485-to-TTL converter.
- Appropriate power supply and wiring.
- Wi-Fi connectivity.
- Access to the configured MQTT broker and BITSathy cloud services.
- Visual Studio Code.
- PlatformIO extension.

# Step 1: Clone the Repository

git clone https://github.com/karmegank198-karmegan/Energy_Monitor.git

Navigate to the project directory:


cd Energy_Monitor


# Step 2: Configure the Hardware

Connect the energy meter to the RS485 side of the converter.

Connect the converter's TTL interface to the appropriate ESP32 UART pins.

Verify the power supply, logic voltage, signal connections, and communication settings before powering the system.

The exact wiring depends on the meter, converter, and ESP32 board.

# Step 3: Configure the Firmware

Open the project in Visual Studio Code with PlatformIO installed.

Review the following files:

platformio.ini
src/main.cpp
include/Get_data.h
include/Values.h

Configure the appropriate:

- UART pins.
- Serial communication parameters.
- Energy meter address, if applicable.
- Wi-Fi settings.
- MQTT broker address and port.
- MQTT credentials, if required.
- MQTT topic.
- Cloud message format.

# Step 4: Build the Firmware

Run:

pio run

# Step 5: Upload the Firmware

Connect the ESP32 to your computer and execute:

pio run --target upload

# Step 6: Verify Communication

After uploading the firmware:

1. Confirm that the ESP32 starts correctly.
2. Verify serial communication with the energy meter.
3. Check that valid meter readings are received.
4. Confirm that the ESP32 connects to Wi-Fi.
5. Verify the MQTT connection.
6. Confirm that readings are published to the correct MQTT topic.
7. Check that the BITSathy cloud server receives the data.

# Step 7: View the Dashboard

Open the configured energy monitoring dashboard.

Verify that the readings received by the cloud server are displayed correctly.

The dashboard URL and access permissions depend on the deployed BITSathy monitoring application.

---

# Advantages

- Enables remote monitoring of energy meter readings.
- Uses RS485 for communication with compatible energy meters.
- Connects industrial-style serial interfaces to an ESP32.
- Uses MQTT for lightweight IoT data transmission.
- Supports centralized cloud-based energy monitoring.
- Reduces the need for manual meter reading.
- Makes historical energy information available through a dashboard.
- Provides a foundation for expanding energy monitoring capabilities.

---

# Future Enhancements

Possible future improvements include:

- Supporting additional energy meters.
- Monitoring more electrical parameters.
- Adding communication failure detection.
- Implementing automatic reconnection after network interruptions.
- Improving cloud data visualization.
- Generating downloadable energy consumption reports.
- Adding configurable threshold alerts.
- Integrating energy consumption forecasting as a separate module.

---

# Conclusion

The IoT-Based Smart Energy Meter Monitoring System integrates **RS485 serial communication, an RS485-to-TTL converter, ESP32, Wi-Fi, MQTT, and the BITSathy cloud server** to enable remote energy monitoring.

The energy meter provides the electrical readings, the converter interfaces the communication signals, and the ESP32 collects and transmits the data to the cloud using MQTT.

The cloud server processes the received information and makes it available through an energy monitoring dashboard.

This system provides a practical approach to centralized energy monitoring and establishes a foundation for future smart energy management applications.

---

# Author

**Karmegan K**

GitHub: [@karmegank198-karmegan](https://github.com/karmegank198-karmegan)

Project Repository: [Energy_Monitor](https://github.com/karmegank198-karmegan/Energy_Monitor)
