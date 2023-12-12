#include "ports.h"

// -- Drivetrain
const double kP = 1;
const double kI = 0.00;
const double kD = 0.00;

const double turn_kP = 1;
const double turn_kI = 0.00;
const double turn_kD = 0.00;

// -- PID Variables
int error;
int prevError;
int derivative;
int totalError;
int targetPosition;

int turn_error;
int turn_prevError;
int turn_derivative;
int turn_totalError;
int turn_targetPosition;

bool enablePID = true;
bool resetDriveSensors = false;

int drivePID(){
    while (enablePID) 
    {
        if (resetDriveSensors)
        {
            resetDriveSensors = false;
            leftDriveA.tare_position();
            rightDriveA.tare_position();
        }

        int leftPosition = leftDriveA.get_position();
        int rightPosition = rightDriveA.get_position();

        // -- Average Position
        int averagePosition = (leftPosition + rightPosition)/2;

        // -- Derivative
        derivative = error - prevError;

        // -- Integral
        totalError += error;

        double lateralMotion = error * kP + derivative * kD + totalError * kI;

        // -- Turn difference
        int turnDifference = leftPosition - rightPosition;

        // -- Turn potential
        turn_error = turnDifference - targetPosition;

        // -- Turn derivative
        turn_derivative = turn_error - turn_prevError;

        // -- Turn integral
        turn_totalError += turn_error;

        double turnMotion = turn_error * kP + turn_derivative * kD + turn_totalError * kI;

        leftDrive.move_voltage(lateralMotion + turnMotion);
        rightDrive.move_voltage(lateralMotion - turnMotion);

        prevError = error;
        turn_prevError = turn_error;
        delay(20);
    }
    return 1;
}