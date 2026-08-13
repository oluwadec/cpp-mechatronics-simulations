#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>

// Convert degrees to radians for trigonometric functions
constexpr double DEG_TO_RAD = 3.14159265358979323846 / 180.0;

// Structure representing the physical state of the Robotic Arm
struct RobotState {
    double angleDeg = 0.0;     // Joint angle in degrees
    double armLength = 5.0;    // Fixed arm length (e.g., 5 meters)
    bool gripperClosed = false;// false = OPEN, true = CLOSED
    
    // Calculates Cartesian (X, Y) coordinates using Forward Kinematics
    double getX() const { return armLength * std::cos(angleDeg * DEG_TO_RAD); }
    double getY() const { return armLength * std::sin(angleDeg * DEG_TO_RAD); }
};

// Base Command Class (Interface)
class Command {
public:
    virtual ~Command() = default;
    virtual void execute(RobotState& robot) = 0;
};

// Concrete Command: Rotate Joint
class RotateCommand : public Command {
private:
    double deltaAngle;
public:
    RotateCommand(double angle) : deltaAngle(angle) {}
    
    void execute(RobotState& robot) override {
        robot.angleDeg += deltaAngle;
        std::cout << "[EXECUTED] Rotated joint by " << deltaAngle << " degrees.\n";
    }
};

// Concrete Command: Operate Gripper
class GripperCommand : public Command {
private:
    bool closeGripper;
public:
    GripperCommand(bool close) : closeGripper(close) {}
    
    void execute(RobotState& robot) override {
        robot.gripperClosed = closeGripper;
        std::cout << "[EXECUTED] Gripper " << (closeGripper ? "CLOSED (Object Grabbed)" : "OPENED (Object Released)") << ".\n";
    }
};

// Robot Controller class managing execution history
class RobotController {
private:
    RobotState state;
    std::vector<Command*> commandQueue;

public:
    ~RobotController() {
        for (Command* cmd : commandQueue) {
            delete cmd;
        }
    }

    void addCommand(Command* cmd) {
        commandQueue.push_back(cmd);
    }

    void executeAll() {
        std::cout << "\n--- Executing Queued Robot Commands ---\n";
        for (Command* cmd : commandQueue) {
            cmd->execute(state);
            displayStatus();
        }
    }

    void displayStatus() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "  -> Current Pos: X = " << state.getX() 
                  << " | Y = " << state.getY() 
                  << " | Angle = " << state.angleDeg << " deg"
                  << " | Gripper = " << (state.gripperClosed ? "CLOSED" : "OPEN") << "\n\n";
    }
};

int main() {
    std::cout << "    ROBOT ARM KINEMATICS SIMULATOR      \n";

    RobotController controller;

    // Queue up sequence of robotic actions
    controller.addCommand(new RotateCommand(45.0));   // Rotate to 45 deg
    controller.addCommand(new GripperCommand(true));  // Grab object
    controller.addCommand(new RotateCommand(45.0));   // Rotate further to 90 deg
    controller.addCommand(new GripperCommand(false)); // Drop object

    // Run command queue
    controller.executeAll();

    return 0;
}