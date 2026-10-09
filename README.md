# Mechatronics Control Systems in C++

A focused suite of pure C++ implementations covering core concepts in control theory, linear algebra, and robotic kinematics.  
Built from scratch with zero external dependencies to demonstrate clean software architecture applied to real engineering problems.

---

## Featured Modules

### 1. Matrix Mathematics Library  
**Path:** `1_MatrixLibrary/`

Custom linear algebra toolkit designed for spatial transformations and state-space calculations used in robotics and sensor fusion.

**Engineering Concepts**
- Coordinate transformations and rotations
- Matrix dimension safety and alignment
- State representation for control systems

**C++ Highlights**
- Encapsulated dynamic 2-D structure (`std::vector<std::vector<double>>`)
- Bounds-checked element access with proper exception handling
- Matrix multiplication with dimension validation
- Efficient transpose operation

---

### 2. PID Controller Simulator  
**Path:** `2_PIDController/`

Interactive closed-loop PID controller regulating a continuous dynamic system (motor speed / position style plant).

**Engineering Concepts**
- Proportional, Integral, and Derivative control
- Steady-state error elimination
- Overshoot damping and derivative kick awareness
- Discrete-time approximation of continuous control laws

**C++ Highlights**
- Clean OOP design with configurable `Kp`, `Ki`, `Kd`
- Numerical integration and differentiation of the error signal
- Fixed time-step simulation loop
- Real-time target vs. actual tracking output

---

### 3. Robot Arm Forward Kinematics Simulator  
**Path:** `3_RobotArmSimulator/`

2-D robotic manipulator that converts joint commands into Cartesian end-effector positions using forward kinematics.

**Engineering Concepts**
- Forward kinematics (`x = r · cosθ`, `y = r · sinθ`)
- End-effector state tracking
- Basic trajectory / command sequencing

**C++ Highlights**
- Command design pattern (polymorphic `Command` interface)
- Separation of command queuing from robot state execution
- Proper resource management with custom destructors
- Standard `<cmath>` trigonometric transforms

---

## Build & Run

All modules are standalone C++17 programs using only the standard library.

```bash
# Example – build the PID controller
cd 2_PIDController
g++ -std=c++17 -O2 -o pid main.cpp
./pid
```

Repeat the same pattern for the other modules.

---

## Design Philosophy

- Zero third-party dependencies
- Emphasis on readable, maintainable, and educational code
- Clear mapping between engineering theory and software implementation
- Suitable as portfolio evidence of control systems + C++ proficiency

---

## Repository Layout
```
mechatronics-cpp-projects/
├── 1_MatrixLibrary/
├── 2_PIDController/
├── 3_RobotArmSimulator/
└── README.md
```

---

**Author:** Aboderin Logo (`oluwadec`)  
**Domain:** Mechatronics Engineering · Control Systems · Robotics Software
