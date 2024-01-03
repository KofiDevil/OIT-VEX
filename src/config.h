#include "main.h"
using namespace pros;
using namespace std;

Motor leftDriveA = Motor(1, MOTOR_GEAR_BLUE, false);
Motor leftDriveB = Motor(2, MOTOR_GEAR_BLUE, false);
Motor leftDriveC = Motor(3, MOTOR_GEAR_BLUE, false);

Motor rightDriveA = Motor(4, MOTOR_GEAR_BLUE, false);
Motor rightDriveB = Motor(5, MOTOR_GEAR_BLUE, false);
Motor rightDriveC = Motor(6, MOTOR_GEAR_BLUE, false);

Motor_Group leftDrive({leftDriveA, leftDriveB, leftDriveC});
Motor_Group rightDrive({rightDriveA, rightDriveB, rightDriveC});
Motor_Group allDrive({leftDriveA, leftDriveB, leftDriveC, rightDriveA, rightDriveB, rightDriveC});

void motorSetBrake()
{
    leftDriveA.set_brake_mode(MOTOR_BRAKE_COAST);
    leftDriveB.set_brake_mode(MOTOR_BRAKE_COAST);
    leftDriveC.set_brake_mode(MOTOR_BRAKE_COAST);

    rightDriveA.set_brake_mode(MOTOR_BRAKE_COAST);
    rightDriveB.set_brake_mode(MOTOR_BRAKE_COAST);
    rightDriveC.set_brake_mode(MOTOR_BRAKE_COAST);
}
