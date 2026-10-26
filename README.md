# Micro Flight Computer

A lightweight, C-based flight computer simulation designed to demonstrate core low-level avionics concepts. This project integrates memory management, data packing, and persistent logging into a single main flight loop.

## Key Features

* **Hardware-Level Optimization (Bit-Fields):** The `TelemetryPacket` struct uses bit-fields to compress engine status (1-bit), parachute deployment (1-bit), and flight modes (3-bits), drastically reducing telemetry bandwidth.
* **In-Place State Updates (Pointers):** The `updateKinematics` function utilizes call-by-reference pointers (`*` and `&`) to directly manipulate altitude and velocity memory addresses, avoiding expensive variable copying during the high-frequency flight loop.
* **Black-Box Data Logging (File I/O):** Real-time flight state data is streamed directly to a persistent `flight_log.csv` file using standard C file operations (`fopen`, `fprintf`, `fclose`) for post-flight analysis.

## Project Structure

* `main.c`: Contains the telemetry struct, the kinematic update logic, and the main simulation loop.

## Expected Output

Upon running, the terminal will display the current time, altitude, and velocity. Simultaneously, a flight_log.csv file will be generated in the root directory containing the serialized flight data, ready for numerical analysis via Python (Pandas/Matplotlib).

## How to Build and Run

You can compile and run this simulation using GCC on any standard terminal:

```bash
# Compile the source code
gcc main.c -o flight_computer

# Run the executable
./flight_computer


