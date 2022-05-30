#include <iostream>

#include "Car.h"
#include "CommandHandler.h"

std::string parsingError = "Parsing error was occured.";
std::string executionError = "Execution error was occured.";
std::string exiting = "Exiting...";


// В Car.h убрать конструкцию case и сделать так, чтобы работало при изменении только списка скоротей
//(сделал, но пока не проходят тесты)

int main()
{
	Car car;
	CommandHandler interpreter(car, std::cin, std::cout);
	CommandHandler::Result result;


	// Пока обьект interpreter не вернет статус Exit читаем и выполняем команды
	while ((result = interpreter.Interpret()).status != CommandHandler::Status::Exit)
	{
		if (result.status != CommandHandler::Status::OK)
		{
			if (result.reportMessage.has_value())
			{
				std::cout << *(result.reportMessage) << std::endl;
			}
			else
			{
				switch (result.status)
				{
				case CommandHandler::Status::ParsingError:
					std::cout << parsingError << std::endl;
					break;
				case CommandHandler::Status::ExecutionError:
					std::cout << executionError << std::endl;
					break;
				default:
					break;
				}
			}
		}
	}

	std::cout << exiting << std::endl;

	return 0;
}