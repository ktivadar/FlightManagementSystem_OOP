#pragma once
#include "aircraft.h"
class passengerAircraft : public aircraft {
private:
	int capacity; //utasszalito gep utas kapacitasa
	int current_passenger; //jelenlegi utas szam
public:
	passengerAircraft(const std::string, const int, const float, const float, const int, const int);
	int getCapacity();
	void setCapacity(const int);
	int getCurrentPassenger();
	void setCurrentPassanger(const int);
	void information();
};