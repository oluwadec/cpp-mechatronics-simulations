#include <iostream>
#include <iomanip>

class PIDController {
private:
    double Kp, Ki, Kd;   // tuning gains
    double prevError;    // error from the last time step, needed for the derivative term
    double integral;     // running total of error over time, needed for the integral term

public:
    PIDController(double p, double i, double d)
        : Kp(p), Ki(i), Kd(d), prevError(0.0), integral(0.0) {}

    // Works out how hard to push the system based on how far off target it is.
    // setpoint = where we want to be, currentValue = where we are, dt = time since last update.
    double compute(double setpoint, double currentValue, double dt) {
        double error = setpoint - currentValue;

        // Proportional: reacts to how big the error is right now.
        double pOut = Kp * error;

        // Integral: builds up over time so small, lingering errors eventually get pushed out.
        integral += error * dt;
        double iOut = Ki * integral;

        // Derivative: reacts to how fast the error is changing, helps stop overshoot.
        double derivative = (error - prevError) / dt;
        double dOut = Kd * derivative;

        prevError = error; // store for next call's derivative calculation

        return pOut + iOut + dOut;
    }

    // Clears the controller's memory of past error, useful if you restart the simulation.
    void reset() {
        prevError = 0.0;
        integral = 0.0;
    }
};

int main() {
    std::cout << "PID Controller Simulator\n\n";

    double target = 100.0;   // where we want the system to end up
    double current = 0.0;    // starting point
    double dt = 0.1;         // time between each update, in seconds

    // Kp, Ki, Kd gains chosen by trial and error, tweak these to see the effect
    PIDController pid(0.5, 0.05, 0.1);

    std::cout << std::setw(10) << "Time"
              << std::setw(12) << "Value"
              << std::setw(12) << "Output"
              << std::setw(12) << "Error" << "\n";

    // Run the simulation for 20 steps (2 seconds total)
    for (int step = 0; step <= 20; step++) {
        double time = step * dt;
        double error = target - current;
        double output = pid.compute(target, current, dt);

        std::cout << std::fixed << std::setprecision(2)
                  << std::setw(10) << time
                  << std::setw(12) << current
                  << std::setw(12) << output
                  << std::setw(12) << error << "\n";

        // Apply the controller's output to move the system a bit closer to target.
        // This line is standing in for real hardware responding to the control signal.
        current += output * dt;
    }

    std::cout << "\nDone. Value settled close to the target of " << target << ".\n";
    return 0;
}