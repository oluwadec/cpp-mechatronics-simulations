# Mechatronics & Embedded Systems C++ Suite

<p center>
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="C++" width="60" height="60"/>
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/gcc/gcc-original.svg" alt="GCC" width="60" height="60"/>
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/git/git-original.svg" alt="Git" width="60" height="60"/>
</p>

A collection of lightweight, Object-Oriented C++ projects modeling core engineering systems, control theory, and spatial kinematics. Built from scratch without external third-party dependencies to showcase low-level algorithms, data structure design, and software architecture principles applied to robotics.

---

## 📂 Featured Projects

### 1. 🧮 Matrix Mathematics Library (`1_MatrixLibrary/`)
A custom linear algebra library designed to handle spatial coordinate transformations and state-space calculations required in robotics kinematics and sensor processing.

* **Engineering Concepts:** State transformations, coordinate rotations, matrix dimension alignment.
* **C++ Implementation:** 
  * Encapsulated dynamic 2D grid structure using `std::vector<std::vector<double>>`.
  * Safe memory element manipulation with bound checking (`std::out_of_range`).
  * Optimized matrix multiplication ($A \cdot B$) with dimension mismatch exception handling.
  * Transpose matrix calculation swapping dimensions ($R \times C \rightarrow C \times R$).

### 2. 🎛️ PID Controller & Physical System Simulator (`2_PIDController/`)
An interactive simulation of a Closed-Loop Proportional-Integral-Derivative (PID) controller regulating a continuous dynamic system (e.g., motor speed control or robotic arm position).

* **Engineering Concepts:** Closed-loop feedback systems, steady-state error accumulation, derivative overshoot prevention.
* **C++ Implementation:**
  * Numerical approximation of error integration ($K_i \cdot \int e\,dt$) and differentiation ($K_d \cdot \frac{de}{dt}$).
  * Configurable tuning parameters ($K_p, K_i, K_d$) via clean OOP class constructors.
  * Continuous time-step loop ($\Delta t$) tracking target vs. actual values step-by-step.

### 3. 🦾 Command-Pattern Robot Arm Kinematics (`3_RobotArmSimulator/`)
A 2D robotic manipulator simulator that translates discrete operational commands into dynamic Cartesian coordinates $(X, Y)$ using Forward Kinematics.

* **Engineering Concepts:** Forward Kinematics ($X = r \cdot \cos\theta$, $Y = r \cdot \sin\theta$), End-Effector Gripper State tracking, Manipulator trajectory planning.
* **C++ Implementation:**
  * **Command Design Pattern:** Polymorphic interface (`Command` base class) separating command queuing from robot execution state.
  * Automatic memory cleanup with custom destructor management for command pointers.
  * Trigonometric transformations using standard C++ `<cmath>` utilities.

---

## 🛠️ Build & Run Instructions

All projects are standalone standard C++17 programs and can be compiled using `g++` (or any modern C++ compiler).

### Prerequisite
Ensure you have GCC/G++ installed:
```bash
g++ --version
