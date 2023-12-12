#include "main.h"
#include "ports.h"
#include "string.h"
#include "iostream"
#include "PID.h"
using namespace pros;
using namespace std;

void initialize()
{
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
}

void disabled() {}
void competition_initialize() {}
void autonomous() 
{
	Task runPID(drivePID);
	resetDriveSensors = true;

	// targetPosition = 300;

	delay(1000);
}

void opcontrol()
{
	while (true)
	{
		float lateral = master.get_analog(ANALOG_LEFT_Y);
		float rotational = master.get_analog(ANALOG_RIGHT_X);

		rightDrive = lateral - rotational;
		leftDrive = lateral + rotational;

		if (master.get_digital(E_CONTROLLER_DIGITAL_R1))
			flyWheel.move_voltage(12000);
		else if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
			flyWheel.move_voltage(-12000);
		else
			flyWheel.brake();

		// if (master.get_digital(E_CONTROLLER_DIGITAL_L1))
		// 	// ---
		// else if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
		// 	// ---

		// if (master.get_digital(E_CONTROLLER_DIGITAL_X))
		// 	// ---

		delay(15);
	}
}