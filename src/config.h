#include "main.h"
using namespace pros;

Controller master(E_CONTROLLER_MASTER);

/*--------------------------------------------------------------------*/ // Left drive config
Motor leftDriveA(1, true);
Motor leftDriveB(2);
Motor leftDriveC(3, true);
Motor leftDriveD(4);
Motor leftDriveE(5, true);

/*--------------------------------------------------------------------*/ // Right drive config
Motor rightDriveA(6);
Motor rightDriveB(7, true);
Motor rightDriveC(8);
Motor rightDriveD(9, true);
Motor rightDriveE(10);

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
    leftDriveA.set_brake_mode(MOTOR_BRAKE_COAST);
    leftDriveB.set_brake_mode(MOTOR_BRAKE_COAST);
	leftDriveC.set_brake_mode(MOTOR_BRAKE_COAST);
	leftDriveD.set_brake_mode(MOTOR_BRAKE_COAST);
	leftDriveE.set_brake_mode(MOTOR_BRAKE_COAST);

	rightDriveA.set_brake_mode(MOTOR_BRAKE_COAST);
	rightDriveB.set_brake_mode(MOTOR_BRAKE_COAST);
	rightDriveC.set_brake_mode(MOTOR_BRAKE_COAST);
	rightDriveD.set_brake_mode(MOTOR_BRAKE_COAST);
	rightDriveE.set_brake_mode(MOTOR_BRAKE_COAST);

    return 0;
}

int brakeType();