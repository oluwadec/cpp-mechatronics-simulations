# Mechatronics Control Systems in Modern C++

**Pure C++ implementations of core control and robotics concepts — zero external dependencies.**

This repository contains clean, educational implementations of fundamental building blocks used in mechatronics and robotics software:

1. **Matrix Mathematics Library**
2. **PID Controller Simulator**
3. **2D Robot Arm Forward Kinematics Simulator**

Each module is deliberately written to demonstrate both the *engineering concept* and *solid C++ design*.

---

## Why This Repository Exists

Most student control/robotics code is either:
- Written in MATLAB/Python (great for learning theory, weaker for systems skills), or
- Buried inside large frameworks.

This project intentionally stays in pure C++ so that:

- Ownership, memory, and performance characteristics are visible
- The mapping between theory and implementation is clear
- The code can serve as credible portfolio evidence of both control knowledge *and* C++ competence

---

## Modules

### 1. Matrix Mathematics Library
**Path:** `1_MatrixLibrary/`

A minimal but carefully designed matrix class for linear algebra operations commonly required in robotics and control (transformations, state-space work, etc.).

**Engineering Concepts**
- Coordinate transformations
- State representation
- Matrix dimension safety

**C++ Design Highlights**
- Encapsulated dynamic 2D storage
- Bounds-checked access with meaningful exceptions
- Dimension validation on multiplication
- Clean transpose implementation

---

### 2. PID Controller Simulator
**Path:** `2_PIDController/`

Discrete-time PID controller regulating a simple dynamic plant (motor-style system). Demonstrates the classic control loop in software form.

**Engineering Concepts**
- Proportional, Integral, and Derivative terms
- Steady-state error elimination
- Overshoot and derivative kick awareness
- Discrete approximation of continuous control laws
- Fixed-timestep simulation

**C++ Design Highlights**
- Clean OOP design with configurable gains
- Explicit numerical integration/differentiation of error
- Clear separation between controller and plant

**Key Performance Metrics to Observe**
- Rise time
- Overshoot (%)
- Settling time
- Steady-state error

---

### 3. Robot Arm Forward Kinematics Simulator
**Path:** `3_RobotArmSimulator/`

2D robotic manipulator that converts joint angles into Cartesian end-effector position using basic forward kinematics.

**Engineering Concepts**
- Forward kinematics (`x = L · cosθ`, `y = L · sinθ` and multi-link extension)
- End-effector tracking
- Simple command sequencing

**C++ Design Highlights**
- Command pattern (polymorphic command interface)
- Separation of command queue from robot state
- Clear resource management

---

## Build & Run

All modules are standalone C++17 programs using only the standard library.

```bash
# Example: PID Controller
cd 2_PIDController
g++ -std=c++17 -O2 -Wall -Wextra -o pid main.cpp
./pid
```

The same pattern applies to the other modules.

---

## Design Philosophy

- **Zero third-party dependencies** — forces understanding of the fundamentals
- **Readability first** — code should be explainable in an interview
- **Clear mapping** between theory and implementation
- **Educational value** over feature completeness

---

## Future Improvements

- Add simple data logging + CSV export for analysis
- Parameter sweeps for PID tuning demonstration
- Inverse kinematics for the robot arm
- Basic visualization output (ASCII or simple plot data)
- Unit tests for the matrix library

---

## Author

**Aboderin Logo** (`oluwadec`)  
Mechatronics Engineering Student  
Focus: Control Systems · Robotics Software · Systems Programming in C++

---

*Built to learn deeply. Documented to communicate clearly.*
