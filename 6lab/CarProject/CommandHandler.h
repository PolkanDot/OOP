#pragma once
#include "Car.h"
#include <fstream>
#include <optional>
#include <map>

class CommandHandler
{
public:
	CommandHandler(Car& car, std::istream& in, std::ostream& out)
		: mainCar(car)
		, input(in)
		, output(out)
	{
	}
	enum class Status
	{
		OK,
		ParsingError,
		ExecutionError,
		Exit
	};

	struct Result
	{
		Status status;
		std::optional<std::string> reportMessage;
	};

	Result Interpret();


private:
	enum class CommandType
	{
		Info,
		EngineOn,
		EngineOff,
		SetGear,
		SetSpeed,
		Exit
	};

	const std::map<std::string, CommandType> mapStringToCommandType = {
		{ "Info", CommandType::Info },
		{ "EngineOn", CommandType::EngineOn },
		{ "EngineOff", CommandType::EngineOff },
		{ "SetGear", CommandType::SetGear },
		{ "SetSpeed", CommandType::SetSpeed },
		{ "Exit", CommandType::Exit }
	};

	struct Command
	{
		CommandType type;
		std::optional<int> arg;
	};

	struct ParseResult
	{
		Status status;
		std::optional<Command> command;
		std::optional<std::string> reportMessage;
	};

	ParseResult Parse(const std::string& rawExpression);

	Result Execute(std::optional<Command> command);

	void PrintCarInfo();
	std::istream& input;
	std::ostream& output;
	Car& mainCar;
};
