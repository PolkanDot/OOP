﻿#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../CarProject/Car.h"
#include "../CarProject/CommandHandler.h"

TEST_CASE("Checking Car's initial state and engine behavior")
{
	Car car;

	SECTION("Check initial state of car: engine is off, speed 0, gear neutral, direction immobile")
	{
		REQUIRE(!car.IsTurnedOn());
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 0);
		REQUIRE(car.GetDirection() == 0);
	}

	SECTION("Turning off engine which already stopped")
	{
		REQUIRE(!car.IsTurnedOn());
		REQUIRE(car.TurnOffEngine());
	}

	SECTION("Turning on engine which already running")
	{
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.IsTurnedOn());
		REQUIRE(car.TurnOnEngine());
	}
}

TEST_CASE("Checking Car's gear manipulations")
{
	Car car;

	SECTION("Trying set gear and speed while engine is off")
	{
		REQUIRE(!car.IsTurnedOn());
		REQUIRE(!car.SetGear(1));
		REQUIRE(car.GetGear() == 0);
		REQUIRE(!car.SetSpeed(10));
		REQUIRE(car.GetSpeed() == 0);
		REQUIRE(car.GetDirection() == 0);
	}

	SECTION("Trying set gear with out of range values")
	{
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.IsTurnedOn());
		REQUIRE(!car.SetGear(-2));
		REQUIRE(car.GetGear() == 0);
		REQUIRE(!car.SetGear(6));
		REQUIRE(car.GetGear() == 0);
	}

	SECTION("Trying set gear while moving at wrong speed range")
	{
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(1));
		REQUIRE(car.SetSpeed(10));

		REQUIRE(!car.SetGear(-1));
		REQUIRE(car.GetGear() == 1);
		REQUIRE(!car.SetGear(2));
		REQUIRE(car.GetGear() == 1);
		REQUIRE(!car.SetGear(3));
		REQUIRE(car.GetGear() == 1);
		REQUIRE(!car.SetGear(4));
		REQUIRE(car.GetGear() == 1);
		REQUIRE(!car.SetGear(5));
		REQUIRE(car.GetGear() == 1);

		REQUIRE(car.SetSpeed(30));
		REQUIRE(car.SetGear(2));

		REQUIRE(!car.SetGear(-1));
		REQUIRE(car.GetGear() == 2);
		REQUIRE(!car.SetGear(5));
		REQUIRE(car.GetGear() == 2);

		REQUIRE(car.SetGear(0));
		REQUIRE(car.SetSpeed(0));
		REQUIRE(car.SetGear(-1));
		REQUIRE(car.SetSpeed(15));

		REQUIRE(!car.SetGear(1));
		REQUIRE(car.GetGear() == -1);

		REQUIRE(car.SetGear(0));
		REQUIRE(!car.SetGear(-1));
		REQUIRE(car.GetGear() == 0);
	}
}

TEST_CASE("Checking Car's speed manipulations")
{
	Car car;

	SECTION("Trying set speed which out of range of current gear speed range")
	{
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(1));

		// gear 1
		REQUIRE(!car.SetSpeed(31));
		REQUIRE(!car.SetSpeed(150));
		REQUIRE(!car.SetSpeed(151));
		REQUIRE(!car.SetSpeed(-45));

		REQUIRE(car.SetSpeed(20));
		REQUIRE(car.SetGear(2));

		// gear 2
		REQUIRE(!car.SetSpeed(19));
		REQUIRE(!car.SetSpeed(51));

		REQUIRE(car.SetSpeed(40));
		REQUIRE(car.SetGear(3));

		// gear 3
		REQUIRE(!car.SetSpeed(29));
		REQUIRE(!car.SetSpeed(61));

		REQUIRE(car.SetSpeed(55));
		REQUIRE(car.SetGear(4));

		// gear 4
		REQUIRE(!car.SetSpeed(39));
		REQUIRE(!car.SetSpeed(91));

		REQUIRE(car.SetSpeed(85));
		REQUIRE(car.SetGear(5));

		// gear 5
		REQUIRE(!car.SetSpeed(49));
		REQUIRE(!car.SetSpeed(151));
	}

	SECTION("Trying accelearte at neutral gear")
	{
		REQUIRE(car.TurnOnEngine());
		REQUIRE(car.SetGear(1));
		REQUIRE(car.SetSpeed(30));

		REQUIRE(car.SetGear(0));

		//brake down to 15
		REQUIRE(car.SetSpeed(15));

		//trying accelerate
		REQUIRE(!car.SetSpeed(25));

		// same thing but moving backwards
		REQUIRE(car.SetSpeed(0));
		REQUIRE(car.SetGear(-1));

		REQUIRE(car.SetSpeed(20));

		REQUIRE(car.SetGear(0));

		REQUIRE(car.SetSpeed(15));

		REQUIRE(!car.SetSpeed(18));
	}
}
// CommandHandlerTests

TEST_CASE("CommandInterpreter parses commands from istream and executes it by calling car's methods")
{
	std::ostringstream oss;
	Car car;

	SECTION("Try parse unknown command")
	{
		std::istringstream iss("SomeCommand 123");
		CommandHandler interpreter(car, iss, oss);

		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::ParsingError);
	}

	SECTION("Try parse SetGear command with bad argument")
	{
		std::istringstream iss("SetGear gi390g");
		CommandHandler interpreter(car, iss, oss);

		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::ParsingError);
	}

	SECTION("Parse sequence of valid commands")
	{
		std::istringstream iss("EngineOn\nSetGear -1\nSetSpeed 20\nSetGear 0\nSetSpeed 10\nSetSpeed 15\nSetGear 1\nEngineOff\nSetSpeed 0\nEngineOff\n");
		CommandHandler interpreter(car, iss, oss);

		//turn on engine
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);
		REQUIRE(car.IsTurnedOn());
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetDirection() == 0);

		//set rear gear
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);
		REQUIRE(car.IsTurnedOn());
		REQUIRE(car.GetGear() == -1);
		REQUIRE(car.GetDirection() == 0);

		//accelerate to 20 moving backwards
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);
		REQUIRE(car.IsTurnedOn());
		REQUIRE(car.GetGear() == -1);
		REQUIRE(car.GetSpeed() == 20);
		REQUIRE(car.GetDirection() == -1);

		//set neutral gear
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 20);
		REQUIRE(car.GetDirection() == -1);

		//brake to 10
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 10);
		REQUIRE(car.GetDirection() == -1);

		//trying to accelerate from 10 to 15 on neutral gear
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::ExecutionError);
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 10);
		REQUIRE(car.GetDirection() == -1);

		//trying to set gear 1 while moving backwards on neutral gear
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::ExecutionError);
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 10);
		REQUIRE(car.GetDirection() == -1);

		//trying turn off engine while moving backwards on neutral gear
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::ExecutionError);
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 10);
		REQUIRE(car.GetDirection() == -1);

		//brake to 0
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);
		REQUIRE(car.IsTurnedOn());
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 0);
		REQUIRE(car.GetDirection() == 0);

		//turn off engine
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);
		REQUIRE(!car.IsTurnedOn());
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 0);
		REQUIRE(car.GetDirection() == 0);
	}
}

TEST_CASE("Empty string ignoring and 'Exit' command behavior")
{
	std::ostringstream oss;
	Car car;

	SECTION("Empty string is valid meaning that there is nothing to execute")
	{
		std::istringstream iss("\n");
		CommandHandler interpreter(car, iss, oss);

		REQUIRE(!car.IsTurnedOn());
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 0);
		REQUIRE(car.GetDirection() == 0);

		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);

		//car state wasn't changed
		REQUIRE(!car.IsTurnedOn());
		REQUIRE(car.GetGear() == 0);
		REQUIRE(car.GetSpeed() == 0);
		REQUIRE(car.GetDirection() == 0);
	}

	SECTION("Exit command invokes 'Exit' status")
	{
		std::istringstream iss("Exit\n");
		CommandHandler interpreter(car, iss, oss);

		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::Exit);
	}
}

TEST_CASE("Testing 'Info' command correct behavior")
{
	std::ostringstream oss;
	Car car;

	SECTION("Info command prints info into ostream")
	{
		std::istringstream iss("Info\n");
		CommandHandler interpreter(car, iss, oss);

		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK);

		REQUIRE(oss.str() == "Engine: Off\nDirection: Immobile\nSpeed: 0\nGear: N\n");
	}

	SECTION("Print info after changing car's state")
	{
		std::istringstream iss("EngineOn\nSetGear 1\nSetSpeed 10\nInfo\n");
		CommandHandler interpreter(car, iss, oss);

		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK); // turn engine on
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK); // set gear 1
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK); // set speed 10 moving forward
		REQUIRE(interpreter.Interpret().status == CommandHandler::Status::OK); // print info

		REQUIRE(oss.str() == "Engine: On\nDirection: Forward\nSpeed: 10\nGear: 1\n");
	}
}
