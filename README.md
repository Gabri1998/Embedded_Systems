# Embedded Systems in C Programming

A comprehensive collection of embedded systems programming exercises and projects developed during an embedded systems course, covering seven work packages of increasing complexity in C programming for microcontroller environments.

## Course Overview

This repository contains the practical work from an embedded systems course focused on C programming for microcontroller applications, ranging from basic I/O operations to complex embedded system design and IoT integration.

## Work Packages

### WP1: Fundamentals of C for Embedded Systems
- **Exercise 1**: Basic C programming concepts and syntax
- **Exercise 2**: Control structures and flow control
- **Exercise 3**: Functions and modular programming
- **Exercise 4**: Number systems and conversions (Binary ↔ Hex ↔ Decimal)
- **Exercise 5**: Basic input/output operations

### WP2: Data Representation and Encoding
- **Exercise 1**: Character encoding and manipulation
- **Exercise 2**: Data encoding algorithms
- **Exercise 3**: Data decoding implementations

### WP3: File Operations and Data Processing
- **Exercise 1**: File I/O operations in C
- **Exercise 2**: Text file processing
- **Exercise 3**: Binary file operations
- **Exercise 4**: Data parsing and serialization
- **Exercise 5**: Memory management with files
- **Exercise 6**: Complex file manipulation techniques

### WP4: Hardware Interaction and Low-level Programming
- **Exercise 1**: GPIO (General Purpose Input/Output) programming
- **Exercise 2**: Bit manipulation and register operations
- **Exercise 3**: Interrupt service routines
- **Exercise 4**: Hardware timer/counter programming

### WP5: Communication Protocols
- **Exercise 1**: UART (Universal Asynchronous Receiver/Transmitter) implementation
- **Exercise 2**: I2C (Inter-Integrated Circuit) protocol
- **Exercise 3**: SPI (Serial Peripheral Interface) communication

### WP6: Arduino Programming Basics
- **Exercise 1**: Basic Arduino setup and digital I/O
- **Exercise 2**: Analog input reading and PWM output

### WP7: Advanced Embedded Applications
- **Exercise 1**: Sensor integration and data acquisition
- **Exercise 2**: Actuator control and system integration

## Technical Skills Developed

### C Programming for Embedded Systems
- Low-level memory management
- Pointer arithmetic and manipulation
- Register-level hardware access
- Interrupt-driven programming
- Real-time constraints handling

### Embedded Concepts
- Microcontroller architecture understanding
- Peripheral device interfacing
- Communication protocol implementation
- Power management techniques
- Debugging and testing in constrained environments

### Development Tools
- Cross-compilation toolchains
- Debuggers and emulators
- Version control for embedded projects
- Hardware-in-the-loop testing
- Serial communication tools


## Development Environment

- **Compiler**: GCC for ARM/AVR toolchain
- **IDE**: Visual Studio Code with C/C++ extensions
- **Debugger**: GDB with OpenOCD
- **Hardware**: Various microcontrollers (AVR, ARM Cortex-M)
- **Programming**: In-system programming tools

## Learning Outcomes

1. **Foundational C Skills**: Mastery of C programming in resource-constrained environments
2. **Hardware Understanding**: Direct hardware manipulation and peripheral control
3. **Protocol Implementation**: Hands-on experience with common embedded communication protocols
4. **Debugging Proficiency**: Techniques for debugging embedded systems without printf
5. **System Integration**: Combining software and hardware components into functional systems
6. **Real-time Programming**: Meeting timing constraints and handling concurrent events

## Usage

### Building and Running
```bash
# Navigate to specific work package
cd WP1/

# Compile example exercise
gcc -o exercise1 exercise1.c

# Run compiled program
./exercise1



For Arduino Projects (WP6/WP7)

    Open Arduino IDE

    Load the appropriate .ino file

    Select correct board and port

    Upload to microcontroller

Assessment Structure

Each work package was assessed on:

    Code correctness and functionality

    Adherence to embedded programming best practices

    Documentation and code comments

    Understanding of underlying concepts

    Ability to explain design decisions

Academic Context

This repository represents the practical component of an embedded systems course focusing on:

    Theoretical concepts applied to real hardware

    Incremental skill development through structured exercises

    Hands-on experience with industry-relevant tools and techniques

    Team collaboration on complex embedded projects

Notes

    Exercises progress from basic C concepts to complex embedded applications

    Each work package builds upon skills from previous packages

    Practical examples demonstrate real-world embedded system challenges

    Code includes extensive comments explaining embedded-specific considerations

This collection demonstrates progressive learning in embedded systems programming, from basic C syntax to complex microcontroller applications with real-world constraints.
