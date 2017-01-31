#pragma once

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/MecanumDrive.h"
#include "Subsystems/Flashlight.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command
{
	public:
		CommandBase(const std::string& name);
		CommandBase() = default;

		// Create a single static instance of all of your subsystems
		static std::unique_ptr<MecanumDrive> drive;
		static std::unique_ptr<Flashlight> light;
		static std::unique_ptr<OI> oi;
};

