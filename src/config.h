#include "main.h"
using namespace pros;

Controller master(E_CONTROLLER_MASTER);

/*--------------------------------------------------------------------*/ // Left drive config
Motor leftDriveA(1);
Motor leftDriveB(2);
Motor leftDriveC(3);
Motor leftDriveD(4);
Motor leftDriveE(5);

/*--------------------------------------------------------------------*/ // Right drive config
Motor rightDriveA(6, true);
Motor rightDriveB(7, true);
Motor rightDriveC(8, true);
Motor rightDriveD(9, true);
Motor rightDriveE(10, true);

/*--------------------------------------------------------------------*/ // Fly wheel config
Motor flyWheelA(11);
Motor flyWheelB(12, true);

/*--------------------------------------------------------------------*/ // Motor group config
Motor_Group leftDrive({leftDriveA, leftDriveB, leftDriveC, leftDriveD, leftDriveE});
Motor_Group rightDrive({rightDriveA, rightDriveB, rightDriveC, rightDriveD, rightDriveE});
Motor_Group allDrive({leftDriveA, leftDriveB, leftDriveC, leftDriveD, leftDriveE, rightDriveA, rightDriveB, rightDriveC, rightDriveD, rightDriveE});
Motor_Group flyWheel({flyWheelA, flyWheelB});

int brakeType()
{
    leftDriveA.set_brake_mode(MOTOR_BRAKE_BRAKE);
    leftDriveB.set_brake_mode(MOTOR_BRAKE_BRAKE);
	leftDriveC.set_brake_mode(MOTOR_BRAKE_BRAKE);
	leftDriveD.set_brake_mode(MOTOR_BRAKE_BRAKE);
	leftDriveE.set_brake_mode(MOTOR_BRAKE_BRAKE);

	rightDriveA.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightDriveB.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightDriveC.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightDriveD.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightDriveE.set_brake_mode(MOTOR_BRAKE_BRAKE);

    return 0;
}

int brakeType();