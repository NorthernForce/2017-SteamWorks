#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;


const int kFrontRightTalon = 1;
const int kFrontLeftTalon = 3;
const int kBackRightTalon = 4;
const int kBackLeftTalon = 2;


const int kShooter = 5; // THIS IS NOT TRUE
const int kWaterWheels = 6; //THIS IS NOT TRUE
const int kIntake = 7; //THIS IS NOT TRUE
const int kClimber = 8; //THIS IS NOT TRUE


const int kSpikeAddress = 0;
const int kRelayPortA = 0;

const int kAttackJoystickTrigger = 0;
const int kAttackJoystickButton2 = 1;
const int kAttackJoystickButton3 = 2;
const int kAttackJoystickButton4 = 3;
const int kAttackJoystickButton5 = 4;
const int kAttackJoystickButton6 = 5;
const int kAttackJoystickButton7 = 6;
const int kAttackJoystickButton8 = 7;
const int kAttackJoystickButton9 = 8;
const int kAttackJoystickButton10 = 9;
const int kAttackJoystickButton11 = 10;
//const int kAttackJoystickButton12 = 11;

constexpr float kDeadbandLimit = 0.01;

enum XBoxJoystickButtonPort
{
	// New mappings starting in 2015
	kXBoxButtonA = 1,
	kXBoxButtonB = 2,
	kXBoxButtonX = 3,
	kXBoxButtonY = 4,
	kXBoxButtonLeft = 5,
	kXBoxButtonRight = 6,
	kXBoxButtonBack = 7,
	kXBoxButtonStart = 8,
	kXBoxButtonLeftJoystick = 9,
	kXBoxButtonRightJoystick = 10,
};

const int kDriverStickPort = 0;
const int kManipulatorStickPort = 1;
