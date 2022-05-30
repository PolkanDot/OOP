#include "CommandHandler.h"

std::string unknownCommand = "Parsing error: unknown command";
std::string invalidCommandArgument = "Parsing error: invalid command argument";
std::string invalidCommandType = "Internal error: Executing command with invalid command type.";
std::string Engine = "Engine: ";
std::string Direction = "Direction: ";
std::string Speed = "Speed: ";
std::string Gear = "Gear: ";
std::string On = "On";
std::string Off = "Off";
std::string Neitral = "N";
std::string ReversGear = "R";
std::string Forward = "Forward";
std::string ReverseDirection = "Backwards";
std::string Immobile = "Immobile";

// √лавный метод выполнени€ команды
CommandHandler::Result CommandHandler::Interpret()
{
	std::string inputString;
	std::getline(input, inputString);

	ParseResult parseResult;
	if ((parseResult = Parse(inputString)).status != Status::OK)
	{
		return { parseResult.status, parseResult.reportMessage };
	}

	Result execResult;
	if ((execResult = Execute(parseResult.command)).status != Status::OK)
	{
		return { execResult.status, execResult.reportMessage };
	}

	return (input.eof() || !input) ?
		Result{ Status::Exit } : Result{ Status::OK };
}

// ѕреобразование строки в существующий тип команды
// и при надобности вычленение аргумента команды
CommandHandler::ParseResult CommandHandler::Parse(const std::string& raw)
{
	if (raw.empty())
	{
		return { Status::OK };
	}

	size_t spacePos = raw.find(' ');
	std::string commandString = raw.substr(0, spacePos);

	// ≈сли не нашли переданную команду в списке команд,
	// то возвращаем ошибку парсинга
	if (!mapStringToCommandType.contains(commandString))
	{
		return {
			Status::ParsingError,
			std::nullopt,
			unknownCommand
		};
	}

	CommandType type = mapStringToCommandType.at(commandString);
	std::optional<int> arg;

	if (type == CommandType::SetGear || type == CommandType::SetSpeed)
	{
		try
		{
			arg = std::stoi(raw.substr(spacePos + 1));
		}
		catch (...)
		{
			return {
				Status::ParsingError,
				std::nullopt,
				invalidCommandArgument
			};
		}
	}

	return {
		Status::OK,
		Command{
			type,
			arg
		}
	};
}

// ћетод, отвечающий за выполнение в объекте Car
// предварительно обработанных команд пользовател€ 
CommandHandler::Result CommandHandler::Execute(std::optional<Command> command)
{
	if (!command.has_value())
	{
		return { Status::OK };
	}

	bool noError;
	switch (command->type)
	{
	case CommandType::Info:
		PrintCarInfo();
		return { Status::OK };

	case CommandType::Exit:
		return { Status::Exit };

	case CommandType::EngineOn:
		noError = mainCar.TurnOnEngine();
		break;

	case CommandType::EngineOff:
		noError = mainCar.TurnOffEngine();
		break;

	case CommandType::SetGear:
		noError = mainCar.SetGear(*(command->arg));
		break;

	case CommandType::SetSpeed:
		noError = mainCar.SetSpeed(*(command->arg));
		break;

	default:
		return {
			Status::ExecutionError,
			invalidCommandType
		};
	}
		
	if (noError)
	{
		return { Status::OK };
	}

	return {
		Status::ExecutionError,
		mainCar.GetErrorMessage()
	};
}

void CommandHandler::PrintCarInfo()
{
	int direction = mainCar.GetDirection();
	int gear = mainCar.GetGear();

	output
		<< Engine << (mainCar.IsTurnedOn() ? On : Off) << std::endl
		<< Direction << (direction >= 0 ? direction == 0 ? Immobile : Forward : ReverseDirection) << std::endl
		<< Speed << mainCar.GetSpeed() << std::endl
		<< Gear << (gear < 0 ? ReversGear : gear == 0 ? Neitral : std::to_string(gear)) << std::endl;
}