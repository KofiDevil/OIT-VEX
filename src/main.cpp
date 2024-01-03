#include "main.h"
#include "config.h"
using namespace pros;
using namespace std;

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
}

void disabled() {}
void competition_initialize() {}
void autonomous() {}

void opcontrol() {
	motorSetBrake();
	while (true) {
		pros::delay(15);
	}
}
