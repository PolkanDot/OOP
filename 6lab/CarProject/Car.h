#pragma once
#include <string>

class Car
{
public:
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gearParam);
	bool SetSpeed(int speedParam);
	bool IsTurnedOn() const;
	int GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	std::string GetErrorMessage() const;

private:
	int gear = 0;
	int speed = 0;
	bool isEngineOn = false;
	std::string errorMessage;
};
