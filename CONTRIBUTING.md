# Contributing to Mechatronics Control Systems in C++

Thank you for your interest in improving this project.

## Ways to Contribute

- Improve documentation and explanations of control theory ↔ code mapping
- Add unit tests for the Matrix library
- Improve numerical robustness or edge-case handling
- Add data logging / CSV export for the PID simulator
- Implement inverse kinematics for the robot arm
- Suggest better educational examples

## Guidelines

1. Keep the **zero external dependency** philosophy unless there is a very strong reason to change it.
2. Prefer clarity and educational value over micro-optimizations.
3. Match the existing code style (modern C++, readable names, clear comments on non-obvious engineering decisions).
4. Open an issue first for larger changes so we can discuss direction.

## Development Setup

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o <target> main.cpp
```

Pull requests are welcome.
