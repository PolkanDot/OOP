#include "Car.h"
#include <map>

std::string unableSpeedNotNegative = "Unable to set speed: speed cannot be negative value.";
std::string unableSpeedTurnedOff = "Unable to set speed: engine is turned off.";
std::string unableSpeedReverseSpeedLimit = "Unable to set speed: exceed reverse speed limit";
std::string unableSpeedAccelerateAtNeutral = "Unable to set speed: impossible to accelerate at neutral gear";
std::string unableSpeedNotSuiteGear = "Unable to set speed: speed does not suite currently selected gear.";
std::string unableSpeedInvalideGearValue = "Unable to set speed: invalid gear value";
std::string unableGearEngineTurnedOff = "Unable to set gear: Engine is turned off.";
std::string unableGearInvalidGearArgument = "Unable to set gear: invalid gear argument.";
std::string unableGearunSuitableCurrentSpeed = "Unable to set gear: unsuitable current speed";
std::string unableReverseGear = "Unable to set reverse gear while moving not from reverse gear.";
std::string internalError = "Internal error: invalid gear argument";
std::string unableTurnOff = "Unable to turn off engine: car must be immoble and gear is neutral.";

const std::map<int, std::pair<int, int>> gearSpeedRange = {
	{ -1, { -20, 0 } },
	{ 0, {} },
	{ 1, { 0, 30 } },
	{ 2, { 20, 50 } },
	{ 3, { 30, 60 } },
	{ 4, { 40, 90 } },
	{ 5, { 50, 150 } }
};

int maxGear = (--gearSpeedRange.end()) -> first;


bool Car::IsTurnedOn() const
{
	return isEngineOn;
}

bool Car::TurnOnEngine()
{
	isEngineOn = true;

	return true;
}	

bool Car::TurnOffEngine()
{
	if (gear != 0 || speed != 0)
	{
		errorMessage = unableTurnOff;
		return false;
	}

	isEngineOn = false;

	return true;
}

int Car::GetDirection() const
{
	if (speed >= 0)
	{
		if (speed == 0)
		{
			return 0;
		}

		return 1;
	}

	return -1;
}

int Car::GetSpeed() const
{
	return abs(speed);
}

int Car::GetGear() const
{
	return gear;
}

std::string Car::GetErrorMessage() const
{
	return errorMessage;
}

bool Car::SetSpeed(int speedParam)
{
	if (speedParam < 0)
	{
		errorMessage = unableSpeedNotNegative;
		return false;
	}

	if (!IsTurnedOn())
	{
		errorMessage = unableSpeedTurnedOff;
		return false;
	}

	if (gear == -1)
	{
		if (-speedParam < gearSpeedRange.find(gear)->second.first)
		{
			errorMessage = unableSpeedReverseSpeedLimit;
			return false;
		}
		speed = -speedParam;
		return true;
	}
	if (gear == 0)
	{
		if (speedParam > abs(speed))
		{
			errorMessage = unableSpeedAccelerateAtNeutral;
			return false;
		}
		if (speed < 0)
		{
			speed = -speedParam;
		}
		else
		{
			speed = speedParam;
		}
		return true;
	}
	if ((gear > 0) && (gear <= maxGear))
	{
		if (speedParam < gearSpeedRange.find(gear)->second.first || gearSpeedRange.find(gear)->second.second < speedParam)
		{
			errorMessage = unableSpeedNotSuiteGear;
			return false;
		}
		speed = speedParam;
		return true;
	}

	if ((gear < -1) || (gear > maxGear))
	{
		errorMessage = unableSpeedInvalideGearValue;
		return false;
	}
	
}

bool Car::SetGear(int gearParam)
{
	if (!IsTurnedOn() && (gearParam != 0))
	{
		errorMessage = unableGearEngineTurnedOff;
		return false;
	}

	if (gearSpeedRange.find(gearParam) == gearSpeedRange.end())
	{
		errorMessage = unableGearInvalidGearArgument;
		return false;
	}

	if (gearParam == -1)
	{
		if (speed != 0)
		{
			if (gearParam != gear)
			{
				errorMessage = unableReverseGear;
				return false;
			}

			return true;
		}
	}

	if ((gearParam > 0) && (gearParam <= maxGear))
	{
		if (speed < gearSpeedRange.find(gearParam)->second.first || gearSpeedRange.find(gearParam)->second.second < speed)
		{
			errorMessage = unableGearunSuitableCurrentSpeed;
			return false;
		}
	}

	if ((gearParam < -1) || (gearParam > maxGear))
	{
		errorMessage = internalError;
		return false;
	}
	

	gear = gearParam;
	return true;
}
