#include "main.h"
#include "config.h"
#include "string.h"
#include "iostream"
using namespace pros;
using namespace std;

void initialize()
{
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
}

int splitstr(string arguments, string deli = "-")
{
	int argument_array [5];

	int start = 0;
	int end = arguments.find(deli);
	while (end != -1)
	{
		arguments.substr(start, end - start);
		start = end + deli.size();
		end = arguments.find(deli, start);

		//argument_array[sizeof(argument_array) + 1] = arguments.substr(start, end - start);
	}
}

void cmd(char command, string arguments)
{
	switch (command)
	{
	case 'f':
		//allDrive.move();
		break;
	
	default:
		break;
	}
}
void disabled() {}
void competition_initialize() {}
void autonomous() {}

void isPressed(char buttonPressed)
{
	switch (buttonPressed)
	{
	case 'R':
		flyWheel.move(127);
		break;
	case 'E':
		flyWheel.move(-127);
		break;
	case 'L':
		break;
	case 'K':
		break;
	case 'X':
		break;
	default:
		break;
	}
}

void opcontrol()
{
	while (true)
	{
		float lateral = master.get_analog(ANALOG_LEFT_Y);
		float rotational = master.get_analog(ANALOG_RIGHT_X);

		rightDrive = lateral + rotational;
		leftDrive = lateral - rotational;

		if (master.get_digital(E_CONTROLLER_DIGITAL_R1))
			isPressed('R');
		else if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
			isPressed('E');
		else
			flyWheel.brake();

		if (master.get_digital(E_CONTROLLER_DIGITAL_L1))
			isPressed('L');
		else if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
			isPressed('K');

		if (master.get_digital(E_CONTROLLER_DIGITAL_X))
			isPressed('X');

		delay(20);
	}
}